#include <iostream>
using namespace std;
#include <string>

#include "Fighter.h"

Fighter::Fighter(int h, int s) : QuestPlayer(h, s)
{

}

void Fighter::setInitalPosition(int width,int height)
{
    w=width;
    h=height;
    current_position.x = w-1;
    current_position.y = random()%h;
}

void Fighter::next_position()
{
        int d = random()%3;
        if (d == 0) {
            current_position.y = current_position.y;
        } else if (d == 1) {
            if (current_position.y < h-1)
                current_position.y += 1;
        } else if (d == 2) {
            if (current_position.y >0)
                current_position.y -= 1;
        }

        current_position.x -= 1;
        //cout <<"fighter： " << current_position.x <<endl;

}
