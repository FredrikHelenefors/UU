// Filnamn: .../char.cc

#include <iostream>
using namespace std;

int main() {
   char c;
   cout << "Ge ett tecken: ";
   cin  >> c;
   cout << "Kod f�r tecknet " << c 
        << " �r " << int(c) << endl;
   cout << "N�sta tecken �r " << char(c+1) 
        << " med kod " << c+1 << endl;
   return 0;
}
