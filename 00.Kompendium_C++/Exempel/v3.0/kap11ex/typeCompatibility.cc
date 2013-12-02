// Filnamn : .../typeCompatibility.cc

#include <iostream>
#include "person.h"
#include "sportsman.h"
#include "runner.h"
#include "student.h"
using namespace std;

int main() {
  person    p("P","P");
  sportsman sp("Sp", "Sp", "", 0);
  runner    ru("Ru", "Ru", "", 0, 0.0);
  student   st("S", "S", "MBL");

  // These assignments are OK
  p  = sp;            // en niv� upp
  p  = ru;            // tv� niv�er upp
  p  = st;            // en niv� upp
  sp = ru;            // en niv� upp

  // These assignments are NOT OK
  sp = p;
  ru = sp;
  ru = p;
  st = sp;
  return 0;
}
