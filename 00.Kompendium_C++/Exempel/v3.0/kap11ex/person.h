// Filnamn : .../person.h
#ifndef __person__
#define __person__

#include<string>
using namespace std;

class person {
 public:
  person();               // defaultkonstruktor
  person(string fn, string ln); // �verlagrad konstruktor
  ~person();              // destruktor

  void report();          // Skriv all
  void writeName();       // Skriv namnet
  void input();           // L�s in person

 protected:
  string fname; 
  string lname; 
};
#endif
