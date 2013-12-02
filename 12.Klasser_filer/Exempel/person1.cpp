#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person1.cpp
// Med str�mvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att anv�nda.

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens �lder

public:
  Person ();
  Person ( string n, int a );
  void skriv( string filnamn );
  void skriv( ofstream &fout );
};

//----------------------------------------
Person::Person()
{
  namn = "Inget";
  alder = 0;
}
//----------------------------------------
Person::Person( string n, int a ) 
{
  namn = n;
  alder = a;
}
//----------------------------------------
void Person::skriv( string filnamn )
{
  ofstream fout(filnamn.c_str());
  fout << "Personen " << namn 
       << " med �lder " << alder << endl;
}
//----------------------------------------
void Person:: skriv( ofstream &fout )
{
  // Filen f�rv�ntas vara �ppnad i anropande
  // programmet, h�r=main.

  fout << "Personen " << namn 
       << " med �lder " << alder << endl;
}
//----------------------------------------
int main()
{
  Person p("Kalle Anka", 39);
  cout << "Vilken fil skall vi skriva ut p�?" << endl;
  string filnamnet;
  getline(cin, filnamnet);

  ofstream utfilen( filnamnet.c_str() );
  p.skriv( utfilen );

  //
  p.skriv( filnamnet );

  return 0;
}

/*
K�rningsexempel:

Vilken fil skall vi skriva ut p�?
b.txt

Inneh�llet i "b.txt" �r:
Personen Kalle Anka med �lder 39

*/
