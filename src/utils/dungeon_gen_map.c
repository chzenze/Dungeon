//
// Created by chen_ on 2019/1/31.
//

#include <time.h>
#include <limits.h>
#include "../../include/game.h"
#include "../../include/gameCommon.h"
#include "../../include/utils/data_stucture/heap.h"


static uint32_t in_room(dungeon_t *d, int16_t y, int16_t x)
{
    int i;

    for (i = 0; i < d->num_rooms; i++) {
        if ((x >= d->rooms[i].position[dim_x]) &&
            (x < (d->rooms[i].position[dim_x] + d->rooms[i].size[dim_x])) &&
            (y >= d->rooms[i].position[dim_y]) &&
            (y < (d->rooms[i].position[dim_y] + d->rooms[i].size[dim_y]))) {
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

static void dijkstra_corridor(dungeon_t *d, pair_t from, pair_t to)
{
    static corridor_path_t path[DUNGEON_Y][DUNGEON_X], *p;
    static uint32_t initialized = 0;
    heap_t h;
    uint32_t x, y;

    if (!initialized) {
        for (y = 0; y < DUNGEON_Y; y++) {
            for (x = 0; x < DUNGEON_X; x++) {
                path[y][x].pos[dim_y] = y;
                path[y][x].pos[dim_x] = x;
            }
        }
        initialized = 1;
    }

    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            path[y][x].cost = INT_MAX;
        }
    }

    path[from[dim_y]][from[dim_x]].cost = 0;

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

    while ((p = heap_remove_min(&h))) {
        p->hn = NULL;

        if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
            for (x = to[dim_x], y = to[dim_y];
                 (x != from[dim_x]) || (y != from[dim_y]);
                 p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
                if (mapxy(x, y) != ter_floor_room) {
                    mapxy(x, y) = ter_floor_hall;
                    hardnessxy(x, y) = 0;
                }
            }
            heap_delete(&h);
            return;
        }

        if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
            (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
            [p->pos[dim_x]    ].hn);
        }
        if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
            (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
            [p->pos[dim_x] - 1].hn);
        }
        if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
            (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
            [p->pos[dim_x] + 1].hn);
        }
        if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
            (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
             p->cost + hardnesspair(p->pos))) {
            path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
                    p->cost + hardnesspair(p->pos);
            path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
            [p->pos[dim_x]    ].hn);
        }
    }
}

/* This is a cut-and-paste of the above.  The code is modified to  *
 * calculate paths based on inverse hardnesses so that we get a    *
 * high probability of creating at least one cycle in the dungeon. */
static void dijkstra_corridor_inv(dungeon_t *d, pair_t from, pair_t to)
{
    static corridor_path_t path[DUNGEON_Y][DUNGEON_X], *p;
    static uint32_t initialized = 0;
    heap_t h;
    uint32_t x, y;

    if (!initialized) {
        for (y = 0; y < DUNGEON_Y; y++) {
            for (x = 0; x < DUNGEON_X; x++) {
                path[y][x].pos[dim_y] = y;
                path[y][x].pos[dim_x] = x;
            }
        }
        initialized = 1;
    }

    for (y = 0; y < DUNGEON_Y; y++) {
        for (x = 0; x < DUNGEON_X; x++) {
            path[y][x].cost = INT_MAX;
        }
    }

    path[from[dim_y]][from[dim_x]].cost = 0;

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

    while ((p = heap_remove_min(&h))) {
        p->hn = NULL;

        if ((p->pos[dim_y] == to[dim_y]) && p->pos[dim_x] == to[dim_x]) {
            for (x = to[dim_x], y = to[dim_y];
                 (x != from[dim_x]) || (y != from[dim_y]);
                 p = &path[y][x], x = p->from[dim_x], y = p->from[dim_y]) {
                if (mapxy(x, y) != ter_floor_room) {
                    mapxy(x, y) = ter_floor_hall;
                    hardnessxy(x, y) = 0;
                }
            }
            heap_delete(&h);
            return;
        }

#define hardnesspair_inv(p) (is_open_space(d, p[dim_y], p[dim_x]) ? 127 :     \
                             (adjacent_to_room(d, p[dim_y], p[dim_x]) ? 191 : \
                              (255 - hardnesspair(p))))

        if ((path[p->pos[dim_y] - 1][p->pos[dim_x]    ].hn) &&
            (path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[dim_y] - 1][p->pos[dim_x]    ].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y] - 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y] - 1]
            [p->pos[dim_x]    ].hn);
        }
        if ((path[p->pos[dim_y]    ][p->pos[dim_x] - 1].hn) &&
            (path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[dim_y]    ][p->pos[dim_x] - 1].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y]    ][p->pos[dim_x] - 1].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
            [p->pos[dim_x] - 1].hn);
        }
        if ((path[p->pos[dim_y]    ][p->pos[dim_x] + 1].hn) &&
            (path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[dim_y]    ][p->pos[dim_x] + 1].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y]    ][p->pos[dim_x] + 1].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y]    ]
            [p->pos[dim_x] + 1].hn);
        }
        if ((path[p->pos[dim_y] + 1][p->pos[dim_x]    ].hn) &&
            (path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost >
             p->cost + hardnesspair_inv(p->pos))) {
            path[p->pos[dim_y] + 1][p->pos[dim_x]    ].cost =
                    p->cost + hardnesspair_inv(p->pos);
            path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_y] = p->pos[dim_y];
            path[p->pos[dim_y] + 1][p->pos[dim_x]    ].from[dim_x] = p->pos[dim_x];
            heap_decrease_key_no_replace(&h, path[p->pos[dim_y] + 1]
            [p->pos[dim_x]    ].hn);
        }
    }
}

