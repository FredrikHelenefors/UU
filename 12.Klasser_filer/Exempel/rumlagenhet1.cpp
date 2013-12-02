#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// lagenhetrum1.cpp
// Rum har nu en egen inl�sningsmetod.
// Rum har nu en egen utskriftsmetod.

const int MAXANTALRUM = 10;

class Rum 
{
private:
  int yta;
  
public:
  Rum();
  Rum( int y );
  int hamtaYta();
  bool laes( istream &is );
  void skriv( ostream &os);  
};

class Lagenhet 
{
 private:
  Rum koek;
  Rum badrum;
  Rum rum[MAXANTALRUM]; // Andra rum
  int antalrum;         
  
 public:
  Lagenhet();
  Lagenhet( int antrum );
  Lagenhet( int koeksyta, int badrumsyta, 
            int antalrum, int rumsyta[]);
  bool laes( istream &is );
  void skriv( ostream &os);
};

// Implementationer av metoder...

Rum:: Rum()
  : yta(0)
{}

Rum:: Rum( int y )
  : yta(y)
{}

int Rum:: hamtaYta()
{
  return yta;
}

bool Rum:: laes( istream &is )
{
  // L�s in och returnera true/false beroende
  // p� hur inl�sningen g�r.

  is >> yta;
  return is; // Eller "return !is.eof();" 
}

void Rum:: skriv( ostream &os)
{
  os << " Rum med yta = " << yta;
}


Lagenhet:: Lagenhet()
  : antalrum(0)
{}

Lagenhet:: Lagenhet( int antrum )
  : antalrum(antrum)
{}

Lagenhet:: Lagenhet( int koeksyta, 
		     int badrumsyta, 
		     int arum, int rumsyta[]) 
  :  koek(koeksyta), badrum(badrumsyta), antalrum(arum) 
{
  for ( int i = 0; i < antalrum; i++ )
    rum[i] = Rum(rumsyta[i]);
}

bool Lagenhet::laes( istream &is )
{
  // F�r varje l�genhet finns 
  // f�ljande information i filen: 
  // koeksyta badrumsyta antalrum yta 
  // f�r varje rum.
  //  Exempel: 
  // 20 12 3 20 10 10
  // 12 12 2 15 10

  // Rum har nu en egen inl�sningsmetod.
  // Anv�nd denna ist�llet f�r konstruktor!

  if ( !koek.laes(is) ) 
    return false;

  if ( !badrum.laes(is) ) 
    return false;

  if ( !(is >> antalrum) ) 
    return false;

  for ( int i = 0; i < antalrum; i++ )
    {
      if ( !rum[i].laes(is) ) 
	return false;
    }

  return true;
}

void Lagenhet::skriv( ostream &os )
{
  // Rum har ingen egen utskriftsmetod.
  // M�ste anv�nda selektorer.
  
  os << " K�k: ";
  koek.skriv( os );
  os << " Badrum: ";
  badrum.skriv( os );
  os << endl;

  os << " Antal rum : " << antalrum << ":" << endl;

  for ( int i = 0; i < antalrum; i++ )
    {
      rum[i].skriv( os );
    }

  os << endl;
}

const int MAXANTALLGH = 10;

int main()
{
  Lagenhet lagenhet[MAXANTALLGH];
  ifstream fin("lagen_in.txt");
  ofstream fout("lagen_ut1.txt");
  int antal = 0;

  if ( fin )
    {
      while ( antal < MAXANTALLGH &&
	      lagenhet[antal].laes(fin) )
	{
	  antal++;
	}
      
      for ( int i = 0; i < antal; i++ ) 
	{
	  lagenhet[i].skriv(fout);
	}
    }
  else
    cout << "Infilen fanns kanske inte..." << endl; 
  return 0;
}

/*
K�rningsexempel:

K�k med yta: 20 Badrum med yta: 12
Antal rum : 3 med ytor:  20 10 10
K�k med yta: 12 Badrum med yta: 12
Antal rum : 2 med ytor:  15 10


Utfilen blir:

 K�k:  Rum med yta = 20 Badrum:  Rum med yta = 12
 Antal rum : 3:
 Rum med yta = 20 Rum med yta = 10 Rum med yta = 10
 K�k:  Rum med yta = 12 Badrum:  Rum med yta = 12
 Antal rum : 2:
 Rum med yta = 15 Rum med yta = 10


 */
