// Filnamn: .../squares.cc
// Ber�kna kvadrater p� ett antal inl�sta tal

#include <iostream>
using namespace std;

int main() {
  double tal;
  cout << "Ge tal att kvadrera. Avbryt med 0.";
  cin >> tal;                       // L�s det f�rsta talet
  while ( tal!=0 ) {                // S� l�nge inte 0 l�sts
    cout << "Kvadraten �r " << tal*tal << endl;
    cin >> tal;                     // L�s nytt tal
  }
  cout << "Tack f�r mig!" << endl;
  return 0;
}
