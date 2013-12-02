// Filnamn : .../Account1/Account.cc
//
// Implementation av metoderna utanf�r klassdefinitionen

#include <iostream>
#include <string>
using namespace std;

// Klassdefinition f�r bankkonton.

class Account {
 public:            // Deklaration av publika metoder
  void input();
  void deposit( double amount );
  void withdraw( double amount );
  void print();
  
 protected:         // Skyddade dataf�lt
  string name;
  double balance;
}; // Slut p� klassdefinition

// Implementationer (definitioner) av metoderna. Observera 
// att varje metod f�reg�s av klassnamnet f�ljt av ::

void Account::input() {
  cout << "Ge namn : ";
  getline(cin, name);
  balance = 0;
}

void Account::deposit( double amount ) { balance += amount; }
  
void Account::withdraw( double amount ) {balance -= amount; }
  
void Account::print() {
  cout << name << " har " << balance 
       << " p� sitt konto " << endl;
}

// Testprogram

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
