/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 2
September 22, 2019
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

  Vector(double X, double Y, double Z = 0.0);

  void display() const;

  void add(const Vector&);

  void sub(const Vector&);

  void mult(const double&);

  void div(const double&);

  void normalize();

  double length()const;

};

#endif
