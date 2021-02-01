/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "greenseaturtle.h"

Greenseaturtle::Greenseaturtle ( )
:Reptile()
{
  _lengthF = 5;
  r._water = true;
  r._land = false;
}
Greenseaturtle::Greenseaturtle ( const char* name )
:Reptile(name)
{
  _length = 5;
  r._water = true;
  r._land = false;
}

Greenseaturtle::Greenseaturtle ( const char* n, const GenderType& gt,
               double fc, double lf, bool wt)
:Reptile(n,gt,fc,lf,Omnivore,RawFish,true)
{
  _water = wt;
}

Greemseaturtle::Greenseaturtle ( const Greenseaturtle& r)
:Reptile(r)
{
  _lengthF = r._lengthF;
}

Greemseaturtle::~Greenseaturtle ( ) { }

Greenseaturtle& Greenseaturtle::operator= ( const Greemseaturtle& r)
{
  Reptile::operator=(r);
  _lengthF = r._lengthF;
  return *this;
}

bool Greenseaturtle::waterT ( ) const;
:Reptile(r)
{
  return _water = true;
}

void Greenseaturtle::lengthF (double w)
{
  double w = 5;
  char a = 'n';
  cout << "Enter in length? ( Y or N?)" << endl;
  cin >> a;
  if (a == 'y' || a == 'Y')
  {
   cin >> w;
  }
  _lengthF = w;
}

bool lengthinRange (double _lengthF)
{
  if (_lengthF >= 4 && _lengthF <= 5)
  return true;
  else
  return false;
}

void Greenseaturtle::display()const
{
  Mammal::display();
  cout << "Length in range: "<<((_lengthF)? "Yes":"No")<<endl;;
}

void Greemseaturtle::cageMaintenance()const
{
  cout << "1- Get diving gear on" << endl
       << "2- Jump into water tank" << endl
       << "3- Use fish net to catch any floaters" << endl
       << "4- Jump out of tank" << endl;
}
