// Filnamn:.../raentaFor.cc
// Hur stort blir kapitalet efter ett visst antal �r

#include <iostream>
using namespace std;

int main() {
  double kapital = 1.;                // Startkapital
  double raenta;                      // R�ntesats i procent
  int    aar;                         // Antal g�ngna �r

  cout << "R�ntesats i procent: ";
  cin >> raenta;
  cout << "Antal �r           : ";
  cin >> aar;        

  for ( int i = 1; i<=aar; i++ )
    kapital = kapital + kapital*raenta/100.;

  cout << "Kapitalet har blivit " << kapital << endl;

  return 0;
}
