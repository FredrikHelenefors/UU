// Filnamn: .../kapital.cc

#include <iostream>
using namespace std;

int main() {
  double raenta;
  cout << "R�ntesats i procent:";
  cin >> raenta;                      // L�s in r�ntesats
  double kapital = 1.;                // Startkapital
  int    aar = 0;                     // Antal g�ngna �r

  while ( kapital < 2. ) {
    kapital = kapital + kapital*raenta/100.; // L�gg till en �rsr�nta
    aar++;
  }
  cout << "Det kr�vs " << aar 
       << " f�r att f�rdubbla kapitalet" << endl;
  return 0;
}
