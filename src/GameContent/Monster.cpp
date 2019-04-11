#include <time.h>
#include <math.h>
#include <unordered_map>
#include "../../include/GameContant/Monster.h"
#include "../../include/utils/data_stucture/heap.h"

#define getCurrentHardness this->dungeon->map[this->currentLocation[dim_y]][this->currentLocation[dim_x]].hardness
#define nextMonster(monster) ((corridor_node_t *) monster->path[this->currentLocation[dim_y]][this->currentLocation[dim_x]].prev_node)



//overload operator for priority queue
bool operator < (Monster monster1, Monster monster2){
    return monster1.getSpeed() < monster2.getSpeed();
}

bool operator> (Monster monster1, Monster monster2){
    return monster1.getSpeed() > monster2.getSpeed();
}

bool operator== (Monster monster1, Monster monster2){
    return monster1.getSpeed() == monster2.getSpeed();
}

Monster::Monster(std::unordered_map<std::string, std::string> base, dungeon_t * dungeon):GameContent(base){
    this->itemID = 0;
    this->dungeon = dungeon;
    this->range = (uint8_t) (rand() % 3);
}

bool Monster::meetWithPlayer(pair_t playerLocation){
    for (int i = -1 * this->range; i < this->range + 1 ; ++i) {
        for (int j = -1 * this->range; j < this->range + 1 ; ++j) {
            uint8_t x = (uint8_t) (this->currentLocation[dim_x] + i);
            uint8_t y = (uint8_t) (this->currentLocation[dim_y] + j);

            if (checkLocation(x,y)){
                if ((x == playerLocation[dim_x]) && (y == playerLocation[dim_y])){
                    this->lastPcLocation[dim_y] = y;
                    this->lastPcLocation[dim_x] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

int Monster::moveMonster(pair_t playerLocation){
    srand(time(NULL));

    pair_t nextParh;
    corridor_node_t path[DUNGEON_Y][DUNGEON_X];

    if (this->characteristics & 0x1){
        bool flag = true;
        if ((rand() % 2 ) == 1){
            while(flag){
                int x = this->currentLocation[dim_x] + rand()%3 - 1;
                int y = this->currentLocation[dim_y] + rand()%3 - 1;
                if (checkLocation(x,y)){
                    if ((dungeonMapTer(x,y) == ter_floor_room) ||
                        (dungeonMapTer(x,y)  == ter_floor_hall))
                    {
                        flag = false;
                        nextParh[dim_y] = (int16_t) y;
                        nextParh[dim_x] = (int16_t) x;
                    }
                }
            }
            goto update;
        }
    }

    if (this->characteristics & 0x4){
        if(this->characteristics & 0x8){
            if(this->characteristics & 0x2){
                if ( getCurrentHardness == 0){
                    dijkstra_tunnelling(playerLocation);
                    nextParh[dim_x] = nextMonster(this)->pos[dim_x];
                    nextParh[dim_y] = nextMonster(this)->pos[dim_y];
                    goto update;
                } else{
                    if (getCurrentHardness <= 85)
                        getCurrentHardness = 0;
                    else{
                        getCurrentHardness -= 85;
                    }
                    return 0;
                }
            }else{
                dijkstra_no_tunnelling(playerLocation);
                nextParh[dim_x] = nextMonster(this)->pos[dim_x];
                nextParh[dim_y] = nextMonster(this)->pos[dim_y];
                goto update;
            }
        }else{
            double shortestDistance = UINT32_MAX;
            for (int i = -1; i <2 ; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int16_t y = (int16_t) (this->currentLocation[dim_y] + j);
                    int16_t x = (int16_t) (this->currentLocation[dim_x] + i);
                    if (checkLocation(x,y)){
                        double distance = sqrt(abs(this->currentLocation[dim_y] + j - playerLocation[dim_y])) +
                                            sqrt(abs(this->currentLocation[dim_x] + i - playerLocation[dim_x]));
                        if (distance < shortestDistance){
                            shortestDistance = distance;
                            nextParh[dim_x] = x;
                            nextParh[dim_y] = y;
                        }
                    }
                }
            }
            goto update;
        }
    } else if (this->meetWithPlayer(playerLocation)){
        if(this->characteristics & 0x8){
            if(this->characteristics & 0x2){
                if (getCurrentHardness == 0){
                    dijkstra_tunnelling(playerLocation);
                    nextParh = nextMonster(this)->pos;
                    goto update;
                } else{
                    if (getCurrentHardness <= 85)
                        getCurrentHardness = 0;
                    else{
                        getCurrentHardness -= 85;
                    }
                    return 0;
                }
            }else{
                dijkstra_no_tunnelling(playerLocation);
                nextParh = nextMonster(this)->pos;
                goto update;
            }
        } else
            return 0;
    } else
        return 0;

    update:
    this->prevLocation = this->currentLocation;
    this->currentLocation = nextParh;

    return 0;
}

static int32_t corridor_node_cmp(const void *key, const void *with) {
    return ((corridor_node_t *) key)->cost - ((corridor_node_t *) with)->cost;
}

void Monster::dijkstra_no_tunnelling(pair_t playerLocation)
{

    heap_t h;
    corridor_node_t *prev_node;

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            this->path[y][x].pos[dim_y] = y;
            this->path[y][x].pos[dim_x] = x;
            this->path[y][x].cost = INT32_MAX;

        }
    }

    this->path[playerLocation[dim_y]][playerLocation[dim_x]].cost = 0;

    heap_init(&h, corridor_node_cmp, NULL);

    heap_insert(&h,&this->path[playerLocation[dim_y]][playerLocation[dim_x]]);

    while (h.size != 0){
        prev_node = (corridor_node_t *) heap_remove_min(&h);
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[dim_x];
                uint16_t y = i + prev_node->pos[dim_y];

                if (checkLocation(x,y)){
                    if (dungeonMapTer(x,y) != ter_wall){
                        if (prev_node->cost + 1 < this->path[y][x].cost){
                            this->path[y][x].prev_node = prev_node;
                            this->path[y][x].cost = prev_node->cost + 1;

                            heap_insert(&h,&this->path[y][x]);
                        }
                    }
                }
            }
        }
    }
    heap_delete(&h);
}

