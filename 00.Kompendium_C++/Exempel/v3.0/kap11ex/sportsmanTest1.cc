// Filnamn : .../sportsmanTest1.cc
#include <iostream>
#include <string>
#include "sportsman.h"
using namespace std;

int main() {
  sportsman anyOne("Kajsa", "Bergkvist", "h�jdhopp", 100);

  anyOne.report();
  anyOne.firstPrize();
  cout << "Hej ";
  anyOne.writeName();
  cout << ", du har " << anyOne.getNrFirstPrize() 
       << " f�rstapriser!" << endl;

  return 0;
}
