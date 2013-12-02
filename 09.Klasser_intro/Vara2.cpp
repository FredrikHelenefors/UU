//-------------------------------------------
// Vara2.cpp
// Ett program med klassen Vara.
// Nu med b�ttre struktur i hela filen:
// 1. Klassdeklaration
// 2. Main
// 3. Definition av metoderna.

#include <iostream>
#include <string>
using namespace std;

//Klassdeklaration f�r klassen Vara.

class Vara
{
private:
  string Namn;
  double Pris;
  int    Antal;

public:
  void LaesIn();                    //L�s fr�n tangentbord.
  void TillLager(int AntalNya);     //Nya till lagret.
  void Saelja(int AntalSaelj);      //S�lj vara.
  void ProcentPris(double Faktor);  //S�tt nytt pris.
  void SkrivUt();                   //Skriv info om vara.
  
};
//=================================================
// Huvudprogram som testar klassen Vara.

int main()
{
  Vara enVara;                      // Skapar objektet enVara. 
  enVara.LaesIn();                  // L�s in data till enVara-objektet.
  enVara.SkrivUt();                 // Skriv ut info om varan.

  enVara.ProcentPris(1.10);         // Pris�kning 10%.
  enVara.TillLager(100);            // 100 nya fr�n grossisten.
  enVara.Saelja(50);                // S�lj 50 st.

  enVara.SkrivUt();                 //Skriv ut info om varan.
  return 0;
}
//=====================================================
// Implementation (definition) av metoder i klassen Vara.

void Vara::LaesIn()
{
  cout << "Ge varans namn:" << endl;
  getline( cin, Namn );
  cout << "Ge pris och antal i lager:" << endl;
  cin >> Pris >> Antal;
  cin.get();                        //S� man kan l�sa in ny vara senare...
}
//--------------------------------------------------
void Vara::TillLager(int AntalNya)
{
  Antal += AntalNya;
}
//--------------------------------------------------
void Vara::Saelja(int AntalSaelj)
{
  Antal -= AntalSaelj;              //Vad h�nder om man s�ljer mer �n man har?
}
//--------------------------------------------------
void Vara::ProcentPris(double Faktor)
{
  Pris *= Faktor;
}
//--------------------------------------------------
void Vara::SkrivUt()
{
  cout << "\t Varunamn: " << Namn 
       << "\t Pris: " << Pris 
       << "\t Antal i lager: " << Antal
    << endl;
}
/* K�rningsexempel:
Ge varans namn:
Ost   
Ge pris och antal i lager:
45.50 100
         Varunamn: Ost   Pris: 45.5      Antal i lager: 100
         Varunamn: Ost   Pris: 50.05     Antal i lager: 150
*/
