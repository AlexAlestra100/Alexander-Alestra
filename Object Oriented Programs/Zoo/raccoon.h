/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
#include "mammal.h"
using namespace std;

#ifndef RACCOON_H_ABA
#define RACCOON_H_ABA

class Raccoon : public Mammal
{

  double _weightB;

public:
  Raccoon ( );
  Raccoon ( const char* );
  Raccoon ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool wt);
  void Name(const char* c) { cout <<"Raccoon: "<< c << endl;}
  Raccoon ( const Raccoon& );

  ~Raccoon ( );

  Raccoon& operator= ( const Raccoon& );

  double tempB ( ) const;
  void weightB (double );
  bool weightinRange(double );

  void display()const;
  void cageMaintenance()const { cout << "RACCOON"; }
};

#endif

