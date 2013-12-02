//  Filnamn: .../countChars1.cc
// L�ser och r�knar antalet bokst�ver och siffror.
// Avbryter n�r inget mer finns att l�sa.

#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int nletters = 0, ndigits = 0, ntotal = 0;
  char c;
  while ( cin.get(c) ) {
    ntotal++;
    if ( isalpha(c) )
      nletters++;
    else if ( isdigit(c) )
      ndigits++;
  }
  cout << "Totalt antal l�sta tecken: " << ntotal << endl;
  cout << "Antal bokst�ver          : " << nletters << endl;
  cout << "Antal siffror            : " << ndigits << endl;

  return 0;
}
