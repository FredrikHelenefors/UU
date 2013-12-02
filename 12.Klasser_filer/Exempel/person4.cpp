#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person4.cpp
// Med str�mvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att anv�nda.
// M�nga utskrifter efter varandra.
// Nu med open -close.
// �ndra ofstream till ostream s� kan man
// anropa med str�m av typen ofstream eller
// cout!

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens �lder

public:
  Person ();
  Person ( string n, int a );
  void skriv( ostream &fout );
  void skriv( string filnamn );
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
void Person:: skriv( ostream &fout )
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

  // Skriva ut p� fil ibland och cout ibland, t.ex.
  // b�de och!

  for ( int i = 0; i < MAX; i++ )
    pers[i].skriv( utfilen );

  utfilen.close(); // Beh�vs ej, st�ngs automatiskt vid
                   // programmets slut...
                 // Men bra ha denna vana :-)

  for ( int i = 0; i < MAX; i++ )
    pers[i].skriv( cout );

  return 0;
}

/*
K�rningsexempel:

Vilken fil skall vi skriva ut p�?
e.txt
Personen Kalle Anka med �lder 39
Personen Kajsa Anka med �lder 35
Personen Mimmi Pigg med �lder 25
Personen Musse Pigg med �lder 24
Personen Sp�ket Laban med �lder 3

Inneh�llet i "e.txt" �r:
Personen Kalle Anka med �lder 39
Personen Kajsa Anka med �lder 35
Personen Kajsa Anka med �lder 35
Personen Mimmi Pigg med �lder 25
Personen Musse Pigg med �lder 24
Personen Sp�ket Laban med �lder 3


*/
