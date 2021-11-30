#ifndef DRAGON_H
#define DRAGON_H

#include "QuestPlayer.h"

class Dragon: public QuestPlayer {
  public:
    Dragon();
    void setInitalPosition(int,int);
    void next_position();
  private:
    int dragon_move_count = 0;
    int arr[4];
};

#endif //DRAGON_H
