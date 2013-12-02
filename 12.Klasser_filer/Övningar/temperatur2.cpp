#include <iostream>
#include <string>
using namespace std;

// Uppgift 2: temperatur2.cpp

// Deklaration av klassen:

class  temperatur
{
private:
  double grader;        // gradtal
  string typ;           // "Celsius" eller "Fahrenheit".

public:
  temperatur();            // default-konstruktor
  temperatur( double t, string typen ); // �verlagrad konstruktor 
  void lasin();            // inl�sning av grader
  void skriv();            // utskrift av grader
  double haemta_grader();  // selektor: returnerar grader
  string haemta_typ();     // selektor, returnerar typ.
  double skillnad( temperatur t ); // skillnaden mellan 2 temperaturer
  double fahrenheit();             // returnerar grader i Fahrenheit
  void rapport( int nedre, int oevre ); // skriver "rapport"
};
//------------------------------------------------------
// Huvudprogram:

int main()
{
  temperatur t1, t2;
  temperatur t3(35,"Celsius"), t4(100,"Fahrenheit");
  t2.lasin();

  t1.skriv();
  t2.skriv();
  t3.skriv();
  t4.skriv();
  t3.rapport(5, 15);
  t4.rapport(75, 90);

  double temp = t1.haemta_grader();
  string grad_enhet = t1.haemta_typ();
  cout << "Default-objekt: " << temp 
       << " " << grad_enhet << endl;

  double f = t1.fahrenheit();
  cout << temp 
       << " grader Celsius motsvaras av "
       << f << " grader Fahrenheit." << endl;
  
  double d = t2.skillnad(t3);
  cout << "Skillnaden mellan " << t2.haemta_grader()
       << " och " << t3.haemta_grader()
       << " = " << d << endl;

  return 0;
}

//------------------------------------------------------
// Implementation av klassens metoder:

// ---Konstruktorer---

temperatur::temperatur() // default-konstruktor
{ 
  grader = 28;  
  typ = "Celsius";
}

temperatur::temperatur( double t, string typen )
{ 
  grader = t;
  typ = typen;
}

// ---Medlemsfunktioner--- 

void temperatur::lasin()
{
  cout << "Ange grader: ";
  cin >> grader;
  cin.get();  //L�s f�rbi returntecknet.

  cout << "Ange typen: ";
  getline( cin, typ );
}

void temperatur::skriv()
{ 
  cout << "Temperaturen �r "<< grader << " grader "
       << typ << "." << endl;
}
  
double temperatur::haemta_grader()
{ 
  return grader;
}

string temperatur::haemta_typ()
{
  return typ;
}

double temperatur::skillnad( temperatur t )
{ 
  // Kolla att samma enheter m�ts!
  if ( typ == t.typ )
    return (grader - t.grader);
  else
    {
      cout << "Olika enheter!!!" << endl;
      return -99999;
    }
}

double temperatur::fahrenheit()
{
  if ( typ == "Celsius" )        // Om Celsius, s� konvertera.
    return ( 32 + 1.8*grader );
  else
    return grader;             // Annars, l�t vara.
}
 
void temperatur::rapport( int nedre, int oevre )
{ 
  string s1 = "Oh! Vad varmt det �r idag.";
  string s2 = "Oh! Vad kallt det �r idag.";
  string s3 = "Det �r lagom varmt idag.";
	
  if ( grader < nedre ) 
    cout << s2;
  else if ( grader < oevre ) 
    cout << s3;
  else 
    cout << s1;

  cout << endl;
}
     

/* K�rningsresultat:
Ange grader: 25
Ange typen: Celsius
Temperaturen �r 28 grader Celsius.
Temperaturen �r 25 grader Celsius.
Temperaturen �r 35 grader Celsius.
Temperaturen �r 100 grader Fahrenheit.
Oh! Vad varmt det �r idag.
Oh! Vad varmt det �r idag.
Default-objekt: 28 Celsius
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Skillnaden mellan 25 och 35 = -10


Ange grader: 99
Ange typen: Fahrenheit
Temperaturen �r 28 grader Celsius.
Temperaturen �r 99 grader Fahrenheit.
Temperaturen �r 35 grader Celsius.
Temperaturen �r 100 grader Fahrenheit.
Oh! Vad varmt det �r idag.
Oh! Vad varmt det �r idag.
Default-objekt: 28 Celsius
28 grader Celsius motsvaras av 82.4 grader Fahrenheit.
Olika enheter!!!
Skillnaden mellan 99 och 35 = -99999
 */
