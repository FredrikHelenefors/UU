// Filnamn:  .../countChars.cc
// L�ser en rad och r�knar antalet bokst�ver och siffror
#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int nletters = 0, ndigits = 0, ntotal = 0;
  char c;
  cin.get(c);   
  while ( c!='\n' ) {
    ntotal++;
    if ( isalpha(c) )
      nletters++;
    else if ( isdigit(c) )
      ndigits++;
    cin.get(c);
  }
  cout << "Totalt antal l�sta tecken: " << ntotal << endl;
  cout << "Antal bokst�ver          : " << nletters << endl;
  cout << "Antal siffror            : " << ndigits << endl;

  return 0;
}
