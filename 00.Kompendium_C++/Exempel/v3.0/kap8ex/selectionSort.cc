// Filnamn: .../selectionSort.cc
// Urvalssortering

 void selSort( int data[], int antal ) {
      for ( int i=0; i<antal-1; i++ ) {
      int min = i; // "Gissa" att minsta finns p� plats i
      for ( int j=i+1; j<antal; j++ ); // Se om det finns mindre
          if ( data[j] < data[min] )
             min = j;
                 // Byt plats p� det minsta och det "f�rsta"
             int temp = data[i];
             data[i] = data[min];
             data[min] = temp;
      }
}
