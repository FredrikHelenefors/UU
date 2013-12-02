#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// testabildaeck.cpp

//--- Klassen daeck representerar ett bild�ck.---

const double MAXdjup = 20.00; // 20 mm

class daeck
{
private:
  double djup;        // M�nsterdjup = antal mm gummi.

public:
  daeck();
  daeck( double indjup );
  double haemta_djup();
  int slitage( double slitdjup ); // Slit p� d�cken
                                  // om det g�r.
  void skriv();
};

int main()
{
  // Skapa n�gra bild�ck och testa lite:
  cout << "Testa lite med d�cksklassen:" << endl;

  daeck fram( 20.0 ), bak( 30.0 ); // 20mm resp. 30mm gummi.
  fram.skriv();
  bak.skriv();

  cout << endl;
  cout << "Nu sliter vi lite p� dem..." << endl;

  fram.slitage( 1.5 );
  bak.slitage( 2.5 );

  fram.skriv();
  bak.skriv();
  cout << endl;

  return 0;
}  

//---Implementation av d�ckmetoder.---

//---Konstruktorer:

daeck::daeck()
: djup(MAXdjup)
{}

daeck::daeck( double indjup )
: djup(indjup)
{}

//---Selektorer: 

double daeck::haemta_djup()
{
  return djup;
}

//---Andra metoder:

int daeck::slitage( double slitdjup )
{
  // Slit ned "slitdjup" mycket av
  // gummit (om det g�r).
  // Returnera 1 om allt gummi slut,
  // annars 0.

  int slutgummi = 0;

  if ( djup - slitdjup < 0 )
    {
      djup = 0;
      slutgummi = 1;
    }
  else
    djup -= slitdjup;

  return slutgummi;
}

void daeck::skriv()
{
  cout.setf( ios::fixed );
  cout << " d�ck = " << setprecision(1) << djup;
}
/* K�rningsexempel:

Testa lite med d�cksklassen:
 d�ck = 20.0 d�ck = 30.0
Nu sliter vi lite p� dem...
 d�ck = 18.5 d�ck = 27.5

 */
