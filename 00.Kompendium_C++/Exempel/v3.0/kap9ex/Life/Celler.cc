// Filnamn : ...Life//Celler.cc

/* 
   En klass som simulerar 'Game of life'. 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>    // Inneh�ller slumptalsfunktionerna
#include "Celler.h"
using namespace std;


Cells::Cells() {
  size = 0;
  zeroit(plate);
}

void Cells::initiate() {
  readSize();  // Anv�ndaren v�ljar storlek
  readForm();  // Anv�ndaren v�ljer initialform
  
  // Initiera 'brickan' med celler
  if (form == 'x') 
    initX();
  else if (form == 'y') 
    initY();
  else if (form == 'z') 
    initZ();
  else if (form == 's') 
    initS();
}

void Cells::newGeneration() { // L�t celler d�, f�das eller �verleva
                              // allt beror p� spelreglerna
  int iter=0;
  char svar;
  int temp[MAX][MAX];         // En tempor�r 'bricka'
  
  do {
    zeroit(temp); // Rensa den tempor�ra 'brickan'
    
    for (int i=1; i<=size; i++)
      for (int j=1; j<=size; j++) { 
	int n=neighbours(i,j);
	if (plate[i][j] == 1) { // Om aktuell plats har en levande cell
	  if (n==0 || n==1) 
	    temp[i][j] = 0;
	  else if (n==2 || n==3) 
	    temp[i][j] = 1;
	  else if (n==4 || n==5) 
	    temp[i][j] = 0;
	}
	// Eller om det inte finns en levand cell 
	// men det finns 3 levadne grannar
	else if (plate[i][j]==0 && n==3)
	  temp[i][j] = 1;
      }
    int next=iter+1;
    cout << "\nGeneration # " << iter << " och "<< next; 
    iter++;
    draw(temp);
    
    // Kopiera den tempor�ra 'brickan'
    for (int i=0; i<size+2; i++)
      for (int j=0; j<size+2; j++)
	plate[i][j] = temp[i][j];    
    
    cout << "\nVill du forts�tta? Ja=j , Nej=n: ";
    cin >> svar;
    cin.get();
  } while (svar=='j' || svar=='J' || svar==' ');
}

//********** Privata metoder *************************************
// Metoder som bara klassen sj�lv ska kunna anv�nda!

void Cells::readSize() {
  cout << "\nL�mplig storlek p� brickan �r t ex 15x15, \n";
  cout << "v�lj ett heltal  mellan 10 och 25.";
  
  do {
    cout << "\nAnge brickans storlek = "
	 << "ett heltal i intervallet 10-25: ";
    cin >> size;
    cin.get();
  } while (size>25 || size<10);
}

void Cells::readForm() {
  cout << "Du ska v�lja initial form som kan "
       << "vara en form av f�ljande";
  cout << "* X-formation\n"
       << "* Y-formation\n"
       << "* Z-formation\n"
       << "* Slump-val" << endl;

  do {
    cout << "Ange ett tecken x, y, z eller s "
	 << "f�r att v�lja en av ovanst�ende formationer : ";
    cin >> form;
    cin.get();
  } while (form!='x' && form!='y' && form!='z' && form!='s');
}

void Cells::zeroit(int arr[][MAX]) { // Rensa 'brickan'
  for (int i=0; i<MAX; i++)
    for (int j=0; j<MAX; j++)
      arr[i][j] = 0;
}

void Cells::initX() {
  zeroit(plate);
  int j=size;

  for (int i=1; i<=size; i++) {
    plate[i][i] = 1;
    plate[i][j] = 1;
    j--;
  }
}

void Cells::initY() {
  if (size%2 == 0)
    cout << "F�r Y-formationen kr�vs att "
	 << "spelplanens dimension n "
	 << "�r udda,\ns� �ndrar jag storleken, "
	 << "den blir = " << (++size);
  
  zeroit(plate);
  
  int j=size; 
  int nhalv=(size+1)/2;

  for (int i=1; i<= nhalv; i++) {
    plate[i][i] = 1;
    plate[i][j] = 1; 
    j--;
  }
  for (int i=nhalv+1; i<=size; i++) 
    plate[i][nhalv] = 1;
}

void Cells::initZ() {
  zeroit(plate);
  int j=size-1;

  for (int i=1; i<=size; i++) {
    plate[1][i] = 1;  
    plate[size][i] = 1;
  }
  for (int i=2; i<size; i++)  {
    plate[i][j] = 1; 
    j--;
  }
}

void Cells::initS() {
  zeroit(plate);

  int froe;
  cout << "Ge ett fr�, g�rna ett stort primtal: " << endl;
  cin >> froe; cin.get();
  srand48( froe );             // Initiering sker _en_ g�ng.

  for (int i=1; i<=size; i++)
    for (int j=1; j<=size; j++) { 
      double slump=drand48();
      if (slump> 0.6) 
	plate[i][j] = 1;
    }
}

int Cells::neighbours(int i, int j) { // Titta p� grannarna!!
  int n=0;
  if (plate[i-1][j-1])  n++;
  if (plate[i-1][j])    n++;
  if (plate[i-1][j+1])  n++;
  
  if (plate[i][j-1])    n++;
  if (plate[i][j+1])    n++;
  
  if (plate[i+1][j-1])  n++;
  if (plate[i+1][j])    n++;
  if (plate[i+1][j+1])  n++;
  
  return n;
}

void Cells::draw(int temp[][MAX]) {
  cout << endl;
  
  for (int i=1; i<=size; i++) { 
    for (int j=1; j<=size; j++) {
      if (plate[i][j])
	cout << "*"; 
      else
	cout << " ";
    }
    cout << " | ";

    for (int k=1; k<=size; k++) {
      if (temp[i][k])
	cout << "*";
      else
	cout << " ";
    }
    cout << endl;
  }
}
//****************************************************************
