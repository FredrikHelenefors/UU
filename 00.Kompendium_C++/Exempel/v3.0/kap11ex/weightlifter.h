// Filnamn : .../weightlifter.h

#ifndef __WEIGHTLIFTER__
#define __WEIGHTLIFTER__

#include <string>
#include "sportsman.h"
using namespace std;

class weightlifter : public sportsman {
 public:
  weightlifter();            // Standardkonstruktor
  weightlifter( string fn, string ln,
		string br, int nfp, int w );
                             // �verlagrad konstruktor
  ~weightlifter();           // Destruktor

  void report();             // Skriver data p� sk�rmen
  void input();              // Tar in data fr�n anv�ndaren
  int getWeight();           // Selektor
  void setWeight( int w );   // S�tt vikt

 protected:
  int weight;                // Vikt som kan lyftas i b�nkpress
};
#endif
