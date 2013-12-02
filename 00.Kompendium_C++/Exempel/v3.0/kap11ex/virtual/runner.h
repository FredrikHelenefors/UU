// Filnamn : .../virtual/runner.h
#ifndef __RUNNER__
#define __RUNNER__

#include <string>
#include "sportsman.h"
using namespace std;

class runner : public sportsman {
 public:
  runner();                  // Standardkonstruktor
  runner( string fn, string ln,
	  string br, int nfp, double ci );
                             // �verlagrad konstruktor
  ~runner();                 // Destruktor

  void report();             // Skriver data p� sk�rmen
  void input();              // Tar in data fr�n anv�ndaren
  double getConditionIndex();// Selektor
  void setConditionIndex( double ci );// S�tt konditionsindex

 protected:
  double conditionIndex;     // En l�pares syreupptagningsf�rm�ga
};
#endif
