// Filnamn: .../string1.cc
// L�ser ett namn, skriver en h�lsning
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s = "Hej p� dig";
  string namn;

  cout << "Vad heter du? ";
  cin >> namn;
  
  cout << s << ", " << namn << '!' << endl;
  return 0;
}
