// Filnamn : .../main.cc

/* 
   Ett huvudprogram till 'Game of life'. 
*/

#include <iostream>
#include "Celler.h"
#include "funk.h"
using namespace std;

int main() {
  int myChoice;
  Cells game;
  
  cout << "L�t oss spela med celler!" << endl;

  do {
    menu();
    myChoice = readChoice();
    
    if (myChoice == 1) {
      game.initiate();
      game.newGeneration();
    }
    else 
      cout << "Hej d�, tack f�r idag!" << endl;
  } while (myChoice == 1);

  return 0;
}

