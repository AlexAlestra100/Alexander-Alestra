/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
#include "animal.h"
using namespace std;

#ifndef REPTILE_H_ABA
#define REPTILE_H_ABA

class Reptile : public  Animal
{
  bool _water;
  bool _land;

public:
  Reptile ( );
  Reptile ( const char* );
  Reptile ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool);
  Reptile ( const Reptile& );

  ~Reptile ( );

  Reptile& operator= ( const Reptile& );

  bool inWater ( ) const;
  bool onLand ( ) const;
  void both ( bool );
  void display()const;

  void cageMaintenance()const { cout << "REPTILE"; }
};
#endif


