// Filnamn: .../countDigits.cc
// R�knar antalet siffror p� en rad
#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int ndigits = 0;
  char c;
  cin.get(c);               // L�s f�rsta tecknet
  while ( c!='\n' ) {       // S� l�nge ej radslut
    if ( c>='0' && c<='9' ) // Om siffra s�
      ndigits++;            // r�kna
    cin.get(c);             // L�s n�sta tecken
  }
  cout << "Antal siffror: " << ndigits << endl;

  return 0;
}