void Monster::dijkstra_tunnelling(pair_t playerLocation)
{

    heap_t h;
    corridor_node_t *prev_node;

    for (uint16_t y = 0; y < DUNGEON_Y; y++) {
        for (uint16_t x = 0; x < DUNGEON_X; x++) {
            this->path[y][x].pos[dim_y] = y;
            this->path[y][x].pos[dim_x] = x;
            this->path[y][x].cost = INT32_MAX;

        }
    }


    this->path[playerLocation[dim_y]][playerLocation[dim_x]].cost = 0;

    heap_init(&h, corridor_node_cmp, NULL);

    heap_insert(&h,&this->path[playerLocation[dim_y]][playerLocation[dim_x]]);

    while (h.size != 0){
        prev_node = (corridor_node_t*) heap_remove_min(&h);
        for (int8_t i = -1; i < 2; ++i) {
            for (int8_t j = -1; j < 2 ; ++j) {
                uint16_t x = j + prev_node->pos[dim_x];
                uint16_t y = i + prev_node->pos[dim_y];

                if (checkLocation(x,y)){
                    int weight_tmp = 0;

                    if (dungeonMapTer(x,y) == ter_wall_immutable)
                        break;

                    if (dungeonMapTer(x,y) == 0){
                        weight_tmp = 1 + prev_node->cost;
                    }else{
                        weight_tmp = 1 + (dungeonMapTer(x,y)/85) + prev_node->cost;
                    }

                    if (weight_tmp < this->path[y][x].cost){

                        this->path[y][x].prev_node = prev_node;
                        this->path[y][x].cost = weight_tmp;

                        heap_insert(&h,&this->path[y][x]);
                    }
                }
            }
        }
    }
    heap_delete(&h);
}
