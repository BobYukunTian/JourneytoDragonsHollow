#include <iostream>
using namespace std;
#include <string>
#include "Dragon.h"

Dragon::Dragon() : QuestPlayer(1)
{
}

void Dragon::setInitalPosition(int width,int height)
{
  arr[1] = arr[3] = (int)height/2;
  arr[0] = arr[1] - 1;
  arr[2] = arr[1] + 1;
  current_position.x = width-1;
  current_position.y = arr[1];
}

void Dragon::next_position()
{
  current_position.y = arr[(dragon_move_count++)%4];
}
