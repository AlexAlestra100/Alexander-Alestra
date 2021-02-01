
/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 2
September 22, 2019
*/

#include "Vector.h"

Vector::Vector()
{
	_x = 0;
	_y = 0;
	_z = 0;
}

Vector::Vector(double X, double Y, double Z)
{
	_x = X;
	_y = Y;
	_z = Z;
}

void Vector::display() const
{
	cout << "<" << _x << ", " << _y << ", " << _z << ">";
}

void Vector::add(const Vector& v)
{
	_x += v._x;
        _y += v._y;
        _z += v._z;
}

void Vector::sub(const Vector& v)
{
	add(Vector(-v._x, -v._y, -v._z));
}

void Vector::mult(const double& d)
{
	_x *= d;
	_y *= d;
	_z *= d;
}

void Vector::div(const double& m)
{
	_x /= m;
	_y /= m;
	_x /= m;
}

void Vector::normalize()
{
	div(length());
}

double Vector::length() const
{
	return sqrt(_x * _x + _y * _y + _z * _z);
}
