//
// Created by chen_ on 2019/1/31.
//

#include <ctime>
#include <climits>
#include <cstdlib>
#include "../../include/macros.h"
#include "../../include/GameCommon.h"
#include "../../include/Utils/mapGenerator.h"
#include "../../include/Utils/data_stucture/heap.h"

static uint32_t in_room(dungeon_t *d, int16_t y, int16_t x)
{
    int i;

    for (i = 0; i < d->rooms.size(); i++) {
        if ((x >= d->rooms.at(i).position[curr_x]) &&
            (x < (d->rooms.at(i).position[curr_x] + d->rooms.at(i).size[curr_x])) &&
            (y >= d->rooms.at(i).position[curr_y]) &&
            (y < (d->rooms.at(i).position[curr_y] + d->rooms.at(i).size[curr_y]))) {
            return 1;
        }
    }

    return 0;
}

static uint32_t adjacent_to_room(dungeon_t *d, int16_t y, int16_t x)
{
    return (mapxy(x - 1, y) == ter_floor_room ||
            mapxy(x + 1, y) == ter_floor_room ||
            mapxy(x, y - 1) == ter_floor_room ||
            mapxy(x, y + 1) == ter_floor_room);
}

static uint32_t is_open_space(dungeon_t *d, int16_t y, int16_t x)
{
    return !hardnessxy(x, y);
}

static int32_t corridor_path_cmp(const void *key, const void *with) {
    return ((corridor_path_t *) key)->cost - ((corridor_path_t *) with)->cost;
}

static void dijkstra_corridor(dungeon_t *d, location_t from, location_t to)
{
    static corridor_path_t path[DUNGEON_Y][DUNGEON_X], *p;
    static uint32_t initialized = 0;
    heap_t h;
    uint32_t x, y;

    if (!initialized) {
        for (y = 0; y < DUNGEON_Y; y++) {
            for (x = 0; x < DUNGEON_X; x++) {
                path[y][x].pos[curr_y] = y;
                path[y][x].pos[curr_x] = x;
            }
        }
        initialized = 1;
    }

    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            path[y][x].cost = INT_MAX;
        }
    }

    path[from[curr_y]][from[curr_x]].cost = 0;

    heap_init(&h, corridor_path_cmp, NULL);

    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            if (mapxy(x, y) != ter_wall_immutable) {
                path[y][x].hn = heap_insert(&h, &path[y][x]);
            } else {
                path[y][x].hn = NULL;
            }
        }
    }

    while ((p = (corridor_path * )heap_remove_min(&h))) {
        p->hn = NULL;

        if ((p->pos[curr_y] == to[curr_y]) && p->pos[curr_x] == to[curr_x]) {
            for (x = to[curr_x], y = to[curr_y];
                 (x != from[curr_x]) || (y != from[curr_y]);
                 p = &path[y][x], x = p->from[curr_x], y = p->from[curr_y]) {
                if (mapxy(x, y) != ter_floor_room) {
                    mapxy(x, y) = ter_floor_hall;
                    hardnessxy(x, y) = 0;
                }
            }
            heap_delete(&h);
            return;
        }

        if ((path[p->pos[curr_y] - 1][p->pos[curr_x]    ].hn) &&
            (path[p->pos[curr_y] - 1][p->pos[curr_x]    ].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[curr_y] - 1][p->pos[curr_x]    ].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[curr_y] - 1][p->pos[curr_x]    ].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y] - 1][p->pos[curr_x]    ].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y] - 1]
            [p->pos[curr_x]    ].hn);
        }
        if ((path[p->pos[curr_y]    ][p->pos[curr_x] - 1].hn) &&
            (path[p->pos[curr_y]    ][p->pos[curr_x] - 1].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[curr_y]    ][p->pos[curr_x] - 1].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[curr_y]    ][p->pos[curr_x] - 1].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y]    ][p->pos[curr_x] - 1].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y]    ]
            [p->pos[curr_x] - 1].hn);
        }
        if ((path[p->pos[curr_y]    ][p->pos[curr_x] + 1].hn) &&
            (path[p->pos[curr_y]    ][p->pos[curr_x] + 1].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[curr_y]    ][p->pos[curr_x] + 1].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[curr_y]    ][p->pos[curr_x] + 1].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y]    ][p->pos[curr_x] + 1].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y]    ]
            [p->pos[curr_x] + 1].hn);
        }
        if ((path[p->pos[curr_y] + 1][p->pos[curr_x]    ].hn) &&
            (path[p->pos[curr_y] + 1][p->pos[curr_x]    ].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[curr_y] + 1][p->pos[curr_x]    ].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[curr_y] + 1][p->pos[curr_x]    ].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y] + 1][p->pos[curr_x]    ].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y] + 1]
            [p->pos[curr_x]    ].hn);
        }
    }
}

