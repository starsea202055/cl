#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 64;


pair<string,ICON> pairArray[] =
{
    make_pair("player",ICON("player",4,0, 1, 1)),
    make_pair("stone",ICON("stone",4,1, 1, 1)),
    make_pair("box",ICON("box",0,0, 1, 1)),
    make_pair("house1",ICON("house1",0,2, 3, 3)),
    //make_pair("house2",ICON("house2",10,2, 1, 1)),
    make_pair("flower",ICON("flower",3,1, 1, 1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
