#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
// Aggregatexempel.

// Icke-klassberoende funktioner...

double slump( double tal );

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

//--- Klassen bil.---


class bil
{
private:
  string typ;            // Biltyp, t.ex. "Volvo"
  daeck hf, vf, hb, vb;  // Fyra st hjul.

public:
  bil();                           // Konstruktorer.4st.
  bil( string nytyp );
  bil( double nyhf, double nyvf,
       double nyhb, double nyvb );
  bil( daeck inhf, daeck invf,
       daeck inhb, daeck invb );
  string haemta_typ();           // Vilken typ?
  int gaspaadrag( double d );    // G�r gasp�drag.
  void skriv();                  // Skriv bilinfo.
};

int main()
{
  int froe;
  froe = long( time( NULL ) );
  // Starta slumptalsgeneratorn. (SUN)
  //  srand( froe );   // PC

  srand48( froe ); 

  bil Volvo( "Volvo" );
  bil Saab( "Saab" );
 
  Volvo.skriv();  cout << endl;
  Saab.skriv(); cout << endl;

  int antVolvo = 0;
  int antSaab = 0;

  cout << "\n---Nu startar t�vlingen!" << endl << endl;

  // T�vlingen slutar d� n�gon av dem har slut p� alla d�ck!

  do
    {
      antVolvo = Volvo.gaspaadrag( slump(4) );
      antSaab  = Saab.gaspaadrag( slump(4) );

      Volvo.skriv(); cout << endl;
      Saab.skriv(); cout << endl;

      cout << "Liten pause innan n�sta gasp�drag... (tryck return)." 
	   << endl;
      cin.get();
    } while ( antVolvo < 4 && antSaab < 4 );

  cout << "\n-----Slutresultat: " << endl;
  cout << "Vinnare �r den som har d�ck kvar:" << endl;

  if ( antVolvo + antSaab == 8 ) 
    {
      cout << "Ingen vinnare, b�da har slut p� gummi" 
	   << endl;
    }
  else if ( antVolvo == 4 )
    {
      Saab.skriv(); cout << endl;
    }
  else if ( antSaab == 4 )
    {
      Volvo.skriv(); cout << endl;
    }

  cout << "Tack och hej!" << endl;

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

//---Implementation av bilmetoder.---

bil::bil()
   : typ("Ingen") 
{
  // H�r kommer standardkonstruktorn f�r daeck
  // att anropas automatiskt fyra ggr (hf,vf,hb,vb).
}

bil::bil( string nytyp )
   : typ( nytyp )
{}

bil::bil( double nyhf, double nyvf, 
          double nyhb, double nyvb )
  : hf(daeck(nyhf)), vf(daeck(nyvf)),
    hb(daeck(nyhb)), vb(daeck(nyvb)), typ("--")
{}

bil::bil( daeck inhf, daeck invf,
          daeck inhb, daeck invb )
  //  : hf(inhf), vf(invf), hb(inhb), vb(invb)
{
  hf = inhf; vf = invf;
  hb = inhb; vb = invb;
}

string bil::haemta_typ()
{
  return typ;
}

int bil::gaspaadrag( double d )
{
  // D�cken slits vid varje gasp�drag som
  // f�raren g�r.
  // Parameter: d = d�ckslitage-konstant
  // som beror p� hur aggresivt f�raren gasar.
  // Antag att d�cken i varje d�ckpar 
  // (h�ger/v�nster) slits lika mycket.

  // Antag vidare att vi har en bakhjulsdriven bil.
  // Dvs det sliter mer p� bakhjulen �n framhjulen
  // d� man gasar.
  // Konstanterna "framslit" och "bakslit" har 
  // ber�knats fr�n m�tningar vid rallyt�vlingar.

  const double framslit = 3.0;  
  const double bakslit  = 3.5;   // Ty bakhjulsdriven.

  double fram, bak;
  fram = d*framslit;   // Enligt rallyber�kningar.
  bak  = d*bakslit;

  // Kom ih�g: daeck-klassens metod "slitage" returnerar
  // 1 om d�cket har slut p� gummi, annars 0.

  int sum; // sum = antal d�ck som �r helt utslitna p� bilen

  sum =  vf.slitage(fram) + hf.slitage(fram) +
         vb.slitage(bak) +  hb.slitage(bak);
  return sum;
}




 void bil::skriv()
 {
   cout.setf( ios::fixed ); // F�r lite snyggare utskrifter d�...

   cout << "Bil av typen = " << typ << "\t har ";
   hf.skriv(); // Skriver bara ut ena i fram och ena i bak.
   hb.skriv(); 
}

//--------------Vanliga funktioner----------------------

double slump( double tal )
{
  // F�r att f� tal i intervallet 0-tal p� SUN:
  // return drand48()*tal;
  // F�r att f� tal i intervallet 0-tal p� PC:
  // return tal*rand()/double(RAND_MAX);

  return drand48()*tal;
}

/* K�rningsexempel:
Bil av typen = Volvo     har  d�ck = 20.0 d�ck = 20.0
Bil av typen = Saab      har  d�ck = 20.0 d�ck = 20.0

---Nu startar t�vlingen!

Bil av typen = Volvo     har  d�ck = 11.4 d�ck = 9.9
Bil av typen = Saab      har  d�ck = 12.5 d�ck = 11.2
Liten pause innan n�sta gasp�drag... (tryck return).

Bil av typen = Volvo     har  d�ck = 0.6 d�ck = 0.0
Bil av typen = Saab      har  d�ck = 8.3 d�ck = 6.4
Liten pause innan n�sta gasp�drag... (tryck return).

Bil av typen = Volvo     har  d�ck = 0.0 d�ck = 0.0
Bil av typen = Saab      har  d�ck = 1.7 d�ck = 0.0
Liten pause innan n�sta gasp�drag... (tryck return).

-----Slutresultat: 
Vinnare �r den som har d�ck kvar:
Bil av typen = Saab      har  d�ck = 1.7 d�ck = 0.0
Tack och hej!
 */
