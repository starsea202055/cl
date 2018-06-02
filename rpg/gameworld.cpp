#include "gameworld.h"
#include "icon.h"

 RPGObj obj1, obj2, obj3, obj4, obj5, obj6, obj7;

void gameworld::initWorld(string mapFile){

    this->_player.initObj("player");
    this->_player.setPosX(3);
    this->_player.setPosY(3);

    obj1.initObj("stone");
    obj1.setPosX(3);
    obj1.setPosY(0);

    obj2.initObj("stone");
    obj2.setPosX(4);
    obj2.setPosY(0);

    obj3.initObj("box");
    obj3.setPosX(2);
    obj3.setPosY(3);

    obj4.initObj("flower");
    obj4.setPosX(7);
    obj4.setPosY(6);

    obj5.initObj("flower");
    obj5.setPosX(5);
    obj5.setPosY(7);

    obj6.initObj("house1");
    obj6.setPosX(0);
    obj6.setPosY(0);

    /*obj7.initObj("player");
    obj7.setPosX(3);
    obj7.setPosY(3);*/

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);
    this->_objs.push_back(obj6);
    //this->_objs.push_back(obj7);

}


void gameworld::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
    this->_player.show(painter);

}

void gameworld::handlePlayerMove (int direction,int steps){

     this->_player.move(direction, steps);
}
