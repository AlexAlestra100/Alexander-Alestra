/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "raccoon.h"

Raccoon::Raccoon ( )
:Mammal()
{
  _weightB = 2.6;
}
Giraffe::Giraffe ( const char* name )
:Mammal(name)
{
  _weightB = 2.6;
}

Raccoon::Raccoon ( const char* n, const GenderType& gt,
               double fc, double lf, bool ht)
:Mammal(n,gt,fc,lf,Omnivor,GrubsNGrass,true)
{
  _weightB = wt;
}

Raccoon::Raccoon ( const Raccoon& m)
:Mammal(m)
{
  _weightB = m._weightB;
}

Raccoon::~Raccoon ( ) { }

Raccoon& Raccoon::operator= ( const Raccoon& m)
{
  Mammal::operator=(m);
  _weightB = m._weightB;
  return *this;
}

double Raccoon::tempB ( ) const;
:Mammal(m)
{
  m._temp = 98;
  char a = 'n';
  cout << "Enter in temp? ( Y or N?)" << endl;
  cin >> a;
  if (a == 'y' || a == 'Y')
  {
   cin >> m._temp;
  }
}

void Giraffe::weightB (double w)
{
  double w = 2.6;
  char a = 'n';
  cout << "Enter in height? ( Y or N?)" << endl;
  cin >> a;
  if (a == 'y' || a == 'Y')
  {
   cin >> w;
  }
  _weightB = w;
}

bool weightinRange (double _weightB)
{
  if (_weightB >= 2.1 && _weightB <= 2.6)
  return true;
  else
  return false;
}

void Raccoon::display()const
{
  Mammal::display();
  cout << "Weight in range: "<<((_weightB)? "Yes":"No")<<endl;;
}

void Raccoon::cageMaintenance()const
{
  cout << "1- Cage is always clean" << endl
       << "2- If you find a raccoon it will escape" << endl
       << "3- Don't try to catch one or it will attack" << endl
       << "4- Keep all trash can lids locked" << endl;
}

