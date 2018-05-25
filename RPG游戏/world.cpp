#include "world.h"
#include "icon.h"

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);

    //stone 4 5
    RPGObj obj1, obj2, obj3,obj4, obj5,obj6,obj7,obj8,obj9,obj10,obj11,obj12,obj13;
       obj1.initObj("stone");
       obj1.setPosX(4);
       obj1.setPosY(3);

       obj2.initObj("stone");
       obj2.setPosX(6);
       obj2.setPosY(5);

       obj3.initObj("fruit");
       obj3.setPosX(10);
       obj3.setPosY(8);

       obj4.initObj("well");
       obj4.setPosX(9);
       obj4.setPosY(9);

       obj5.initObj("tree");
       obj5.setPosX(7);
       obj5.setPosY(10);

       obj6.initObj("bucket");
       obj6.setPosX(5);
       obj6.setPosY(8);

       obj7.initObj("fruit");
       obj7.setPosX(17);
       obj7.setPosY(16);

       obj8.initObj("fruit");
       obj8.setPosX(19);
       obj8.setPosY(14);

       obj9.initObj("stone");
       obj9.setPosX(10);
       obj9.setPosY(12);

       obj10.initObj("tree");
       obj10.setPosX(7);
       obj10.setPosY(15);

       obj11.initObj("house");
       obj11.setPosX(12);
       obj11.setPosY(6);

       obj12.initObj("well1");
       obj12.setPosX(16);
       obj12.setPosY(4);

       obj13.initObj("bedroom");
       obj13.setPosX(17);
       obj13.setPosY(7);

       this->_objs.push_back(obj1);
       this->_objs.push_back(obj2);
       this->_objs.push_back(obj3);
       this->_objs.push_back(obj4);
       this->_objs.push_back(obj5);
       this->_objs.push_back(obj6);
       this->_objs.push_back(obj7);
       this->_objs.push_back(obj8);
       this->_objs.push_back(obj9);
       this->_objs.push_back(obj10);
       this->_objs.push_back(obj11);
       this->_objs.push_back(obj12);
       this->_objs.push_back(obj13);


}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((_player.getPosX()==(*it).getPosX())&&(_player.getPosY()==(*it).getPosY()-1)&&((*it).canCover()==false))
        {
            if((*it).canEat()==false)
            {
                continue;
            }
            else
            {
             it=_objs.erase(it)  ;
            }
        }
        else
        {
             (*it).show(painter);
        }
    }
    this->_player.show(painter);
}

void World::handlePlayerMove(int direction, int steps){

    this->_player.move(direction, steps);
}