/* Chooses a random point inside each room and connects them with a *
 * corridor.  Random internal points prevent corridors from exiting *
 * rooms in predictable locations.                                  */
static int connect_two_rooms(dungeon_t *d, room_t *r1, room_t *r2)
{
    pair_t e1, e2;

    e1[dim_y] = rand_range(r1->position[dim_y],
                           r1->position[dim_y] + r1->size[dim_y] - 1);
    e1[dim_x] = rand_range(r1->position[dim_x],
                           r1->position[dim_x] + r1->size[dim_x] - 1);
    e2[dim_y] = rand_range(r2->position[dim_y],
                           r2->position[dim_y] + r2->size[dim_y] - 1);
    e2[dim_x] = rand_range(r2->position[dim_x],
                           r2->position[dim_x] + r2->size[dim_x] - 1);

    /*  return connect_two_points_recursive(d, e1, e2);*/
    dijkstra_corridor(d, e1, e2);

    return 0;
}

static int create_cycle(dungeon_t *d)
{
    /* Find the (approximately) farthest two rooms, then connect *
     * them by the shortest path using inverted hardnesses.      */

    int32_t max, tmp, i, j, p, q;
    pair_t e1, e2;

    for (i = max = 0; i < d->num_rooms - 1; i++) {
        for (j = i + 1; j < d->num_rooms; j++) {
            tmp = (((d->rooms[i].position[dim_x] - d->rooms[j].position[dim_x])  *
                    (d->rooms[i].position[dim_x] - d->rooms[j].position[dim_x])) +
                   ((d->rooms[i].position[dim_y] - d->rooms[j].position[dim_y])  *
                    (d->rooms[i].position[dim_y] - d->rooms[j].position[dim_y])));
            if (tmp > max) {
                max = tmp;
                p = i;
                q = j;
            }
        }
    }

    /* Can't simply call connect_two_rooms() because it doesn't *
     * use inverse hardnesses, so duplicate it here.            */
    e1[dim_y] = rand_range(d->rooms[p].position[dim_y],
                           (d->rooms[p].position[dim_y] +
                            d->rooms[p].size[dim_y] - 1));
    e1[dim_x] = rand_range(d->rooms[p].position[dim_x],
                           (d->rooms[p].position[dim_x] +
                            d->rooms[p].size[dim_x] - 1));
    e2[dim_y] = rand_range(d->rooms[q].position[dim_y],
                           (d->rooms[q].position[dim_y] +
                            d->rooms[q].size[dim_y] - 1));
    e2[dim_x] = rand_range(d->rooms[q].position[dim_x],
                           (d->rooms[q].position[dim_x] +
                            d->rooms[q].size[dim_x] - 1));

    dijkstra_corridor_inv(d, e1, e2);

    return 0;
}

