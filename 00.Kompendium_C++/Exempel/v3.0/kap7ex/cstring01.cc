// Filnamn: .../cstring01.cc
// Felaktig hantering av str�ngar
#include <iostream.h>

int main() {
  int i = 0xffffffff;    // st�rsta talet p� hexadecimal form
  char name[4];
  name[0] = 'R';
  name[1] = 'i';
  name[2] = 'c';
  name[3] = 'k';
  cout << "Hello " << name << endl;
  return 0;
}
