COMP 2404 -- Take-home Final Exam
program name: final
Author: Bob Tian  #101083783

This is a C++ program simulate a confined area called Dragon’s Hollow, which is basically a flat, sunken area,surrounded by trees on three sides and a cave on the other. Timmy Tortoise and Harold the Hare will make their way from the left-hand side of Dragon’s Hollow to the right-hand side, where theEmeraldis locatedinside the cave. This cave is guarded by a Dragon and a bunch of dorcs, borcs, and porcs.The goal of the program is for Timmy or Harold to make their way across Dragon’s Hollow (moving fromthe left-hand side to the right-hand side), and rescue theEmerald, all without dying.

Added Several innovative features:
Add a welcome interface for user selection
Provice interface for adjusting width and height of the Hollow
The QuestPlayer will act acording to the new size and perform correct beheiviour
Add statistics page to log outcomes of all run during the program, and print it for user
classes are involved in providing the functionality:
main
Dragon
Hero
QuestPlayer
View


List of source/header/data files:

Array.h     Dragon.h    Hero.h      QuestPlayer.cc  README.txt
Control.cc  Fighter.cc  main.cc     QuestPlayer.h   TwoDimArray.h
Control.h   Fighter.h   Makefile    random.cc       View.cc
Dragon.cc   Hero.cc     Position.h  random.h        View.h


Compilation and launching instructions:
make
./final
