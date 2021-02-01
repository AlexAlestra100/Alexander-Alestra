/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "mammal.h"

Mammal::Mammal ( )
:Animal()
{
  _temp_range = true;
}

Mammal::Mammal ( const char* name)
:Animal(name)
{
  _temp_range = true;
}

Mammal::Mammal( const char* n, const GenderType& gt,
             double fc, double lf, const DietType& dt,
             const FeedType& ft, bool tr)
:Animal(n,gt,fc,lf,dt,ft)
{
  _temp_range = tr;
}

Mammal::Mammal ( const Mammal& m)
:Animal(m)
{
  _temp_range = m._temp_range;
}

Mammal::~Mammal () { }

Mammal& Mammal::operator= (const Mammal& m)
{
  Animal::operator=(m);
  _temp_range = m._temp_range;
  return *this;
}

void Mammal::bodyTemp(double _temp)
{
  return _temp;
}

double Mammal::tempH (double highT) const
{
  if(_temp >= 97)

  return highT = _temp;
}

double Mammal::TempL (double lowT) const
{
  if (_temp < 97)

  return lowT = _temp;
}

bool Mammal::tempRange ( ) const
{
 return _temp_range;
}

void Mammal::tempRange (bool tr)
{
  _temp_range = tr;
}

void Mammal::display()const
{
  Animal::display();
  cout << "Temp in Range: "<<((_temp_range)?"Yes":"No") << endl;
}

