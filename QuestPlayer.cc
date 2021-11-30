#include <iostream>
using namespace std;
#include <string>
#include "QuestPlayer.h"

QuestPlayer::QuestPlayer(int h) : healthPoint(h), strength(0), armour(0)
{
}

QuestPlayer::QuestPlayer(int h, int s) : healthPoint(h), strength(s), armour(0)
{
}

QuestPlayer::QuestPlayer(int h, int s, int a) : healthPoint(h), strength(s), armour(a)
{
}

void QuestPlayer::setCurrentPosition(const Position &currentPosition)
{
  current_position = currentPosition;
}

int QuestPlayer::getStrength() const
{
    return strength;
}

int QuestPlayer::getHealthPoint() const
{
    return healthPoint;
}

        // The damage is equal to the ﬁghter’s strength, minus the hero’s armour.
void QuestPlayer::updateHealthPoint(int n)
{
    this->healthPoint -=(n-this->armour);
}
