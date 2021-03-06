//
// Created by 陈瀚泽 on 2019-03-11.
//

#ifndef DUNGEON_COMS327_F19_GAMECOMMON_H
#define DUNGEON_COMS327_F19_GAMECOMMON_H

#include <list>
#include <memory>
#include <pthread.h>
#include <vector>
#include <cstdint>
#include "macros.h"

class Item;
class Monster;

using namespace std;

typedef enum dim {
    curr_x,     curr_y,
    prev_x,     prev_y
} dim_t;

typedef struct location{
private:
    struct pair {
        int dimx = 0;
        int dimy = 0;
    }pair_t;
    struct pair prev;
    struct pair current;
public:
    int& operator[](int i){
        if (i == curr_x)
            return this->current.dimx;
        else if (i == curr_y)
            return this->current.dimy;
        else if (i == prev_x)
            return this->prev.dimx;
        else
            return this->prev.dimy;
    }
    void operator=(struct location pair){
        this->prev = this->current;
        this->current.dimx = pair[curr_x];
        this->current.dimy = pair[curr_y];
    }
}location_t;

typedef struct corridor_node {
    int cost;
    location_t pos;
    void * prev_node;
} corridor_node_t;

typedef enum __attribute__ ((__packed__)) terrain_type {
    ter_debug,
    ter_wall,
    ter_wall_immutable,
    ter_floor,
    ter_floor_room,
    ter_floor_hall,
    ter_stairs,
    ter_stairs_up,
    ter_stairs_down
} terrain_type_t;

typedef struct map_block{
    uint8_t hardness = 0;
    Monster * monster = nullptr;
    std::unique_ptr<Item> item;
    terrain_type_t terrain_type = ter_debug;
    bool visable = false, isMonsterInit = false, isItemInit = false;
} map_block_t;

typedef struct room{
    location_t position;
    location_t size;
}room_t;

typedef enum direction{
    Upper,      UpperLeft,      UpperRight,
    Left,       Right,          Down,
    DownLeft,   DownRight,
}direction_t;

class Dungeon {
private:

bool FogOfWarFlag;
bool TeleportFlag;

vector<vector<map_block_t>> map;
corridor_node_t tunnel[DUNGEON_Y][DUNGEON_X];
corridor_node_t nontunnel[DUNGEON_Y][DUNGEON_X];

std::vector<room_t> rooms;

list<Item> items;
list<Monster> monsters;

public:
Dungeon(int sizeX, int sizeY){
    //allocate spaces
    this->map = vector<vector<map_block_t>>(sizeX);
    for (auto mapY : this->map){
        mapY = vector<map_block_t>(sizeY);
    }
}

};

#endif //DUNGEON_COMS327_F19_GAMECOMMON_H
