// Filnamn : .../person.cc
#include<iostream>
#include<string>
#include "person.h"
using namespace std;

// Konstruktorer och destruktor

person::person() {
  fname = "Arne";
  lname = "Anonym"; 
  cout << "V�lkommen " << fname << endl;
}

person::person(string fn, string ln) {
  fname = fn;
  lname = ln;
  cout << "V�lkomen " << fname << endl;
}

person::~person() {
  cout << "Aj�ss " << fname << " " << lname << endl;
}


// Publika metoder

void person::report() {
  cout << fname << " " << lname << endl;
}

void person::writeName() {
  cout << fname << " " << lname;
}

void person::input() {
  cout << "F�rnamn: ";
  getline(cin, fname);
  cout << "Efternamn: ";
  getline(cin, lname);
}
