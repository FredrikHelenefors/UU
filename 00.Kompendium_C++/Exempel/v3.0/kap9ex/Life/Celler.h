// Filnamn : .../Life/Celler.h

/* 
   En klass som simulerar 'Game of life'. 
   Man vill studera en modell av en cellpopulations 
   liv. Cellerna t�nks ligga p� en kvadratisk bricka 
   som �r indelad i rutor, d�r varje ruta kan 
   inneh�lla en cell. Varje cell kan vara levande 
   eller d�d. Man b�rjar med givet initialtillst�nd 
   av levande celler och studerar hur cellpopulationen 
   f�r�ndras i tiden. Dessa f�r�ndringar inneb�r 
   helt enkelt att celler d�r eller f�ds beroende p� 
   hur omgivningen till dessa ser ut. Ett steg fram�t 
   i tiden ger en nu s k generation av celler p� brickan.

   En bricka med celler som kommer att �ndra
   antalet celler enligt vissa spelregler:
   * Om en levande cell har ingen eller enbart 
     en granne s� d�r den av isolering.
   * Om en levande cell har tv� eller tre grannar 
     s� �verlever den till n�sta generation.
   * Om en levende cell har fyra eller fler grannar 
     s� d�r den p g a '�verbefolkning' och n�ringsbrist.
   * Om en d�d cell har exakt tre levande grannar 
     s� f�ds en ny cell p� samma plats. Man kan se det 
     som att den d�da cellen blir levande i n�sta generation.
*/

#ifndef __CELLS__
#define __CELLS__

const int MAX = 30;       // Brickans maxstorlek

class Cells {
 public:
  Cells();

  void initiate();
  void newGeneration();

 private:
  int plate[MAX][MAX];    // 'Bricka' med celler
  int size;               // Storlek p� 'brickan'
  char form;              // Initialm�nster

  // Privata metoder
  void readSize();
  void readForm();
  void zeroit(int arr[][MAX]);
  void initX();
  void initY();
  void initZ();
  void initS();
  int neighbours(int i, int j);
  void draw(int temp[][MAX]);
};
#endif


