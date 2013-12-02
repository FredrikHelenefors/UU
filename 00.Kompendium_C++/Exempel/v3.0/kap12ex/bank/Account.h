// Filnamn : .../Bank2/Account.h

#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <string>
using namespace std;

// Klassdefinition f�r hantering av bankkonton.

class Account {

 public:
  Account();                       // Standardkonstruktor.
  Account( string n, double b );   // Konstruktor med parametrar
  
  void input();                    // L�s in data.
  void deposit( double amount );   // S�tt in pengar. 
  void withdraw( double amount );  // Ta ut pengar.
  void print();                    // Skriv saldobesked.
  double getBalance();             // Returnera saldo
  string getName();                // Returnera �gare
 protected:
  string name;
  double balance;
  friend class Bank;       // Ger banken fullst�ndiga r�ttigheter
};
#endif



