#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// person0.cpp
// Med filnamn som parameter.

class Person 
{
private:
  string namn;     // personens namn
  int alder;       // personens �lder

public:
  Person ();
  Person ( string n, int a );
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
int main()
{
  Person p("Kalle Anka", 39);
  cout << "Vilken fil skall vi skriva ut p�?" << endl;
  string filnamnet;
  getline(cin, filnamnet);
  p.skriv( filnamnet );

  return 0;
}

/*
K�rningsexempel:

Vilken fil skall vi skriva ut p�?
a.txt

Inneh�llet i "a.txt" �r:
Personen Kalle Anka med �lder 39

*/
