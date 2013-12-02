//-------------------------------------------
// Vara1.cpp

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
  void LaesIn()                            //L�s fr�n tangentbord.
  {
    cout << "Ge varans namn:" << endl;
    getline( cin, Namn );
    cout << "Ge pris och antal i lager:" << endl;
    cin >> Pris >> Antal;
    cin.get(); //S� man kan l�sa in ny vara senare ..
  }
  void TillLager( int AntalNya )                    //Nya till lagret.
  {
    Antal += AntalNya;
  }
  void Saelja( int AntalSaelj )                     //S�lj vara.
  {
    Antal -= AntalSaelj;   //Vad h�nder om man s�ljer mer �n man har?
  }
  void ProcentPris( double Faktor )                 //S�tt nytt pris.
  {
    Pris *= Faktor;
  }
  void SkrivUt()                                    //Skriv info om vara.
  {
    cout << "\t Varunamn: " << Namn 
         << "\t Pris: " << Pris 
         << "\t Antal i lager: " << Antal
         << endl;
    
  }
};
//=====================================================
// Huvudprogram som testar klassen Vara.

int main()
{
  Vara enVara;        // Skapar objektet enVara. 
  enVara.LaesIn();    // L�s in data till enVara-objektet.
  enVara.SkrivUt();   // Skriv ut info om varan.

  enVara.ProcentPris( 1.10 );    // Pris�kning 10%.
  enVara.TillLager( 100 );       // 100 nya fr�n grossisten.
  enVara.Saelja( 50 );           // S�lj 50 st.

  enVara.SkrivUt();               //Skriv ut info om varan.
  return 0;
}

/* K�rningsexempel:
Ge varans namn:
Mj�lk
Ge pris och antal i lager:
7.00 125
         Varunamn: Mj�lk         Pris: 7         Antal i lager: 125
         Varunamn: Mj�lk         Pris: 7.7       Antal i lager: 175
*/
