#include "player.h"

//direction =1,2,3,4 for 上下左右
void Player::move(int direction, int steps){
 switch (direction){
        case 1:
        if((_pos_x==4&&_pos_y==3)||(_pos_x==6&&_pos_y==5)||(_pos_x==10&&_pos_y==12))
        { break;}
        else
           { this->_pos_y -= steps;
            break;}
        case 2:
        if((_pos_x==4&&_pos_y==1)||(_pos_x==6&&_pos_y==3)||(_pos_x==10&&_pos_y==10))
            {  break;}
        else
            {this->_pos_y += steps;
            break;}
        case 3:
         if((_pos_x==5&&_pos_y==2)||(_pos_x==7&&_pos_y==4)||(_pos_x==11&&_pos_y==11))
         {  break;}
         else
            {this->_pos_x -= steps;
            break;}
        case 4:
        if((_pos_x==3&&_pos_y==2)||(_pos_x==5&&_pos_y==4)||(_pos_x==9&&_pos_y==11))
         {  break;}
        else
            {this->_pos_x += steps;
            break;}
    }
}

