#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person5.cpp
// Med str�mvariabel (filvariabel) som parameter blir
// det lite mer flexibelt att anv�nda.
// M�nga utskrifter efter varandra.
// Nu med open -close.
// �ndra ofstream till ostream s� kan man
// anropa med str�m av typen ofstream eller
// cout!
// Nu med inl�sning p� generellt s�tt,
// ibland med cin, ibland fr�n fil!

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens �lder

public:
  Person ();
  Person ( string n, int a );
  void skriv( ostream &fout );
  void las( istream &fin ); 
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
void Person:: skriv( ostream &fout )
{
  // Filen f�rv�ntas vara �ppnad i anropande
  // programmet, h�r=main.

  fout << "Personen " << namn 
       << " med �lder " << alder << endl;
}
//----------------------------------------
void Person:: las( istream &fin )
{
  // Namn (f�r- och efternamn) p� en rad
  // �lder p� n�sta rad.

  getline( fin, namn );
  fin >> alder;
  fin.get();   // bort med returtecknet...
} 

//----------------------------------------
int main()
{
  // Skapa en array med personer.
  const int MAX = 5;

  Person pers[MAX];

  cout << "Ge " << MAX << " st personer "
       << "(namn och �lder p� olika trader)" << endl;


  ifstream indata("indatanamn.txt");

  // Testa med inl�sning fr�n tangentbord
  // eller fil genom att kommentera bort den ena. 

  for ( int i = 0; i < MAX; i++ )
    {
    //    pers[i].las( cin );         
    pers[i].las( indata );
    }
  
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

Ge 5 st personer (namn och �lder p� olika trader)
Nisse Anka
23
Olle Korp
34
Allan J�nsson
21
Stina Salomonsson
45
Oskar Oskarsson
67
Vilken fil skall vi skriva ut p�?
f.txt
Personen Nisse Anka med �lder 23
Personen Olle Korp med �lder 34
Personen Allan J�nsson med �lder 21
Personen Stina Salomonsson med �lder 45
Personen Oskar Oskarsson med �lder 67


Inneh�llet i "f.txt" �r:
...


*/
