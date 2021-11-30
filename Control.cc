#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <time.h>
#include<list>
#include <unistd.h>

#include "Control.h"
#include "Fighter.h"
#include "QuestPlayer.h"
#include "random.h"
#include "TwoDimArray.h"
Control::Control()
{

}

void Control::launch()
{
  int  choice;
  int  width = 25;
  int  height = 5;

  while (1) {
    view.showMenu(choice);

    if (choice == 0){
      view.printStr("See you next time! Bye!");
      break;
    }
    if (choice == 1) {
      //run
      run(width,height);
    }
    else if (choice == 2) {
      //change
      view.printStr("width: (default 25)");
      view.readInt(width);
      view.printStr("height: (default 5)");
      view.readInt(height);
      view.printStr("Changes saves.");
    }
    else if (choice == 3) {
      //print statistics
      view.printStr("\n Statistics: " );
      view.printStr("\n Number of times Timmy claim the Emerald: ");
      view.printInt(tWin);
      view.printStr("\n Number of times Harold claim the Emerald: ");
      view.printInt(hWin);
      view.printStr("\n Number of times both heros failured: ");
      view.printInt(bLoss);
    }
  }


}

bool Control::generate_fighter() {
    return random()%10 < 6;
}

void Control::run(int width, int height)
{
  srand(time(NULL));
  TwoDimArray<char> hollow(height,width);
  for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
          hollow[i][j]=' ';
      }
  }


  timmy.setInitalPosition(width, height);
  harold.setInitalPosition(width, height);
  dragon.setInitalPosition(width, height);

  list<QuestPlayer*> l;
  l.push_back(&timmy);
  l.push_back(&harold);
  l.push_back(&dragon);
  int success = 0;
  int mid=(int)height/2;
  bool harold_dead = false;
  bool timmy_dead = false;
  pair<int, int> dead_position;
  // start
  while (1) {
      sleep(1);
      //cout << "size: " << l.size() << endl;

      for (int i = 0; i < height; i++) {
          for (int j = 0; j < width; j++) {
              hollow[i][j]=' ';
          }
      }

      for (list<QuestPlayer*>::iterator it=l.begin(); it != l.end(); ++it) {
          if (dynamic_cast<Timmy *>((*it))) {
              hollow[(*it)->current_position.y][(*it)->current_position.x] = 'T';
          } else if (dynamic_cast<Harold *>((*it))) {
              hollow[(*it)->current_position.y][(*it)->current_position.x] = 'H';
          } else if (dynamic_cast<Borc *>((*it))) {
              hollow[(*it)->current_position.y][(*it)->current_position.x] = 'b';
          } else if (dynamic_cast<Porc *>((*it))) {
              hollow[(*it)->current_position.y][(*it)->current_position.x] = 'p';
          } else if (dynamic_cast<Dorc *>((*it))) {
              hollow[(*it)->current_position.y][(*it)->current_position.x] = 'd';
          } else if (dynamic_cast<Dragon *>((*it))) {
              hollow[(*it)->current_position.y][(*it)->current_position.x] = 'D';
          }
      }

      for (int i = 0; i < height; i++) {
          if (i == 0) {
              //cout <<"|-------------------------|"<<endl;
              cout << "|";
              for (int k = 0; k < width; k++)
                cout << "-";
              cout << "|"<<endl;
          }
          cout<<"|";
          for (int j = 0; j < width; j++) {
              if (timmy_dead || harold_dead) {
                  if (j == dead_position.first && i == dead_position.second)
                      hollow[i][j] = '+';
              }
              cout << hollow[i][j];
          }
          if ( i >= mid-1 && i <= mid+1) {
              cout << "=";
          } else {
              cout <<"|";
          }
          if (i == mid)
              cout <<" *";
          cout <<endl;
      }
      //cout <<"|-------------------------|"<<endl;
      cout << "|";
      for (int k = 0; k < width; k++)
        cout << "-";
      cout << "|"<<endl;

      // start one iteration
      if (generate_fighter()) {
          int n =random()%3;
          if (n == 0) {
              Dorc* dorc = new Dorc;
              dorc->setInitalPosition(width, height);
              l.push_back(dorc);
          } else if (n == 1) {
              Borc* borc = new Borc;
              borc->setInitalPosition(width, height);
              l.push_back(borc);
          } else if (n == 2) {
              Porc* porc = new Porc;
              porc->setInitalPosition(width, height);
              l.push_back(porc);
          }
      }
      for (list<QuestPlayer*>::iterator it=l.begin(); it != l.end(); ++it) {

          (*it)->next_position();
          //cout << " " << (*it)->current_position.x << endl;
          // every quest player move next position
          if (dynamic_cast<Hero *>((*it))) {

              if (dynamic_cast<Timmy *>((*it))) {
                  if ((*it)->current_position.x == width) {
                      tWin += 1;
                      cout <<"Timmy CLAIMS THE EMERALD!!!"<<endl;
                      success = 1;
                      break;
                  }
              } else {
                  if ((*it)->current_position.x == width) {
                      hWin += 1;
                      cout <<"Harold CLAIMS THE EMERALD!!!"<<endl;
                      success = 1;
                      break;
                  }
              }
          }
          //cout << "next postion end" << endl;
          //cout <<"x:" <<(*it).getCurrentPosition().x << "\t";
          if ((*it)->current_position.x < 0 || (*it)->current_position.x >= width) {
              //cout <<"start die" << endl;
              delete *it;
              //QuestPlayer* t =  *it;
              it = l.erase(it);
              //delete *t
              --it;
          }

      }
      if (success == 1) {
          break;
      }

      // iterate every quest player and compare with two hero
      // for timmy
      if (timmy_dead == false) {
          for (list<QuestPlayer *>::iterator it = l.begin(); it != l.end(); ++it) {
              if (timmy.current_position.x == (*it)->current_position.x &&
                  ((timmy.current_position.y == (*it)->current_position.y))) {

                  // itself and harold
                  if (dynamic_cast<Hero *>((*it))) {
                      continue;
                  }
                  if (dynamic_cast<Fighter *>((*it))) {
                      Fighter *f = dynamic_cast<Fighter *>((*it));
                      timmy.updateHealthPoint((f->getStrength()));
                      f->updateHealthPoint(timmy.getStrength());
                      //cout << "timmy health: " << timmy.getHealthPoint() << endl;
                      if (timmy.getHealthPoint() <= 0) {
                          timmy_dead = true;
                          dead_position ={(*it)->current_position.x, (*it)->current_position.y};
                          //cout << "timmy has no health point" << endl;
                          break;
                      }
                      if (f->getHealthPoint() <= 0) {
                          delete *it;
                          it = l.erase(it);
                          --it;
                      }
                  }
                  if (dynamic_cast<Dragon *>((*it))) {
                      //l.remove(timmy);
                      //cout<<"harold equal dragon" <<endl;
                      dead_position ={(*it)->current_position.x, (*it)->current_position.y};
                      timmy_dead = true;
                      break;
                  }
              }
          }
          if (timmy_dead == true)
              l.remove(&timmy);
      }

      // for harold
      if (harold_dead == false) {
          for (list<QuestPlayer *>::iterator it = l.begin(); it != l.end(); ++it) {
              if (harold.current_position.x == (*it)->current_position.x &&
                  ((harold.current_position.y == (*it)->current_position.y))) {

                  // itself and timmy
                  if (dynamic_cast<Hero *>((*it))) {
                      continue;
                  }
                  if (dynamic_cast<Fighter *>((*it))) {
                      Fighter *f = dynamic_cast<Fighter *>((*it));
                      harold.updateHealthPoint((f->getStrength()));
                      f->updateHealthPoint(timmy.getStrength());
                      //cout << "harold health: " << harold.getHealthPoint() << endl;
                      if (harold.getHealthPoint() <= 0) {
                          harold_dead = true;
                          //cout << "harold has no health point" << endl;
                          dead_position ={(*it)->current_position.x, (*it)->current_position.y};
                          break;
                      }
                      if (f->getHealthPoint() <= 0) {
                          delete *it;
                          it = l.erase(it);
                          --it;
                      }

                  }
                  if (dynamic_cast<Dragon *>((*it))) {
                      //l.remove(harold);
                      //cout<<"harold equal dragon" <<endl;
                      dead_position ={(*it)->current_position.x, (*it)->current_position.y};
                      harold_dead = true;
                      break;
                  }
              }
          }
          if (harold_dead == true)
              l.remove(&harold);
      }
      if (timmy_dead == true && harold_dead == true) {
          cout <<"Game over. Heroes failured" << endl;
          bLoss += 1;
          break;
      }

  }

  for (list<QuestPlayer *>::iterator it = l.begin(); it != l.end(); ++it)
  {
      if (dynamic_cast<Fighter *>((*it)))
        delete *it;
  }
  l.clear();

}
