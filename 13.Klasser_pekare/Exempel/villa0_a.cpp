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
  // Tv� objekt finns inne p� fastighetsf�rmedlingen:

  Villa villa1("Ekv�gen 123", 1000000);  
  Villa villa2("Alv�gen 12", 1200000);   

  // Vi l�ter pekare peka ut dem.

  Villa *v1, *v2;
  v1 = &villa1;
  v2 = &villa2;

  cout << "---Skriv info om villorna" << endl;

  v1->skriv(); cout << endl;
  v2->skriv(); cout << endl;

  // S�lj alla villor f�r skojs skull...
  // Vi tar bort sj�lva pekandet, men egentligen
  // ligger villorna kvar i minnet, eftersom vi
  // deklarerade dem statiskt som "villa1" och "villa2".

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

/* K�rning:
---Skriv info om villorna
 Adress = Ekv�gen 123, pris = 1000000
 Adress = Alv�gen 12, pris = 1200000
*/
