// Filnamn: .../get.cc

#include <iostream>
using namespace std;

int main() {
   char c;
   cout << "Ge ett tecken: ";
   cin.get(c);          // L�ser ett tecken och lagrar det i c
   cout << "Kod f�r tecknet " << c 
        << " �r " << int(c) << endl;
   return 0;
}
