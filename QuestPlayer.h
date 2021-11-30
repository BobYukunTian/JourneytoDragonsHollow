#ifndef QUESTPLAYER_H
#define QUESTPLAYER_H

#include "Position.h"

class QuestPlayer {
private:
    int healthPoint;
    int strength;
    int armour;
  public:
    QuestPlayer(int);
    QuestPlayer(int, int);
    QuestPlayer(int, int, int);
    Position current_position;
    void setCurrentPosition(const Position &currentPosition);
    virtual void next_position()=0;
    virtual void setInitalPosition(int, int)=0;
    int getStrength() const;
    int getHealthPoint() const;
    // The damage is equal to the ﬁghter’s strength, minus the hero’s armour.
    void updateHealthPoint(int n);
};

#endif //DRAGON_QUESTPLAYER_H