static int connect_rooms(dungeon_t *d)
{
    uint32_t i;

    for (i = 1; i < d->num_rooms; i++) {
        connect_two_rooms(d, d->rooms + i - 1, d->rooms + i);
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
            head = tail = malloc(sizeof (*tail));
        } else {
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
        }
        tail->next = NULL;
        tail->x = x;
        tail->y = y;
    }

    out = fopen("seeded.pgm", "w");
    fprintf(out, "P5\n%u %u\n255\n", DUNGEON_X, DUNGEON_Y);
    fwrite(&hardness, sizeof (hardness), 1, out);
    fclose(out);

    /* Diffuse the vaules to fill the space */
    while (head) {
        x = head->x;
        y = head->y;
        i = hardness[y][x];

        if (x - 1 >= 0 && y - 1 >= 0 && !hardness[y - 1][x - 1]) {
            hardness[y - 1][x - 1] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x - 1;
            tail->y = y - 1;
        }
        if (x - 1 >= 0 && !hardness[y][x - 1]) {
            hardness[y][x - 1] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x - 1;
            tail->y = y;
        }
        if (x - 1 >= 0 && y + 1 < DUNGEON_Y && !hardness[y + 1][x - 1]) {
            hardness[y + 1][x - 1] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x - 1;
            tail->y = y + 1;
        }
        if (y - 1 >= 0 && !hardness[y - 1][x]) {
            hardness[y - 1][x] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x;
            tail->y = y - 1;
        }
        if (y + 1 < DUNGEON_Y && !hardness[y + 1][x]) {
            hardness[y + 1][x] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x;
            tail->y = y + 1;
        }
        if (x + 1 < DUNGEON_X && y - 1 >= 0 && !hardness[y - 1][x + 1]) {
            hardness[y - 1][x + 1] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x + 1;
            tail->y = y - 1;
        }
        if (x + 1 < DUNGEON_X && !hardness[y][x + 1]) {
            hardness[y][x + 1] = i;
            tail->next = malloc(sizeof (*tail));
            tail = tail->next;
            tail->next = NULL;
            tail->x = x + 1;
            tail->y = y;
        }
        if (x + 1 < DUNGEON_X && y + 1 < DUNGEON_Y && !hardness[y + 1][x + 1]) {
            hardness[y + 1][x + 1] = i;
            tail->next = malloc(sizeof (*tail));
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
            d->hardness[y][x] = t / s;
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
            d->hardness[y][x] = t / s;
        }
    }


    out = fopen("diffused.pgm", "w");
    fprintf(out, "P5\n%u %u\n255\n", DUNGEON_X, DUNGEON_Y);
    fwrite(&hardness, sizeof (hardness), 1, out);
    fclose(out);

    out = fopen("smoothed.pgm", "w");
    fprintf(out, "P5\n%u %u\n255\n", DUNGEON_X, DUNGEON_Y);
    fwrite(&d->hardness, sizeof (d->hardness), 1, out);
    fclose(out);

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
    pair_t p;
    uint32_t i;
    int success;
    room_t *r;

    for (success = 0; !success; ) {
        success = 1;
        for (i = 0; success && i < d->num_rooms; i++) {
            r = d->rooms + i;
            r->position[dim_x] = 1 + rand() % (DUNGEON_X - 2 - r->size[dim_x]);
            r->position[dim_y] = 1 + rand() % (DUNGEON_Y - 2 - r->size[dim_y]);
            for (p[dim_y] = r->position[dim_y] - 1;
                 success && p[dim_y] < r->position[dim_y] + r->size[dim_y] + 1;
                 p[dim_y]++) {
                for (p[dim_x] = r->position[dim_x] - 1;
                     success && p[dim_x] < r->position[dim_x] + r->size[dim_x] + 1;
                     p[dim_x]++) {
                    if (mappair(p) >= ter_floor) {
                        success = 0;
                        empty_dungeon(d);
                    } else if ((p[dim_y] != r->position[dim_y] - 1)              &&
                               (p[dim_y] != r->position[dim_y] + r->size[dim_y]) &&
                               (p[dim_x] != r->position[dim_x] - 1)              &&
                               (p[dim_x] != r->position[dim_x] + r->size[dim_x])) {
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
    pair_t p;
    do {
        while ((p[dim_y] = rand_range(1, DUNGEON_Y - 2)) &&
               (p[dim_x] = rand_range(1, DUNGEON_X - 2)) &&
               ((mappair(p) < ter_floor)                 ||
                (mappair(p) > ter_stairs)))
            ;
        d->num_down_stairs += 1;
        mappair(p) = ter_stairs_down;
    } while (rand_under(1, 3));
    do {
        while ((p[dim_y] = rand_range(1, DUNGEON_Y - 2)) &&
               (p[dim_x] = rand_range(1, DUNGEON_X - 2)) &&
               ((mappair(p) < ter_floor)                 ||
                (mappair(p) > ter_stairs)))

            ;
        d->num_up_stairs += 1;
        mappair(p) = ter_stairs_up;
    } while (rand_under(2, 4));

    //tmp set stair number to 1
}

static int make_rooms(dungeon_t *d)
{
    uint32_t i;

    memset(d->rooms, 0, sizeof (d->rooms));

    for (i = MIN_ROOMS; i < MAX_ROOMS && rand_under(5, 8); i++)
        ;
    d->num_rooms = i;

    for (i = 0; i < d->num_rooms; i++) {
        d->rooms[i].size[dim_x] = ROOM_MIN_X;
        d->rooms[i].size[dim_y] = ROOM_MIN_Y;
        while (rand_under(3, 5) && d->rooms[i].size[dim_x] < ROOM_MAX_X) {
            d->rooms[i].size[dim_x]++;
        }
        while (rand_under(3, 5) && d->rooms[i].size[dim_y] < ROOM_MAX_Y) {
            d->rooms[i].size[dim_y]++;
        }
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
