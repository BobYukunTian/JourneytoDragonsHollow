#include <iostream>
using namespace std;
#include <string>

#include "Hero.h"

Hero::Hero(int h, int s, int a) : QuestPlayer(h,s,a)
{

}

void Hero::setInitalPosition(int width,int height)
{
    w=width;
    h=height;
    mid=(int)height/2;
    current_position.x = 0;
    current_position.y = rand()%h;

}

void Hero::next_position()
{
    if (current_position.y >=mid-1 && current_position.y <= mid+1) {
        if (current_position.x == w-1) {
            current_position.x = w;
        }
    }
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

    if (current_position.x < w-1)
        current_position.x += 1;

        //cout <<"hero： " << current_position.x << endl;
  }