/* This is a cut-and-paste of the above.  The code is modified to  *
 * calculate paths based on inverse hardnesses so that we get a    *
 * high probability of creating at least one cycle in the dungeon. */
static void dijkstra_corridor_inv(dungeon_t *d, location_t from, location_t to)
{
    static corridor_path_t path[DUNGEON_Y][DUNGEON_X], *p;
    static uint32_t initialized = 0;
    heap_t h;
    uint32_t x, y;

    if (!initialized) {
        for (y = 0; y < DUNGEON_Y; y++) {
            for (x = 0; x < DUNGEON_X; x++) {
                path[y][x].pos[curr_y] = y;
                path[y][x].pos[curr_x] = x;
            }
        }
        initialized = 1;
    }

    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            path[y][x].cost = INT_MAX;
        }
    }

    path[from[curr_y]][from[curr_x]].cost = 0;

    heap_init(&h, corridor_path_cmp, NULL);

    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            if (mapxy(x, y) != ter_wall_immutable) {
                path[y][x].hn = heap_insert(&h, &path[y][x]);
            } else {
                path[y][x].hn = NULL;
            }
        }
    }

    while ((p = (corridor_path_t *)heap_remove_min(&h))) {
        p->hn = NULL;

        if ((p->pos[curr_y] == to[curr_y]) && p->pos[curr_x] == to[curr_x]) {
            for (x = to[curr_x], y = to[curr_y];
                 (x != from[curr_x]) || (y != from[curr_y]);
                 p = &path[y][x], x = p->from[curr_x], y = p->from[curr_y]) {
                if (mapxy(x, y) != ter_floor_room) {
                    mapxy(x, y) = ter_floor_hall;
                    hardnessxy(x, y) = 0;
                }
            }
            heap_delete(&h);
            return;
        }

#define hardnesspair_inv(p) (is_open_space(d, p[curr_y], p[curr_x]) ? 127 :     \
                             (adjacent_to_room(d, p[curr_y], p[curr_x]) ? 191 : \
                              (255 - hardnesspair(p))))

        if ((path[p->pos[curr_y] - 1][p->pos[curr_x]    ].hn) &&
            (path[p->pos[curr_y] - 1][p->pos[curr_x]    ].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[curr_y] - 1][p->pos[curr_x]    ].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[curr_y] - 1][p->pos[curr_x]    ].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y] - 1][p->pos[curr_x]    ].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y] - 1]
            [p->pos[curr_x]    ].hn);
        }
        if ((path[p->pos[curr_y]    ][p->pos[curr_x] - 1].hn) &&
            (path[p->pos[curr_y]    ][p->pos[curr_x] - 1].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[curr_y]    ][p->pos[curr_x] - 1].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[curr_y]    ][p->pos[curr_x] - 1].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y]    ][p->pos[curr_x] - 1].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y]    ]
            [p->pos[curr_x] - 1].hn);
        }
        if ((path[p->pos[curr_y]    ][p->pos[curr_x] + 1].hn) &&
            (path[p->pos[curr_y]    ][p->pos[curr_x] + 1].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[curr_y]    ][p->pos[curr_x] + 1].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[curr_y]    ][p->pos[curr_x] + 1].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y]    ][p->pos[curr_x] + 1].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y]    ]
            [p->pos[curr_x] + 1].hn);
        }
        if ((path[p->pos[curr_y] + 1][p->pos[curr_x]    ].hn) &&
            (path[p->pos[curr_y] + 1][p->pos[curr_x]    ].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[curr_y] + 1][p->pos[curr_x]    ].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[curr_y] + 1][p->pos[curr_x]    ].from[curr_y] = p->pos[curr_y];
            path[p->pos[curr_y] + 1][p->pos[curr_x]    ].from[curr_x] = p->pos[curr_x];
            heap_decrease_key_no_replace(&h, path[p->pos[curr_y] + 1]
            [p->pos[curr_x]    ].hn);
        }
    }
}

