// Filnamn : .../Account0/Account.cc
// F�rsta versionen av ett bankkonto.
#include <iostream>
#include <string>
using namespace std;

// Klassdefinition f�r hantering av bankkonton.

class Account {

public:       // Publika metoder
  void input() {
    cout << "Ge namn : ";
    getline(cin, name);
    balance = 0;
  }
  
  void deposit( double amount ) { balance += amount; }
  
  void withdraw( double amount ) { balance -= amount; }
  
  void print() {
    cout << name << " har " << balance 
         << " p� sitt konto " << endl;
  }
  
protected:    // Skyddade dataf�lt
  string name;
  double balance;
}; // H�r �r klassdefinitionen slut


// Ett litet testprogram

int main() {  
  // Deklaration av 2 objekt av klassen Account
  Account lisa;
  Account olle;

  lisa.input();
  olle.input();
  lisa.print();
  olle.print();
  lisa.deposit( 500 );
  lisa.withdraw( 350 );
  lisa.print();
  return 0;
}
