// Filnamn : .../ex02.cc

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inFile( "exempel.dat" );
  
  cout << "Filen 'exempel.dat' har f�ljande inneh�ll:" << endl;
  char ch;

  while ( inFile.get(ch) ) {
    cout << ch;
  }

  cout << "=== end of file ===" << endl;
  return 0;
}
