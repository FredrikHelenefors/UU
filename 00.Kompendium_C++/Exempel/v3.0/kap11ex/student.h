// Filnamn : .../student.h
#ifndef __student__
#define __student__
#include "person.h"

class student : public person {
 public:
  student();                        // Defaultkonstruktor
  student( string fn, string ln, 
	   string edu );            // �verlagrad konstruktor 
  ~student();                       // Destructor

  void report();                    // Skriv ut data
  void input();                     // L�s in
  void newCourse( string cName, int grade, 
		  double points );  // L�gg till ny kurs
  double totalPoints();             // Returnera totalpo�ng
  int lastgrade();                  // Returnera senaste betyg

 protected:
  double totPoints;
  int lastGrade;
  string education; 
  string lastCourse; 
};
#endif
