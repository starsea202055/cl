#ifndef ICON_H
#define ICON_H


#include <string>
#include <map>
using namespace std;

class ICON
{
public:
    static int GRID_SIZE;
    static map<string,ICON> GAME_ICON_SET;
    static ICON findICON(string type);

    ICON(){}
    ICON(string name, int x, int y, int w, int h);
    string getTypeName() const{return this->typeName;}
    int getSrcX() const{return this->srcX;}
    int getSrcY() const{return this->srcY;}
    int getWidth() const{return this->width;}
    int getHeight() const{return this->height;}

private:
    string typeName;
    int srcX, srcY, width, height;

};
#endif // ICON_H
