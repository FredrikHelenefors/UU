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
  Villa *v1, *v2;

  // Tv� objekt kommer in till fastighetsf�rmedlingen:

  v1 = new Villa("Ekv�gen 123", 1000000);  
  v2 = new Villa("Alv�gen 12", 1200000);   

  // Vi s�ljer genast villa "v1".

  delete v1;   // L�mna tillbaka det minne v1 pekar p�
  v1 = 0;      // S�tt pekaren till NULL.

  // Skriv info om v�ra objekt om det g�r, dvs
  // om pekarna pekar p� n�got (dvs �r nollskilda).

  cout << "---Skriv info om villorna" << endl;

  if ( v1 != 0 )
    {
      v1->skriv(); cout << endl;
    }
  else
    cout << "Villan fanns ej!" << endl;

  if ( v2 != 0 )
    {
      v2->skriv(); cout << endl;
    }
  else
    cout << "Villan fanns ej!" << endl;

  // S�lj alla villor f�r skojs skull...
  // utan att kolla om de finns eller ej.

  delete v1;
  delete v2;  // Vi f�r g�ra delete p� noll-pekare,
              // men inget h�nder.
  
  // Ha f�r vana s�tta pekare till NULL efter delete.
  // I allafall om programmet �r st�rre; nu slutar det ju.

  v1 = 0;
  v2 = 0;

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

/*K�rning:
---Skriv info om villorna
Villan fanns ej!
 Adress = Alv�gen 12, pris = 1200000

*/
