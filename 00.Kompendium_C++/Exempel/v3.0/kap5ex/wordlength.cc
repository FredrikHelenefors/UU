// Filnamn: .../wordlength.cc
// R�knar ordl�ngder
#include <iostream>
#include <string>
using namespace std;

int main() {

   string w;
   cout << "Ge ett ord: ";
   cin  >> w;
   while ( w != "STOPP" ) {
     cout << "Ordet " << w << " inneh�ller " 
          << w.length() << " tecken" << endl;
     // L�s ett nytt ord
     cout << "Ge ett ord: ";
     cin  >> w;
   }
   return 0;
}
