#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// lagenhetrum0.cpp
// Rum har ingen egen inl�sningsmetod.
// Rum har ingen utskriftsmetod.

const int MAXANTALRUM = 10;

class Rum 
{
private:
  int yta;
  
public:
  Rum();
  Rum( int y );
  int hamtaYta();
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

  // Rum har ingen egen inl�sningsmetod.
  // Anv�nd tempor�r variabel vid
  // inl�sning. Om det gick bra:
  // anv�nd konstruktor i Rum-klassen.

  int temp;      // tempor�r variabel

  if (!(is >> temp)) 
    return false;  
  koek = Rum(temp);

  if (!(is >> temp)) 
    return false;  
  badrum = Rum(temp);

  if (!(is >> temp)) 
    return false;

  antalrum = temp;

  for ( int i = 0; i < antalrum; i++ )
   {
     if (!(is >> temp)) 
       return false;
     rum[i] = Rum(temp);     
   }
  return true;
}

void Lagenhet::skriv( ostream &os )
{
  // Rum har ingen egen utskriftsmetod.
  // M�ste anv�nda selektorer.
 
  os << "K�k med yta: " << koek.hamtaYta() << " ";
  os << "Badrum med yta: " << badrum.hamtaYta() << endl;
  os << "Antal rum : " << antalrum << " med ytor: ";

  for ( int i = 0; i < antalrum; i++ )
    {
      os << " " << rum[i].hamtaYta();
    }

  os << endl;
}

const int MAXANTALLGH = 20;

int main()
{
  Lagenhet lagenhet[MAXANTALLGH];
  ifstream fin("lagen_in.txt");
  ofstream fout("lagen_ut0.txt");
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
K�k med yta: 20 Badrum med yta: 12
Antal rum : 3 med ytor:  20 10 10
K�k med yta: 12 Badrum med yta: 12
Antal rum : 2 med ytor:  15 10


 */
