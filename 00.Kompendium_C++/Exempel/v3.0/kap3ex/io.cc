// Filnamn: .../io.cc
#include<iostream>
using namespace std;

int main() {
  double radie, yta, omkrets;
  double pi = 3.14159;

  cout << "Ange en cirkelradie: ";
  cin >> radie;
  yta     = pi*radie*radie;
  omkrets = 2.*pi*radie;
  cout << "Cirkelns yta �r " << yta 
       << " och dess omkrets �r " << omkrets << endl;

  int m, n; 
  cout << "G� tv� heltal: ";
  cin >> m >> n;
  cout << m << "*" << n << " = " << m*n << endl 
       << m << "/" << n << " = " << m/n << endl;

}
