/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr:

Namn: Thomas Nordenmark

Personummer: 810427-8257

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja/Nej
     Om Nej, beskriv vilka testdata som ger problem:

Jag har använt kompilator/editor:

Jag har använt följande dator:
      med operativsystemet:

Jag har arbetat ungefär 4 timmar med denna uppgift

================================================================================
*/
#include <iostream>
using namespace std;

// Deklaration av programmets funktioner.
void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &tal1, int &tal2);
long berakna(char op, int tal1, int tal2);
void skrivResultat(long svar);

int main()
{
	int tal1, tal2;
	char op;
	long svar;

	// Skriv ut information om programmet.
	skrivInfo();

	// Läs in tal1 och tal2.
	tal1 = lasEttTal();

	tal2 = lasEttTal();

	// Läs in operationen som ska utföras.
	op = lasOp();

	// Sortera talen i stigande ordning.
	ordna(tal1, tal2);

	// Skicka tal1, tal2 samt valet av operation till beräkningsfunktionen.
	svar = berakna(op, tal1, tal2);

	// Skriv ut resultatet av beräkningen.
	skrivResultat(svar);

  return 0;
}

void skrivInfo()
{
	cout << "Programmet läser in två tal, utför vald" << endl;
	cout << "beräkning på samtliga tal i det angivna skåpet" << endl;
	cout << "samt returnerar beräkningens resultat." << endl;
}

int lasEttTal()
{
	int tal;
	
	cout << "Mata in ett heltal: ";
	cin >> tal;

	return tal;
}

char lasOp()
{
	char op;
	
	cout << "Välj operation; (a)ddition, (m)ultiplikation" << endl;
	cout << "eller (k)vadratsummering: ";
	cin >> op;

	return op;
}

void ordna(int &tal1, int &tal2)
{
	// Om tal1 är större än tal2, byt plats på dessa.
	if(tal1 > tal2)
		swap(tal1, tal2);
}

long berakna(char op, int tal1, int tal2)
{
	int i = 0;
	long svar = 0;

	if(op == 'a')
	{
		for(i = tal1; i <= tal2; i++)
		{
			// Addera svaret med nästa tal i serien tills i = tal2.
			svar += i;
		}
		return svar;
	}
	else if(op == 'k')
	{
		for(i = tal1; i <= tal2; i++)
		{
			// Multiplicera svaret med sig själv tills i = tal2.
			svar += (i * i);
		}
		return svar;
	}
	else if(op == 'm')
	{
		// Lokal variabel för multiplikationsberäkningen.
		long svar = 1;

		for(i = tal1; i <= tal2; i++)
		{
			// Multiplicera svaret med nästa tal i serien tills i = tal2.
			svar *= i;
		}
		return svar;
	}
	else
	{
		// Visa ett felmeddelande om något annat än 'a', 'k' eller 'm' matats in.
		cout << "Du har valt en felaktig operation." << endl;
		return 0;
	}
}

void skrivResultat(long svar)
{
	cout << "Svaret är: " << svar << endl;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

...

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.


*/
