#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"

class gameworld
{
public:
    gameworld(){}
    ~gameworld(){}
    void initWorld(string mapFile);
    void show(QPainter * painter);
    void handlePlayerMove(int direction,int steps);

private:
    vector<RPGObj> _objs;
    Player _player;

};

#endif // GAMEWORLD_H
