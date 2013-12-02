// Filnamn : .../kap11ex/nonVirtual.cc
#include <iostream>
#include "personVirt.h"
#include "sportsman.h"
#include "student.h"
using namespace std;

int main() {
  person *p;    

  int ans;
  cout << "Skapa en idrottare eller en student? " << endl;
  cout << "Svara 1 f�r idrottare och 2 f�r student: ";
  cin >> ans;

  if (ans==1)
    p = new sportsman("Kalle", "Kula", "kulst�tning", 0);
  else
    p = new student("Fia", "Flitig", "Molekylar Bioteknik" );
  p->report();
  delete p;
  return 0;
}
