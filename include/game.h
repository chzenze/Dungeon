//
// Created by chen_ on 2019/1/31.
//
#include "gameCommon.h"

#ifndef DUNGEON_V1_01_GAME_H
#define DUNGEON_V1_01_GAME_H




/*#define malloc(size) ({        \
  void *_tmp;                  \
  assert(_tmp = malloc(size)); \
  _tmp;                        \
})*/

void start_new();
void startGame();
void close_dungeon(int mode);


#endif //DUNGEON_V1_01_GAME_H