/* Chooses a random point inside each room and connects them with a *
 * corridor.  Random internal points prevent corridors from exiting *
 * rooms in predictable locations.                                  */
static int connect_two_rooms(dungeon_t *d, room_t *r1, room_t *r2)
{
    location_t e1, e2;

    e1[curr_y] = rand_range(r1->position[curr_y],
                           r1->position[curr_y] + r1->size[curr_y] - 1);
    e1[curr_x] = rand_range(r1->position[curr_x],
                           r1->position[curr_x] + r1->size[curr_x] - 1);
    e2[curr_y] = rand_range(r2->position[curr_y],
                           r2->position[curr_y] + r2->size[curr_y] - 1);
    e2[curr_x] = rand_range(r2->position[curr_x],
                           r2->position[curr_x] + r2->size[curr_x] - 1);

    /*  return connect_two_points_recursive(d, e1, e2);*/
    dijkstra_corridor(d, e1, e2);

    return 0;
}

static int create_cycle(dungeon_t *d)
{
    /* Find the (approximately) farthest two rooms, then connect *
     * them by the shortest path using inverted hardnesses.      */

    int32_t max, tmp, i, j, p, q;
    location_t e1, e2;
    printf("%d\n",d->rooms.size());
    for (i = max = 0; i < d->rooms.size() - 1; i++) {
        for (j = i + 1; j < d->rooms.size(); j++) {
            tmp = (((d->rooms.at(i).position[curr_x] - d->rooms.at(j).position[curr_x])  *
                    (d->rooms.at(i).position[curr_x] - d->rooms.at(j).position[curr_x])) +
                   ((d->rooms.at(i).position[curr_y] - d->rooms.at(j).position[curr_y])  *
                    (d->rooms.at(i).position[curr_y] - d->rooms.at(j).position[curr_y])));
            if (tmp > max) {
                max = tmp;
                p = i;
                q = j;
            }
        }
    }

    /* Can't simply call connect_two_rooms() because it doesn't *
     * use inverse hardnesses, so duplicate it here.            */
    e1[curr_y] = rand_range(d->rooms.at(p).position[curr_y],
                           (d->rooms.at(p).position[curr_y] +
                            d->rooms.at(p).size[curr_y] - 1));
    e1[curr_x] = rand_range(d->rooms.at(p).position[curr_x],
                           (d->rooms.at(p).position[curr_x] +
                            d->rooms.at(p).size[curr_x] - 1));
    e2[curr_y] = rand_range(d->rooms.at(p).position[curr_y],
                           (d->rooms.at(p).position[curr_y] +
                            d->rooms.at(p).size[curr_y] - 1));
    e2[curr_x] = rand_range(d->rooms.at(p).position[curr_x],
                           (d->rooms.at(p).position[curr_x] +
                            d->rooms.at(p).size[curr_x] - 1));

    dijkstra_corridor_inv(d, e1, e2);

    return 0;
}

int connect_rooms(dungeon_t *d)
{
    uint32_t i;

    for (i = 1; i < d->rooms.size(); i++) {
        connect_two_rooms(d, &d->rooms.at(i -1 ), &d->rooms.at(i));
    }

    create_cycle(d);

    return 0;
}

