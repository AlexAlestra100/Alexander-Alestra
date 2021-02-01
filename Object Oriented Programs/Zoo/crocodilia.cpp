/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "crocodilia.h"

Crocodilia::Crocodilia ( )
:Reptile()
{
  _type = "Crocodile";
  r._water = true;
  r._land = false;
}
Crocodilia::Crocodilia ( const char* name )
:Reptile(name)
{
  _type = "Crocodile";
  r._water = true;
  r._land = false;
}

Crocodilia::Crocodilia ( const char* n, const GenderType& gt,
               double fc, double lf, bool wt)
:Reptile(n,gt,fc,lf,Carnivore,RawMeat,true)
{
  r._water = wt;
}

Crocodilia::Crocodilia ( const Crocodilia& r)
:Reptile(r)
{
  _type = r._type;
}

Crocodilia::~Crocodilia ( ) { }
Crocodilia& Crocodilia::operator= ( const Crocodilia& r)
{
  Reptile::operator=(r);
  _type = r._type;
  return *this;
}

bool Crocodilia::waterT ( ) const;
:Reptile(r)
{
  return r._water = true;
}

void Crocodilia::crocType (string _type)
{
  cout << "Enter in crocodilia type {CrocTypeUnknown, Crocodile, Alligator, Caiman, Gharial}" << endl;
  cin >> _type;
}

void Crocodilia::display()const
{
  Mammal::display();
  cout << "Crocadilia type: "<< _type <<endl;;
}

void Crocodilia::cageMaintenance()const
{
  cout << "1- Get Steve Irwin to go in the cage" << endl
       << "2- Do not go into the cage with out Steve" << endl
       << "3- While Steve keeps the croc's busy clean out the area" << endl
       << "4- Run out of cage as fast as possible" << endl;
}

