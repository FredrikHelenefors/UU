// Filnamn : .../sportsman.cc
#include <iostream>
#include <string>
#include "person.h"
#include "sportsman.h"
using namespace std;

sportsman::sportsman() : person() {
  branch = "";
  nrFirstPrize = 0;
  cout << "V�lkommen sportsman " << fname << endl;
}

sportsman::sportsman( string fn, string ln, string br, int nfp ) 
  : person(fn, ln) {
  branch = br;
  nrFirstPrize = nfp;
  cout << "V�lkommen sportsman " << fname << endl;
}

sportsman::~sportsman() {
  cout << "Aj�ss sportsman " << fname << " " << lname << endl;
}

void sportsman::report() {
  person::report();
  cout << "och ut�var " << branch << ".\n"
       << fname << " har vunnit " << nrFirstPrize 
       << " f�rstapriser" << endl;
}

void sportsman::input() {
  person::input();
  cout << "Ange gren f�r " << fname << " : ";
  getline(cin, branch);
  cout << "Ange antal f�rstapriser : ";
  cin >> nrFirstPrize;
  cin.get();
}

void sportsman::firstPrize() {
  nrFirstPrize++;
}

string sportsman::getBranch() {
  return branch;
}

int sportsman::getNrFirstPrize() {
  return nrFirstPrize;
}
