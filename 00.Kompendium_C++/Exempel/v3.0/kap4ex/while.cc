// .../while.cc
#include <iostream>
using namespace std;

int main() {
  double tal, summa=0.0;
  cout << "Ge tal att summeras. Avbryt med 0.";
  cin >> tal;              // L�s det f�rsta talet
  while ( tal!=0 ) {       // S� l�nge inte 0 l�sts
    summa = summa + tal;   // Addera till summan  
    cin >> tal;            // L�s nytt tal
  }
  cout << "Summan �r: " << summa << endl;
}
