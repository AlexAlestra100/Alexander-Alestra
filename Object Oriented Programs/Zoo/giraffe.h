/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
#include "mammal.h"
using namespace std;

#ifndef GIRAFFE_H_ABA
#define GIRAFFE_H_ABA

class Giraffe : public Mammal
{

  double _heightF;

public:
  Giraffe ( );
  Giraffe ( const char* );
  Giraffe ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool ht);
  void Name(const char* c) { cout <<"Giraffe: "<< c << endl;}
  Giraffe ( const Giraffe& );

  ~Giraffe ( );

  Giraffe& operator= ( const Giraffe& );

  double tempB ( ) const;
  void heightF (double );
  bool heightinRange (double );

  void display()const;
  void cageMaintenance()const { cout << "GIRAFFE"; }
};

#endif
