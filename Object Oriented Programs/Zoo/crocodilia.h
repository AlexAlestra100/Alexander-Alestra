/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
#include "reptile.h"
using namespace std;

#ifndef CROCODILIA_H_ABA
#define CROCODILIA_H_ABA

class CROCODILIA : public Reptile
{

  string _type;

public:
  Crocodilia ( );
  Crocodilia ( const char* );
  Crocodilia ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool lt);
  void Name(const char* c) { cout <<"Crocodilia: "<< c << endl;}
  Crocodilia ( const Crocodilia& );

  ~Crocodilia ( );

  Crocodilia& operator= ( const Crocodilia& );

  bool waterT ( ) const;
  void crocType (string );

  void display()const;
  void cageMaintenance()const { cout << "CROCODILIA"; }
};

#endif

