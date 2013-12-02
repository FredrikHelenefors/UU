#include <iostream>
#include <string>
using namespace std;

// loket.cpp
// Detta �r exempel p� b�de aggregat och lista.
// Vi har ett t�g som best�r av ett lok samt en 
// dynamisk array av vagnar.
// Man skall kunna ta koppla p� och koppla bort
// vagnar i t�get t.ex.

class Vagn
{
private:
  int idnr;      // vagnens id-nummer. 1:a siffran anger vagntyp:
                 // 1=klass1, 2=klass2, 3=godsvagn, 4=restaurangvagn
  int vikt;      // vagnens vikt

public:
  Vagn();               // standardkonstruktor
  Vagn(int id, int v);  // �verlagrad konstruktor
  int returnvikt();     // returnerar en vagns vikt
  int id();             // returnerar idnr
  void skriv();         // skriver ut vagndata
};

class Taag
{
private:
  string lokNamn; // Lokets namn
  int dragvikt;   // Maximal vikt som loket klarar av att dra
  Vagn *vagnar;   // Vagnar (dynamisk array).
  int antal;      // antalet vagnar

public:
  Taag();                  // standardkonstruktor
  Taag( string n, int dv); // �verlagrad konstruktor. Ge loknamn.
  ~Taag();                 // destruktor
  int kopplavagn(Vagn v);  // kopplar in en vagn i t�get 
  int totalvagnvikt();     // returnerar totala vagnsvikten i t�get
  void tabortvagn(int id );// ta bort vagn med idnr=id ur t�get. 
  void skriv();            // skriver ut Taagdata
};

int main( void )
{
  Taag SJ1("RS2000 nr.12", 120000); // skapa ett Taag
  Vagn Persv1(1001, 25000);         // skapa en personvagn, klass 1.
  Vagn Persv2(2004, 250000);        // skapa personvagn, klass 2
  Vagn Restv(4002,  15000);         // skapa en restaurangvagn
  Vagn Godsv(3003,  70000);         // skapa en godsvagn

  // Koppla vagnar som Taaget orkar med.

  if ( !SJ1.kopplavagn(Godsv) )  
    { cout << "Kopplar ej "; Godsv.skriv(); }
  if ( !SJ1.kopplavagn(Persv1) )  
    { cout << "Kopplar ej "; Persv1.skriv(); }
  if ( SJ1.kopplavagn(Persv2) )  
    { cout << "Kopplar ej "; Persv2.skriv(); }
  if ( SJ1.kopplavagn(Restv) )  
    { cout << "Kopplar ej "; Restv.skriv(); }

  cout << "Nu har t�get totalvagnvikt = "
       << SJ1.totalvagnvikt() << endl; 

  SJ1.skriv();

  int vagnsnummer;
  cout << "Hej! Vilken vagn skall bort?" << endl;
  cin >> vagnsnummer;

  SJ1.tabortvagn( vagnsnummer );
  SJ1.skriv();

  return 0;
}
//----------------------------------
Vagn::Vagn()   // konstruktor
  : vikt(0), idnr(0)
{}

Vagn::Vagn(int id, int v)  // �verlagrad konstruktor
  : vikt(v), idnr(id)
{}

int Vagn::returnvikt()
{
  return vikt;
}

int Vagn::id()             // returnerar idnr
{
  return idnr;
}

void Vagn::skriv()
{
  int typ = idnr/1000;    //ex: 4002/1000 = 4

  if ( typ == 1 )
    cout << "Personvagn klass 1 ";
  else if ( typ == 2 )
    cout << "Personvagn klass 2 ";
  else if ( typ == 3 )
    cout << "Godsvagn ";
  else if ( typ == 4 )
    cout << "Restaurangvagn ";

  cout << "med idnr = " << idnr 
       << " och vikt = " << vikt << endl;
}
//-------------------------------------------
Taag::Taag()   // konstruktor
  : lokNamn("Inget"), dragvikt(0.0), vagnar(0), antal(0)
{} 

Taag::Taag(string n, int dv)  // �verlagrad konstruktor
  : lokNamn(n), dragvikt(dv), vagnar(0), antal(0)
{}

Taag:: ~Taag()
{
  delete [] vagnar;
}

int Taag::kopplavagn(Vagn v)  
{
  int okayKoppla = 0;   // Antag man ej kan koppla vagnen.

  if ( v.returnvikt() + totalvagnvikt() < dragvikt )   
    {
      okayKoppla = 1;             // Ok, man kan koppla.

      Vagn *p = 0; 
      p = new Vagn[antal+1]; // Skapa array med antal+1 elem.

      for ( int i = 0; i < antal; i++ )  //Kopiera in de gamla
	{
	  p[i] = vagnar[i];
	}

      p[antal] = v;     // l�gg in vagnen sist i arrayen
      antal++;          // �ka antalet vagnar i t�get

      delete [] vagnar; // Avallokera minne.
      vagnar = p;       // S�tt array till nya arrayen.
    }
  return okayKoppla;
}

int Taag::totalvagnvikt()   // returnerar vikten av alla vagnar
{
  int i, totvikt = 0;
  for (i = 0; i < antal; i++)
    {
      totvikt += vagnar[i].returnvikt();
    }
  return  totvikt;
}

void Taag::skriv()
{

  cout << "Taagnamn = " << lokNamn << " med max dragvikt = " 
       << dragvikt << endl;

  cout << "F�ljande " << antal 
       << " st vagnar finns i t�get:" << endl;

  for ( int v = 0; v < antal; v++ )
    {
      vagnar[v].skriv();
    }
}
//----------------------------------
void Taag:: tabortvagn( int id )  
{
  // Leta reda p� vagn med idnr = id.
  // Plocka bort denna ur t�garrayen. 
  // Flytta upp resterande vagnar ett steg. Uppdatera antal.

  int i = 0;

  while ( i < antal && vagnar[i].id() != id ) i++;

  if ( i == antal )
      cout << "Vagnen finns ej!" << endl;
  else
    {      // i �r index f�r vagn som skall bort!
      Vagn *p = 0;            // Skapa tempor�r vagnarray.
      p = new Vagn[antal-1]; 

      int j;

      for ( j = 0; j < i; j++ ) // Kopiera f�r j<i
	p[j] = vagnar[j];

      for ( j = i; j < antal-1; j++ ) // Kopiera f�r j>i
	p[j] = vagnar[j+1];

      antal = antal-1;
      delete [] vagnar;
      vagnar = p;
    }
}
//----------------------------------
/*
K�rningsexempel:
Kopplar ej Restaurangvagn med idnr = 4002 och vikt = 15000
Nu har t�get totalvagnvikt = 110000
Taagnamn = RS2000 nr.12 med max dragvikt = 120000
F�ljande 3 st vagnar finns i t�get:
Godsvagn med idnr = 3003 och vikt = 70000
Personvagn klass 1 med idnr = 1001 och vikt = 25000
Restaurangvagn med idnr = 4002 och vikt = 15000
Hej! Vilken vagn skall bort?
1
Vagnen finns ej!
Taagnamn = RS2000 nr.12 med max dragvikt = 120000
F�ljande 3 st vagnar finns i t�get:
Godsvagn med idnr = 3003 och vikt = 70000
Personvagn klass 1 med idnr = 1001 och vikt = 25000
Restaurangvagn med idnr = 4002 och vikt = 15000

 */
