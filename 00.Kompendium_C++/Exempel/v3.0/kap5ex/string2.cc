// Filnamn: .../string2.cc
// L�ser ord och tar reda p� ordl�ngden
#include <iostream>
#include <string>
using namespace std;

int main() {

   string s;
   cout << "Ge ett ord: ";
   cin  >> s;
   while ( s != "STOP" ) {
     cout << "Ordet " << s << " inneh�ller " 
	  << s.length() << " tecken" << endl;
     // L�s ett nytt ord
     cout << "Ge ett ord: ";
     cin  >> s;
   }
   return 0;
}
