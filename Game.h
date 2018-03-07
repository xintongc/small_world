//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_GAME_H
#define SMALL_WORLD_GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Map.h"
#include "MapLoader.h"


class Game {

private:

    vector<Player> Players;
    int round;
    Map map = Map(1);

public:

    virtual ~Game();


};


#endif //SMALL_WORLD_GAME_H
