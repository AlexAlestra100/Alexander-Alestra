/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "giraffe.h"

Giraffe::Giraffe ( )
:Mammal()
{
  _heightF = 18.7;
}
Giraffe::Giraffe ( const char* name )
:Mammal(name)
{
  _height = 18.7;
}

Giraffe::Giraffe ( const char* n, const GenderType& gt,
               double fc, double lf, bool ht)
:Mammal(n,gt,fc,lf,Herbivore,Leaves,true)
{
  _heightF = ht;
}

Giraffe::Giraffe ( const Giraffe& m)
:Mammal(m)
{
  _hieghtF = m._heightF;
}

Giraffe::~Giraffe ( ) { }

Giraffe& Giraffe::operator= ( const Giraffe& m)
{
  Mammal::operator=(m);
  _heightF = m._heightF;
  return *this;
}

double Giraffe::tempB ( ) const;
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

void Giraffe::heightF (double h)
{
  double h = 18.7;
  char a = 'n';
  cout << "Enter in height? ( Y or N?)" << endl;
  cin >> a;
  if (a == 'y' || a == 'Y')
  {
   cin >> h;
  }
  _heightF = h;
}

bool heightinRange (double _heightF)
{
  if (_heightF >= 14.1 && _heightF <= 18.7)
  return true;
  else
  return false;
}

void Giraffe::display()const
{
  Mammal::display();
  cout << "Height in range: "<<((_heightF)? "Yes":"No")<<endl;;
}

void Giraffe::cageMaintenance()const
{
  cout << "1- Stay away from Giraffe" << endl
       << "2- Never look them in the eye" << endl
       << "3- Shovel crap out" << endl
       << "4- Always have a distraction ready if you make eye contact" << endl;
}
