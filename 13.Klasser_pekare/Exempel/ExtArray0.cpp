// ExtArray0.cpp
// Extensible array, dvs t�njbar array.
// Anm om kopieringskonstruktor/tilldelning:
//
// Tilldelningar: om arr1 = arr3. D� delar arr1 och arr3
// minne! Dvs om arr3 �ndras, s� �ndras arr1!!!
// Det kan bli mycket fel!
// Okay tilldelning om egen tilldelningsoperator eller
// "assign"-funktion finns. Dvs
// void assign( ExtArray a );  + kopieringskonstruktor.
//

#include <iostream>
using namespace std;

const int blank = 0;

class ExtArray
{
private:
  int *array;
  int bufSize;

public:
  ExtArray();
  ExtArray( int siz, int val );
  ~ExtArray();				      
  ExtArray( const ExtArray & a ); //kopieringskonstr.
  
  void change(int i, int num);
  int size();
  void resize( int n );
  void assign( const ExtArray & a ); // &a ty ingen kopier.konst.
  void write();
  void addToEnd( int newItem );
  //  bool empty();
  //  void append( ExtArray other );
};


int main()
{
  ExtArray arr1( 5, -1 ); // 5 element, alla �r -1.
  ExtArray arr2;          // 0 element.
  ExtArray arr3 = ExtArray( 2, -99 );
  ExtArray arr4(arr3);   // copy...varning
  ExtArray arr5 = arr2;           // copy...varning

  cout << "arr1: "; arr1.write();
  cout << "arr2: "; arr2.write();
  cout << "arr3: "; arr3.write();
  cout << "arr4: "; arr4.write();
  cout << "arr5: "; arr5.write();

  // ***h�r skall kod in!
  return 0;
}

ExtArray:: ExtArray()
  : bufSize(0)
{
  array = 0; //NULLpointer
  cout << "Hello default " << bufSize << endl;
}

ExtArray:: ExtArray( int siz, int val )
  : bufSize(siz)
{
  if ( bufSize > 0 )
    {
      array = new int[bufSize];
      for ( int i = 0; i < bufSize; i++ )
	array[i] = val;
    }
  else
    {
      array = 0; //NULL-pekare
    }
  cout << "Hello �verlagrad " << bufSize << endl;
}


ExtArray:: ExtArray( const ExtArray & a )
  :  bufSize(a.bufSize)
{
  cout << "Hello kopiering: ny l�ngd: " 
       << bufSize << endl;

  if ( bufSize > 0 )
    {
      array = new int[bufSize];  // Allokera nytt minne
      for ( int i = 0; i < bufSize; i++ )
	array[i] = a.array[i]; //Kopiera elementen
    }
  else
    array = 0; //NULL
}


ExtArray:: ~ExtArray()
{
  delete [] array;
}

void ExtArray:: resize( int n )
{
  int *p = 0; 
  
  if ( n > 0 )    // Om ny storlek ej �r noll
    {
      p = new int[n]; // Skapa array med n elem.

      int i; 
      for ( i = 0; i < n   // Fyll med element.
	    && i < bufSize; i++ )
	{
	  p[i] = array[i];
	}
      for ( ; i < n; i++ )      // Fyll resten med blanka .
	p[i] = blank;
    }

  delete [] array; // Avallokera minne.
  array = p;       // S�tt array till nya arrayen.
  bufSize = n;     // S�tt bufSize till nya storleken.
}

int ExtArray:: size()
{
  return bufSize;
}  

void ExtArray:: write()
{
  cout << "Antal element �r " << bufSize;
  if ( bufSize > 0 )
    {
      cout << ":";

      for ( int i = 0; i < bufSize; i++ )
	cout << '\t' << array[i];
    }
  else
    cout << ".";

  cout << endl;
    
}

void ExtArray:: assign( const ExtArray  & a )
{
  // Tilldela: aktuella objektet = a.

  bufSize = a.bufSize;
  cout << "Hello assign " <<  bufSize << endl;

  if ( bufSize > 0 )
    {
      delete [] array;           // Frig�r minne.
      array = new int[bufSize];  // Allokera nytt minne.

      for ( int i = 0; i < bufSize; i++ )
	{
	  array[i] = a.array[i]; //Kopiera elementen
	}
    }
  else
    array = 0; //NULL
}

void ExtArray:: addToEnd( int newItem )
{
  // �ka p� arrayen med ett element till.
  resize(bufSize+1); // Fixar �ven bufSize++;

  // Tilldela nu sista elementet, dvs plats bufSize-1:
  array[bufSize-1] = newItem;
}

void ExtArray:: change(int i, int num)
{
  if ( i < bufSize )
    array[ i ] = num;
}

/*

Hello �verlagrad 5
Hello default 0
Hello �verlagrad 2
Hello kopiering: ny l�ngd: 2
Hello kopiering: ny l�ngd: 0
arr1: Antal element �r 5:       -1      -1      -1      -1      -1
arr2: Antal element �r 0.
arr3: Antal element �r 2:       -99     -99
arr4: Antal element �r 2:       -99     -99
arr5: Antal element �r 0.

*/
