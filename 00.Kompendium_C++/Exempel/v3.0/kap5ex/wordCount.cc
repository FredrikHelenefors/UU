// Filnamn: .../wordCount.cc
// R�knar "ord". Med "ord" avses en f�ljd av tecken som
// inte inneh�ller n�got vitt tecken 
// Avbryter n�r inget mer finns att l�sa.

#include <iostream>
#include <string>

using namespace std;

int main() {
  int nwords = 0;
  string w;;
  while ( cin >> w ) {     // L�s ett ord
    nwords++;
  }
  cout << "Antal l�sta ord: " << nwords << endl;
  return 0;
}