int gaussian[5][5] = {
        {  1,  4,  7,  4,  1 },
        {  4, 16, 26, 16,  4 },
        {  7, 26, 41, 26,  7 },
        {  4, 16, 26, 16,  4 },
        {  1,  4,  7,  4,  1 }
};

typedef struct queue_node {
    int x, y;
    struct queue_node *next;
} queue_node_t;

static int smooth_hardness(dungeon_t *d)
{
    int32_t i, x, y;
    int32_t s, t, p, q;
    queue_node_t *head, *tail, *tmp;
    FILE *out;
    uint8_t hardness[DUNGEON_Y][DUNGEON_X];

    memset(&hardness, 0, sizeof (hardness));

    /* Seed with some values */
    for (i = 1; i < 255; i += 20) {
        do {
            x = rand() % DUNGEON_X;
            y = rand() % DUNGEON_Y;
        } while (hardness[y][x]);
        hardness[y][x] = i;
        if (i == 1) {
            head = tail =(queue_node_t *) malloc(sizeof (*tail));
        } else {
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
        }
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
    }

    /* Diffuse the vaules to fill the space */
    while (head) {
        x = head->x;
        y = head->y;
        i = hardness[y][x];

        if (x - 1 >= 0 && y - 1 >= 0 && !hardness[y - 1][x - 1]) {
            hardness[y - 1][x - 1] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x - 1;
            tail->y = y - 1;
        }
        if (x - 1 >= 0 && !hardness[y][x - 1]) {
            hardness[y][x - 1] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x - 1;
            tail->y = y;
        }
        if (x - 1 >= 0 && y + 1 < DUNGEON_Y && !hardness[y + 1][x - 1]) {
            hardness[y + 1][x - 1] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x - 1;
            tail->y = y + 1;
        }
        if (y - 1 >= 0 && !hardness[y - 1][x]) {
            hardness[y - 1][x] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x;
            tail->y = y - 1;
        }
        if (y + 1 < DUNGEON_Y && !hardness[y + 1][x]) {
            hardness[y + 1][x] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x;
            tail->y = y + 1;
        }
        if (x + 1 < DUNGEON_X && y - 1 >= 0 && !hardness[y - 1][x + 1]) {
            hardness[y - 1][x + 1] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x + 1;
            tail->y = y - 1;
        }
        if (x + 1 < DUNGEON_X && !hardness[y][x + 1]) {
            hardness[y][x + 1] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x + 1;
            tail->y = y;
        }
        if (x + 1 < DUNGEON_X && y + 1 < DUNGEON_Y && !hardness[y + 1][x + 1]) {
            hardness[y + 1][x + 1] = i;
            tail->next = (queue_node_t *) malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x + 1;
            tail->y = y + 1;
        }

        tmp = head;
        head = head->next;
        free(tmp);
    }

    /* And smooth it a bit with a gaussian convolution */
    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            for (s = t = p = 0; p < 5; p++) {
                for (q = 0; q < 5; q++) {
                    if (y + (p - 2) >= 0 && y + (p - 2) < DUNGEON_Y &&
                        x + (q - 2) >= 0 && x + (q - 2) < DUNGEON_X) {
                        s += gaussian[p][q];
                        t += hardness[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
                    }
                }
            }
            d->map[y][x].hardness = t / s;
        }
    }
    /* Let's do it again, until it's smooth like Kenny G. */
    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            for (s = t = p = 0; p < 5; p++) {
                for (q = 0; q < 5; q++) {
                    if (y + (p - 2) >= 0 && y + (p - 2) < DUNGEON_Y &&
                        x + (q - 2) >= 0 && x + (q - 2) < DUNGEON_X) {
                        s += gaussian[p][q];
                        t += hardness[y + (p - 2)][x + (q - 2)] * gaussian[p][q];
                    }
                }
            }
            d->map[y][x].hardness = t / s;
        }
    }
    return 0;
}

