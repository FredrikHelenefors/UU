// Filnamn : .../virtual/sportsman.h

#ifndef __SPORT__
#define __SPORT__
#include <string>
#include "person.h"
using namespace std;

class sportsman : public person {
 public:
  sportsman();               // Standardkonstruktor
  sportsman( string fn, string ln,
	     string br, int nfp );
                             // �verlagrad konstruktor
  ~sportsman();              // Destruktor

  void report();             // Skriver data p� sk�rmen
  void input();              // Tar in data fr�n anv�ndaren
  void firstPrize();         // R�kna upp antal f�rstapris

  // Selektorer
  string getBranch();
  int getNrFirstPrize();

 protected:
  string branch;             // Idrottsgren
  int nrFirstPrize;          // Antal f�rstapris
};
#endif
