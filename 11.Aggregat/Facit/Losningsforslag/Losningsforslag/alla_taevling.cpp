/* 
Filnamn: alla_start.cpp

All kod i en enda fil h�r.
1. Deklaration av vanliga funktioner, tex slump
2. Klassdeklarationer
3. Main
4. Funktionsdefinition (slump)
5. Klassmetoddefinitioner
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//--------------------------------------------------
// Vanliga funktioner:
double slump( double tal );
//--------------------------------------------------
// Klassdeklarationer i r�tt ordning, dvs bil kommer
// sist, eftersom bilen har objektattribut ur klass daeck
// och bensintank.

class bensintank
{
private:
  double liter;      // Antal liter bensin i tanken.
  double volym;      // Max antal liter, dvs tankens "volym".
public:
  bensintank();
  bensintank( double lit );       // Full tank (volym=liter).
  bensintank( double lit, double vol );
  double haemta_liter();
  void foerbruka( double & lit ); // Bensinen minskar om det g�r.
  void skriv();    
};

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
  void skriv();
};

const int framhjulsdriven = 1;
const int bakhjulsdriven = 0;

class bil
{
private:
  string typ;            // Biltyp, t.ex. "Volvo"
  int framhjuls;         // Framhjuls-bakhjulsdriven?
  bensintank tank;       // Bensintanken.
  daeck hf, vf, hb, vb;  // Fyra st hjul.
  double xpos;           // Xposition, 0.0 = startlinjen.

public:
  bil();                                // Konstruktorer.
  bil( string nytyp,  int nyfram );
  string haemta_typ();                  // Vilken typ?
  int tom();                            // 1=tom tank, 0 annars. 
  double haemta_x ();                   // Var �r bilen?
  void gaspaadrag( double d, double b); // G�r gasp�drag.
  void skriv();                         // Skriv bilinfo.
};

//--------------------------------------------------
// MAIN:
int main()
{
  int froe;
  froe = long( time( NULL ) );
  srand48( froe ); // Starta slumptalsgeneratorn. (SUN)
  //  srand( froe );   // PC

  bil Volvo( "Volvo", framhjulsdriven );
  bil Saab( "Saab", bakhjulsdriven );
 
  Volvo.skriv();  cout << endl;
  Saab.skriv(); cout << endl;
  int alla_har_slut;
  cout << "\n---Nu startar t�vlingen!" << endl << endl;

  do
    {
      Volvo.gaspaadrag( slump(2), slump(20.0) );
      Saab.gaspaadrag( slump(2), slump(20.0) );

      Volvo.skriv(); cout << endl;
      Saab.skriv(); cout << endl;

      cout << "Liten pause innan n�sta gasp�drag... (tryck return)." 
	   << endl;
      cin.get();

      alla_har_slut = Volvo.tom() + Saab.tom();
    } while ( alla_har_slut < 2 );

  cout << "\n-----Slutresultat: " << endl;
  cout << "Vinnare:" << endl;

  if ( Volvo.haemta_x() > Saab.haemta_x() )
    Volvo.skriv();
  else
    Saab.skriv(); 

  cout << endl;
  cout << "Tack och hej!" << endl;

  return 0;
}
//--------------------------------------------------
// Definition (implementation) av vanliga funktioner:

double slump( double tal )
{
  // F�r att f� tal i intervallet 0-tal p� SUN:
  // return drand48()*tal;
  // F�r att f� tal i intervallet 0-tal p� PC:
  // return tal*rand()/double(RAND_MAX);

  return drand48()*tal;
}
//--------------------------------------------------
// Definition (implementation) av klassernas metoder
//--------------------------------------------------
//--- Konstruktorer:
bensintank::bensintank()
  : liter(0), volym(0)
{}
bensintank::bensintank( double lit )
  : liter(lit), volym(lit)
{}
bensintank::bensintank( double lit, double vol )
  : liter(lit), volym(vol)
{}
//---Selektorer:
double bensintank::haemta_liter()
{
  return liter;
}
//---Andra metoder:
void bensintank::foerbruka( double & lit )
{
  // Vi vill f�rbruka "lit" antal liter.
  // Om detta ej g�r, s� f�rbruka s� mycket som m�jligt.
  // �ndra i s� fall v�rdet p� "lit", ty referensparameter.
 
  if ( lit > liter )
    {
      cout << "Soppatorsk! Bilen slukar " << liter 
	   << " liter fast du ville " << lit << " liter." << endl;
      lit = liter;  // Tanka s� mycket det g�r.
      liter = 0;    // Tom tank;
    }
  else
    liter -= lit;
}
void bensintank::skriv()
{
  cout.setf( ios::fixed );
  cout << setw(5) << setprecision(1) << liter << " liter ";
}  
//--------------------------------------------------
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
//--------------------------------------------------
bil::bil()
  : framhjuls(framhjulsdriven), // Antag standard �r framhjulsdrift.
  xpos(0.0), typ("Ingen")
{
  // H�r kommer standardkonstruktorerna f�r bensintank
  // hf, vf, hb, vb att anropas automatiskt.
}
bil::bil( string nytyp, int nyfram )
  : tank( bensintank(100.00) ), framhjuls( nyfram ),
    xpos(0.0), typ(nytyp)
{}
string bil::haemta_typ()
{
  return typ;
}
double bil::haemta_x()
{
  return xpos;
}
void bil::gaspaadrag( double d, double b )
{
  // D�cken slits och bensin g�r �t vid en rivstart.
  //
  // Parametrar: d = d�ckslitage, b = bensinminskning.
  // Beroende p� om bilen �r framhjuls- eller bakhjulsdriven, s� slits
  // den p� lite olika s�tt...
  //
  // Dessutom, man kan k�ra p� helslitna d�ck, men d� g�r det �t
  // mycket mer bensin!
  //
  // Antag att d�cken i varje d�ckpar (h�ger/v�nster) slits lika mycket.
  const double framslit = 2.0;
  const double bakslit = 2.5;
  const double framliter = 1.75;
  const double bakliter = 1.5;
  double fram, bak, lit;

  if ( framhjuls )
    {
      fram = d*framslit;
      bak  = d;
      lit  = b*framliter;
    }
  else
    {
      fram = d;
      bak  = d*bakslit;
      lit  = b*bakliter;
    }

  double daeckminus = 2*fram + 2*bak;
  double hur_mycket_soppa = tank.haemta_liter();  // init=innan.
  int sum; //sum = antal d�ck som �r helt utslitna

  if ( hur_mycket_soppa > 0 )
    {
      sum =  vf.slitage(fram) + hf.slitage(fram) +
             vb.slitage(bak) +  hb.slitage(bak);

      double soppaminus = (1 + sum)*lit;    //kolla skillnad.

      tank.foerbruka( soppaminus );

      // Det kan h�nda att "hur_mycket_soppa" blir negativ om man
      // f�r slut p� soppa.
      // Dvs soppamnius skall vara ett mindre tal ibland...

      hur_mycket_soppa -= soppaminus;   
      xpos += soppaminus + 10*daeckminus;
    }
}

int bil::tom()
{
  // Om tanken tom, s� returnera 0, annars 1.
  // Eftersom "exakt nolla" ej finns som flyttal s�
  // kan det vara bra att kolla om absolutbeloppet av liter �r litet tal
  // (n�stan tomt i tanken), dvs funktionen "fabs" i cmath anv�nds.

  if ( fabs( tank.haemta_liter() ) < 1.0e-6 ) 
    return 1;
   else
     return 0;
}

void bil::skriv()
{
  cout.setf( ios::fixed ); // F�r lite snyggare utskrifter d�...
  if ( framhjuls )
    cout << "Framhjuls ";
  else
    cout << "Bakhjuls  ";
  cout << " av typen = " << typ << "\t har ";
  tank.skriv();
  hf.skriv(); // Skriver bara ut ena i fram och ena i bak.
  hb.skriv(); 
  cout << " xpos = " << xpos;
}
//--------------------------------------------------
/* K�rningsresultat:

Framhjuls  av typen = Volvo      har 100.0 liter  d�ck = 20.0 d�ck = 20.0 xpos = 0.0
Bakhjuls   av typen = Saab       har 100.0 liter  d�ck = 20.0 d�ck = 20.0 xpos = 0.0

---Nu startar t�vlingen!

Framhjuls  av typen = Volvo      har  79.6 liter  d�ck = 19.3 d�ck = 19.6 xpos = 42.4
Bakhjuls   av typen = Saab       har  84.9 liter  d�ck = 19.4 d�ck = 18.5 xpos = 57.8
Liten pause innan n�sta gasp�drag... (tryck return).

Framhjuls  av typen = Volvo      har  51.6 liter  d�ck = 17.2 d�ck = 18.6 xpos = 133.6
Bakhjuls   av typen = Saab       har  71.8 liter  d�ck = 18.9 d�ck = 17.4 xpos = 101.9
Liten pause innan n�sta gasp�drag... (tryck return).

Framhjuls  av typen = Volvo      har  40.8 liter  d�ck = 13.7 d�ck = 16.9 xpos = 247.5
Bakhjuls   av typen = Saab       har  55.9 liter  d�ck = 17.8 d�ck = 14.5 xpos = 197.0
Liten pause innan n�sta gasp�drag... (tryck return).

Framhjuls  av typen = Volvo      har   5.9 liter  d�ck = 13.7 d�ck = 16.8 xpos = 284.5
Bakhjuls   av typen = Saab       har  53.8 liter  d�ck = 16.6 d�ck = 11.5 xpos = 283.3
Liten pause innan n�sta gasp�drag... (tryck return).

Framhjuls  av typen = Volvo      har   5.7 liter  d�ck = 10.0 d�ck = 15.0 xpos = 392.8
Bakhjuls   av typen = Saab       har  31.0 liter  d�ck = 15.5 d�ck = 8.8 xpos = 383.1
Liten pause innan n�sta gasp�drag... (tryck return).

Soppatorsk! Bilen slukar 5.7 liter fast du ville 13.5 liter.
Framhjuls  av typen = Volvo      har   0.0 liter  d�ck = 7.6 d�ck = 13.8 xpos = 471.2
Bakhjuls   av typen = Saab       har  12.4 liter  d�ck = 14.7 d�ck = 6.8 xpos = 458.0
Liten pause innan n�sta gasp�drag... (tryck return).

Framhjuls  av typen = Volvo      har   0.0 liter  d�ck = 7.6 d�ck = 13.8 xpos = 471.2
Bakhjuls   av typen = Saab       har   2.0 liter  d�ck = 14.4 d�ck = 6.0 xpos = 490.2
Liten pause innan n�sta gasp�drag... (tryck return).

Soppatorsk! Bilen slukar 2.0 liter fast du ville 11.5 liter.
Framhjuls  av typen = Volvo      har   0.0 liter  d�ck = 7.6 d�ck = 13.8 xpos = 471.2
Bakhjuls   av typen = Saab       har   0.0 liter  d�ck = 13.5 d�ck = 3.6 xpos = 557.9
Liten pause innan n�sta gasp�drag... (tryck return).


-----Slutresultat: 
Vinnare:
Bakhjuls   av typen = Saab       har   0.0 liter  d�ck = 13.5 d�ck = 3.6 xpos = 557.9
Tack och hej!


*/
