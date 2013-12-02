// Filnamn : .../Account3/Account.cc

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

void Account::input() {
  cout << "Ge namn : ";
  getline(cin, name);
  balance = 0;
}
  
void Account::deposit( double amount ) { 
  balance += amount; 
}
  
void Account::withdraw( double amount ) {
  balance -= amount; 
}
  
void Account::print() {
  cout << name << " har " << balance 
       << " p� sitt konto " << endl;
}

double Account::getBalance() {
  return balance;
}

string Account::getName() {
  return name;
}
