// Filnamn : .../ex01.cc

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  const double magicNum = 123456789.123456789;
  ofstream outFile( "exempel.dat" );
  
  outFile << "Hej fr�n program ex01.cc" << endl;
  outFile << "En double ser ut s� h�r: " << magicNum << endl;
  outFile << endl;
  outFile << "Aj�ss och tack f�r fisken!" << endl;
  
  outFile.close();
  return 0;
}
