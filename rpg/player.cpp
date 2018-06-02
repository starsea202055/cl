#include "player.h"

void Player::move(int direction, int steps){
    switch (direction){
        case 1:
           this->_pos_y -= steps;
           break;

        case 2:
           this->_pos_y += steps;
           break;

        case 3:
           this->_pos_x -= steps;
           break;

        case 4:
           this->_pos_x += steps;
           break;
    }
}
