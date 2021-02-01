/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 3
October 12, 2019
*/

#ifndef VECTOR_H_ABA

#define VECTOR_H_ABA

#include <iostream>

#include <cmath>

using namespace std;

class Vector

{

  double _x;

  double _y;

  double _z;

public:

  Vector();

  Vector(double X, double Y, double Z=0);

  Vector (const Vector&);

  ~Vector();

  Vector& operator= (const Vector&);

  Vector& operator+= (const Vector&);

  Vector& operator-= (const Vector&);

  Vector& operator*= (double);

  Vector& operator/= (double);

  friend ostream& operator<< (ostream&, const Vector&);

  friend istream& operator>> (istream&, Vector&);

  Vector operator+ (const Vector&) const;

  Vector operator- (const Vector&) const;

  Vector operator* (double) const;

  friend Vector operator* (double, const Vector&);

  Vector operator/ (double) const;

  bool operator== (const Vector&) const;

  bool operator!= (const Vector&) const;

  bool parallel(const Vector&)const;

  bool perpendicular(const Vector&)const;

  void normalize();

  double length() const;

  double dotProduct ( const Vector& )const;

  Vector crossProduct( const Vector& ) const;

  Vector operator- () const;

  Vector operator+ () const;

};

#endif
