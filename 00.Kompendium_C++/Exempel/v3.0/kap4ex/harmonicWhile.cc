// Filnamn: .../harmonicWhile.cc
// Ber�kna den harmoniska summan

#include <iostream>
using namespace std;

int main() {

  int    n;
  cout << "Antal termer: ";
  cin >> n;

  double h = 0.0;
  while ( n>0 ) {
    h = h + 1./double(n);
    n--;
  }
  cout << "Summan �r: " << h << endl;
  return 0;
}
