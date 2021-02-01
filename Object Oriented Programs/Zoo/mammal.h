/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
#include "animal.h"
using namespace std;

#ifndef MAMMAL_H_ABA
#define MAMMAL_H_ABA

class Mammal : public  Animal
{
  double _temp;
  bool _temp_range;

public:
  Mammal ( );
  Mammal ( const char* );
  Mammal ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool);
  Mammal ( const Mammal& );

  ~Mammal ( );

  Mammal& operator= ( const Mammal& );

  double bodyTemp ();
  double tempH (double ) const;
  double tempL (double ) const;

  bool tempRange ( ) const;
  void tempRange ( bool );
  void display()const;

  void cageMaintenance()const { cout << "MAMMAL"; }
};
#endif
