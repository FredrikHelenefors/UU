// Filnamn : .../Bank2/Bank.cc

#include <iostream>
#include <fstream>
#include "Account.h"
using namespace std;

const int MAX_NR_ACC = 100; // Arraystorlek. Maximalt antal konton

class Bank {
public:
  Bank();           // Standardkonstruktor
  ~Bank();          // Destruktor
 
  // Metoder f�r olika bankoperationer
  void newAccount();          // Skapa nytt konto
  void setCurAccount();       // S�tt aktuellt konto.
  void printCurAccount();     // Skriv aktuellt konto
  void deposit();             // Ins�ttning p� aktuellt konto
  void withdraw();            // Uttag fr�n aktuellt konto
  void printAllAccounts();    // Skriv alla konton

  // Menystyrning av bankoperationer
  void run();       

  // Hj�lpmetoder
  int searchCustomer(string name);
  void save(string fileName); // Spara alla konton p� en fil
  void load(string fileName); // L�s in konton fr�n en fil


protected:
  string name;                  // Banknamn
  int noOfAcc;                  // Antal befintliga konton. Fungerar �ven
                                // som index till f�rsta fria position.
  Account accounts[MAX_NR_ACC]; // Array med konton
  int curAccount;               // Index f�r aktuell kund
};


Bank::Bank() {
  noOfAcc = 0;        // Inga konton fr�n b�rjan
  name    = "TDBank";
  cout << "L�ser fr�n fil..." << endl;
  load("bank.dat");
  cout << noOfAcc << " konton l�sta" <<endl;
}

Bank::~Bank() {
  cout << "Sparar p� fil..." << endl;
  save("bank.dat");
  cout << noOfAcc << " konton sparade" << endl;
}

void Bank::newAccount() {
  cout << "* Skapa nytt konto *" << endl;
  // Kontroll om fler konton f�r plats
  if (noOfAcc >= MAX_NR_ACC)
    cout << "Inga fler konton f�r plats!" << endl;
  else {
    Account temp;
    temp.input(); // L�s in ny kund
    // Kontrollera att namnet inte redan finns
    if ( searchCustomer( temp.getName() ) >= 0 )
      cout << "*** Fel: Namnet finns redan!" << endl;
    else {
	accounts[noOfAcc] = temp;
	curAccount = noOfAcc;     // Nya kunden blir aktuell kund
	noOfAcc++;
    }
  }
}


void Bank::setCurAccount() {
  string name;
  cout << "* S�k konto *" << endl;
  cout << "Namn: ";
  getline(cin, name);
  int i = searchCustomer(name);
  if ( i<0 )
    cout << "Kunden finns ej" << endl;
  else {
    curAccount = i;
    accounts[curAccount].print();
  }
}


void Bank::printCurAccount() {
  accounts[curAccount].print();
}


void Bank::deposit() {
  double amount;
  cout << "* Ins�ttning *" <<endl;
  cout << "Kund  : " << accounts[curAccount].getName() << endl;
  cout << "Belopp: ";
  cin >> amount;
  cin.get();
  accounts[curAccount].deposit(amount);
  accounts[curAccount].print();
}


void Bank::withdraw() {
  double amount;
  cout << "* Uttag *" <<endl;
  cout << "Kund  : " << accounts[curAccount].getName() << endl;
  cout << "Belopp: ";
  cin >> amount;
  cin.get();
  accounts[curAccount].withdraw(amount);
  accounts[curAccount].print();
}


void Bank::printAllAccounts() {
  cout << "F�ljande konton finns i " 
       << name << " : \n";
  
  for (int i=0; i<noOfAcc; i++) 
    accounts[i].print();
}


void Bank::run() {
  int ans;

  do {
    cout << "=====================\n";
    cout << "Vad vill du g�ra?\n";
    cout << "1  Skapa ny kund\n"
	 << "2  Hitta kund\n"
         << "3  Ge saldobesked\n"
         << "4  S�tta in\n"
	 << "5  Ta ut\n"
	 << "6  Lista alla konton\n"
	 << "7  Sluta" << endl;
    cout << "Ditt val: ";
    cin >> ans; 
    cin.get();
    cout << "=====================" << endl;
    if ( ans==1 )       newAccount();
    else if (ans==2)    setCurAccount();
    else if (ans==3)    printCurAccount();
    else if (ans==4)    deposit();
    else if (ans==5)    withdraw();
    else if (ans==6)    printAllAccounts();
    else if (ans==7)    ;
    else {
      cout << "Felaktigt kommando. F�rs�k igen" << endl;
    }
  } while (ans!=7);
}

int Bank::searchCustomer(string name) {
  // Hj�lpmetod som s�ker efter konto med angiven �gare
  for (int i=0; i<noOfAcc; i++)
    if ( accounts[i].getName()==name )
      return i;     // Funnen
  return -1;        // Ej funnen
}


void Bank::save(string fileName) {
  ofstream  ofs(fileName.c_str());
  ofs << noOfAcc << '\n';
  for (int i=0; i<noOfAcc; i++)
    ofs << accounts[i].getName() << '\t' << accounts[i].getBalance() << '\n';
}


void Bank::load(string fileName) {
  ifstream  ifs(fileName.c_str());
  if (ifs.good()) {
    ifs >> noOfAcc;
    ifs.get();
    for (int i=0; i<noOfAcc; i++) {
      ifs >> accounts[i].name >> accounts[i].balance;
    }
  } else
    cout << "Ingen indatafil hittades" << endl;
}


int main() {
  Bank theBank;
  theBank.run();
}
