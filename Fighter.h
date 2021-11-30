#ifndef FIGHTER_H
#define FIGHTER_H

#include "QuestPlayer.h"
#include "random.h"

class Fighter: public QuestPlayer {
private:
  int w;
  int h;
public:
    Fighter(int, int);
    void setInitalPosition(int, int);
    void next_position();

};

class Dorc :public Fighter {
public:
    Dorc() : Fighter(5, random()%3+6){}
};

class Borc:public Fighter {
public:
    Borc() : Fighter(5, random()%4+8){}
};

class Porc:public Fighter {
public:
    Porc() : Fighter(5, random()%2+4){}
};

#endif //FIGHTER_H
