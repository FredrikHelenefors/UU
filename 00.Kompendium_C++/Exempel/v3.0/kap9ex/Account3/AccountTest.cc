// Filnamn .../Account3/AccountTest.cc
// Testprogram f�r klassen Account

#include <iostream>
#include "Account.h"

int main() {  
  // Deklaration av 2 objekt av klassen Account
  Account x, y;
  double dep;

  x.input();
  cout << "Ins�ttning f�r " << x.getName() << ": ";
  cin >> dep;
  cin.get();
  x.deposit(dep);
  
  y.input();
  cout << "Ins�ttning f�r " << y.getName() << ": ";
  cin >> dep;
  cin.get();
  y.deposit(dep);

  if ( x.getBalance() > y.getBalance() )
    cout << x.getName() << " har mer pengar �n " << y.getName() << endl;
  return 0;
}
