#include <iostream>
#include <string>
#include "Vara.h"
using namespace std;

//=====================================================
// Implementation (definition) av metoder i klassen Vara.
// Filnamn: Vara.cpp
//--------------------------------------------------

void Vara::LaesIn()
{
    cout << "Ge varans namn:" << endl;
    getline(cin, Namn);
    cout << "Ge pris och antal i lager:" << endl;
    cin >> Pris >> Antal;
    cin.get();              //S� man kan l�sa in ny vara senare...
}
//--------------------------------------------------
void Vara::TillLager(int AntalNya)
{
    Antal += AntalNya;
}
//--------------------------------------------------
void Vara::Saelja(int AntalSaelj)
{
    Antal -= AntalSaelj;    //Vad h�nder om man s�ljer mer �n man har?
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
