#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"

#include "Hero.h"
#include "Dragon.h"


class Control
{
  public:
    Control();
    void launch();

  private:
    int tWin = 0;
    int hWin = 0;
    int bLoss = 0;
    View view;
    Timmy timmy;
    Harold harold;
    Dragon dragon;
    void run(int, int);
    bool generate_fighter();
};

#endif
