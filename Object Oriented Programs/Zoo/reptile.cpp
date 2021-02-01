/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "reptile.h"

Reptile::Reptile ( )
:Animal()
{
  _water = true;
  _land = true;
}
Reptile::Reptile ( const char* name )
:Animal(name)
{
  _water = true;
  _land = true;
}
Bird::Bird ( const char* n, const GenderType& gt,
             double fc, double lf, const DietType& dt,
             const FeedType& ft, bool df)
:Animal(n,gt,fc,lf,dt,ft)
{
  _water = df;
  _land = df;
}
Reptile::Reptile ( const Reptile& r)
:Animal(r)
{
  _water = r._water;
  _land = r._land
}

Reptile::~Reptile ( ) { }

Reptile& Reptile::operator= ( const Reptile& r)
{
  Animal::operator=(r);
  _water = r._water;
  _land = r._land
  return *this;
}

bool Reptile::inWater ( ) const
{
  return _water;
}

bool Reptile::onLand ( ) const
{
  return _land;
}

void Reptile::both ( bool df )
{
  _water = df;
  _land = df;
}

void Reptile::display()const
{
  Animal::display();
  cout << "In water: "<<((_water)?"Yes":"No") << endl;
  cout << "On land: "<<((_land)?"Yes":"No") << endl;
}

