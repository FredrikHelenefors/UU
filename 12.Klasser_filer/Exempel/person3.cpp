#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person3.cpp
// Med str�mvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att anv�nda.
// M�nga utskrifter efter varandra.
// Nu med open -close.

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
  // Skapa en array med personer.
  const int MAX = 5;

  Person pers[MAX] = {Person("Kalle Anka", 39),
		      Person("Kajsa Anka", 35),
		      Person("Mimmi Pigg", 25),
		      Person("Musse Pigg", 24),
		      Person("Sp�ket Laban", 3)};
    
  cout << "Vilken fil skall vi skriva ut p�?" << endl;
  string filnamnet;
  getline(cin, filnamnet);

  ofstream utfilen;
  utfilen.open ( filnamnet.c_str() );

  for ( int i = 0; i < MAX; i++ )
    pers[i].skriv( utfilen );

  utfilen.close(); // Beh�vs ej, st�ngs automatiskt vid
                   // programmets slut...
                 // Men bra ha denna vana :-)
  return 0;
}

/*
K�rningsexempel:

Vilken fil skall vi skriva ut p�?
d.txt

Inneh�llet i "d.txt" �r:
Personen Kalle Anka med �lder 39
Personen Kajsa Anka med �lder 35
Personen Kajsa Anka med �lder 35
Personen Mimmi Pigg med �lder 25
Personen Musse Pigg med �lder 24
Personen Sp�ket Laban med �lder 3


*/
