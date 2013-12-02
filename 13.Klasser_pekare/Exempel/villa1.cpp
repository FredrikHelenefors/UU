#include <iostream>
#include <string>
using namespace std;

class Villa 
{
private:
  string adress;
  int pris;

public:
  Villa();
  Villa( string inAdress, int inPris );
  void skriv();
};

int main()
{
  const int MAX=100;

  Villa *villor[MAX];   // Array av pekare till 
                        // m�nga Villa-objekt.

  for ( int i = 0; i < MAX; i++ ) 
    {
      villor[i] = 0;   // Bra att nollst�lla pekararrayen.
    }

  int antal;         // Antal villor idag.

  do                 // Kontroll p� inl�sningen
    {
      cout << "Hur m�nga villor?" << endl;
      cin >> antal;
    } while( antal <= 0 || antal > MAX);

  // Skapa lite villor, dvs simulering av att
  // objekt kommer in till f�rs�ljning.

  villor[0] = new Villa("Ekv�gen 123", 1000000); 
  villor[1] = new Villa("Alv�gen 12", 1200000); 
  villor[antal-1] = new Villa("H�velv�gen 7", 130000);

  // Bums s�ljer vi Ekv�gen.
  cout << "---Nu s�ljer vi f�rsta villan" << endl;
 
  delete villor[0];     
  villor[0] = 0;     

  // Skriv ut de villor som finns kvar till
  // f�rs�ljning.

  for ( int i = 0; i < antal; i++ ) 
    {
      if ( villor[i] != 0 ) 
	{
	  cout << "---Objekt nr " << i+1 << " ";
	  villor[i]->skriv(); cout << endl;
	}
    }
  
  // En konkurrerande m�klarfirma
  // k�per upp alla villaobjekt!

  for ( int i = 0; i < antal; i++ ) 
    {
      // Beh�ver ej kolla vilka pekare 
      // som �r NULL. Man f�r g�ra delete 
      // p� noll-pekare, fast inget h�nder...,
      // men det f�renklar programmeringen.

      delete villor[i]; 
    }

  return 0;
}

Villa::Villa()
  : adress("Ingen"), pris(0)
{}

Villa::Villa( string inAdress, int inPris )
  : adress(inAdress), pris(inPris)
{}


void Villa::skriv()
{
  cout << " Adress = " << adress 
       << ", pris = "  <<  pris;
}


/*K�rningsexempel:

Hur m�nga villor?
300
Hur m�nga villor?
-4
Hur m�nga villor?
8
---Nu s�ljer vi f�rsta villan
---Objekt nr 2  Adress = Alv�gen 12, pris = 1200000
---Objekt nr 8  Adress = H�velv�gen 7, pris = 130000
*/