static int empty_dungeon(dungeon_t *d)
{
    uint8_t x, y;

    smooth_hardness(d);
    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            mapxy(x, y) = ter_wall;
            if (y == 0 || y == DUNGEON_Y - 1 ||
                x == 0 || x == DUNGEON_X - 1) {
                mapxy(x, y) = ter_wall_immutable;
                hardnessxy(x, y) = 255;
            }
        }
    }

    return 0;
}

static int place_rooms(dungeon_t *d)
{
    location_t p;
    uint32_t i;
    int success;
    room_t *r;

    for (success = 0; !success; ) {
        success = 1;
        for (i = 0; success && i < d->rooms.size(); i++) {
            r = &d->rooms.at(i);
            r->position[curr_x] = 1 + rand() % (DUNGEON_X - 2 - r->size[curr_x]);
            r->position[curr_y] = 1 + rand() % (DUNGEON_Y - 2 - r->size[curr_y]);
            for (p[curr_y] = r->position[curr_y] - 1;
                 success && p[curr_y] < r->position[curr_y] + r->size[curr_y] + 1;
                 p[curr_y]++) {
                for (p[curr_x] = r->position[curr_x] - 1;
                     success && p[curr_x] < r->position[curr_x] + r->size[curr_x] + 1;
                     p[curr_x]++) {
                    if (mappair(p) >= ter_floor) {
                        success = 0;
                        empty_dungeon(d);
                    } else if ((p[curr_y] != r->position[curr_y] - 1)              &&
                               (p[curr_y] != r->position[curr_y] + r->size[curr_y]) &&
                               (p[curr_x] != r->position[curr_x] - 1)              &&
                               (p[curr_x] != r->position[curr_x] + r->size[curr_x])) {
                        mappair(p) = ter_floor_room;
                        hardnesspair(p) = 0;
                    }
                }
            }
        }
    }

    return 0;
}

static void place_stairs(dungeon_t *d)
{
    location_t p;
    do {
        while ((p[curr_y] = rand_range(1, DUNGEON_Y - 2)) &&
               (p[curr_x] = rand_range(1, DUNGEON_X - 2)) &&
               ((mappair(p) < ter_floor)                 ||
                (mappair(p) > ter_stairs)))
            ;
        d->downStairs.push_back(p);
        mappair(p) = ter_stairs_down;
    } while (rand_under(1, 3));
    do {
        while ((p[curr_y] = rand_range(1, DUNGEON_Y - 2)) &&
               (p[curr_x] = rand_range(1, DUNGEON_X - 2)) &&
               ((mappair(p) < ter_floor)                 ||
                (mappair(p) > ter_stairs)))

            ;
        d->upStairs.push_back(p);
        mappair(p) = ter_stairs_up;
    } while (rand_under(2, 4));

    //tmp set stair number to 1
}

static int make_rooms(dungeon_t *d)
{
    for (int i = 0; i < rand()%(MAX_ROOMS - MIN_ROOMS) + MIN_ROOMS; i++) {
        room_t tmpRoom;
        tmpRoom.size[curr_x] = ROOM_MIN_X;
        tmpRoom.size[curr_y] = ROOM_MIN_Y;
        while (rand_under(3, 5) && tmpRoom.size[curr_x] < ROOM_MAX_X) {
            tmpRoom.size[curr_x]++;
        }
        while (rand_under(3, 5) && tmpRoom.size[curr_y] < ROOM_MAX_Y) {
            tmpRoom.size[curr_y]++;
        }
        d->rooms.push_back(tmpRoom);
    }

    return 0;
}

int gen_dungeon(dungeon_t *d)
{
    empty_dungeon(d);

    do {
        make_rooms(d);
    } while (place_rooms(d));
    connect_rooms(d);
    place_stairs(d);

    return 0;
}

void init_dungeon(dungeon_t *d)
{
    empty_dungeon(d);
}

void generate_dungon(dungeon_t *dunegeon) {

    srand(time(NULL));
    init_dungeon(dunegeon);
    gen_dungeon(dunegeon);

    return;
}
