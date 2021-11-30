#ifndef HERO_H
#define HERO_H

#include "QuestPlayer.h"

class Hero: public QuestPlayer {
private:
    int w;
    int h;
    int mid;
public:
    Hero(int, int, int);
    void setInitalPosition(int, int);
    void next_position();

};

class Timmy: public Hero {
public:
    Timmy() : Hero(15,3,3){}
};

class Harold: public Hero {
public:
    Harold() : Hero(15,5,1){}
};

#endif //DRAGON_HERO_H
