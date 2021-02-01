/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
#include "reptile.h"
using namespace std;

#ifndef GREENSEATURTLE_H_ABA
#define GREENSEATURTLE_H_ABA

class Greenseaturtle : public Reptile
{

  double _lengthF;

public:
  Greenseaturtle ( );
  Greenseaturtle ( const char* );
  Greenseaturtle ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool lt);
  void Name(const char* c) { cout <<"Greenseaturtle: "<< c << endl;}
  Greenseaturtle ( const Greenseaturtle& );

  ~Greenseaturtle ( );

  Greenseaturtle& operator= ( const Greenseaturtle& );

  bool waterT ( ) const;
  void lengthF (double );
  bool lengthinRange (double );

  void display()const;
  void cageMaintenance()const { cout << "GREENSEATURTLE"; }
};

#endif
