#include <iostream>
#include <string>
using namespace std;

// assoc1.cpp
// Med pekare i main.
// Detta �r ett exempel p� en env�gs association,
// en "en-till-en-association".
// Det finns en bilklass och en personklass.
// En person har en association till en bil,
// men en bil har ingen association till en person.
// 

class Bil 
{
private:
  string typ;

public:
  Bil();
  Bil( string inTyp );
  void skriv();
};

class Person 
{
private: 
  string namn;
  Bil *bil_p;      // pekare till bilobjekt

public:
  Person ( string inNamn );
  Person ( string inNamn, Bil *b );
  void skriv();
  void koepBil( Bil *b );
  void saeljBil();
  void saeljPrivat( Person &annan );
};
 
 
int main()
{
  Bil *b1_p, *b2_p, *b3_p;
  b1_p = new Bil("Lada"); 
  b2_p = new Bil("Rolls Royce");
  b3_p = new Bil("Volvo");

  Person p1("Kalle Anka", b1_p);
  Person p2("Joakim von Anka", b2_p);

  cout << "\n---F�ljande personer finns:" << endl;
  p1.skriv(); cout << endl;
  p2.skriv(); cout << endl;

  cout << "\n---F�ljande bilar finns:" << endl;
  b1_p->skriv(); cout << endl;
  b2_p->skriv(); cout << endl;
  b3_p->skriv(); cout << endl;

  cout << "\n---Kalle s�ljer sin bil till ngn." 
       << "\n---Kalle k�per bil Volvo." << endl;
  p1.saeljBil();
  p1.koepBil( b3_p );
  p1.skriv(); cout << endl;

  cout << "\n---Joakim s�ljer sin bil till Kalle." 
       << endl;
  p2.saeljPrivat( p1 );
  p1.skriv(); cout << endl;
  p2.skriv(); cout << endl;

  delete b1_p;  // G�r egentligen automatiskt
  delete b2_p;  // innan programslut, men i allafall...
  delete b3_p;
  return 0;
}

Bil:: Bil()
  : typ("Ingen")
{}

Bil::   Bil( string inTyp )
  : typ(inTyp)
{}

void Bil:: skriv()
{
  cout << typ;
}
  
Person:: Person( string inNamn )
  : namn(inNamn), bil_p(0)
{}

Person:: Person ( string inNamn, Bil *b ) 
  : namn(inNamn), bil_p(b) 
{}

void Person:: skriv()
{
  cout << namn;
  
  if ( bil_p ) 
    { 
      cout <<  " �ger "; bil_p->skriv(); 
    } 
  else
    cout << " �ger ingen bil." << endl;
}

void Person:: koepBil( Bil *b )  
{
  bil_p = b; 
}

void Person:: saeljBil() 
{ 
  bil_p = 0; 
}

void Person:: saeljPrivat( Person &annan )
{
  // referensparameter, eftersom
  // objektet �ndras.

  annan.bil_p = bil_p; // annan pekar p� samma bil
  bil_p = 0;           // aktuell person blir utan bil
}
/*
K�rningsexempel:



---F�ljande personer finns:
Kalle Anka �ger Lada
Joakim von Anka �ger Rolls Royce

---F�ljande bilar finns:
Lada
Rolls Royce
Volvo

---Kalle s�ljer sin bil till ngn.
---Kalle k�per bil Volvo.
Kalle Anka �ger Volvo

---Joakim s�ljer sin bil till Kalle.
Kalle Anka �ger Rolls Royce
Joakim von Anka �ger ingen bil.
*/


