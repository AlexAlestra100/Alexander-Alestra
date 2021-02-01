
/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 3
October 12, 2019
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

Vector::Vector (const Vector& v)
: _x(v._x), _y(v._y), _z(v._z)
{}

Vector::~Vector(){}

Vector& Vector::operator= (const Vector& v)
{
	if (this == &v) return *this;

	_x = v._x;
	_y = v._y;
	_z = v._z;

	return *this;
}

Vector& Vector::operator+= (const Vector& v)
{
        _x += v._x;
        _y += v._y;
        _z += v._z;

        return *this;
}

Vector& Vector::operator-= (const Vector& v)
{
	return operator+= (-v);
}

Vector& Vector::operator*= (double d)
{
	_x *= d;
        _y *= d;
        _z *= d;

	return *this;
}

Vector& Vector::operator/= (double d)
{
	return operator*= (1.0/d);
}

ostream& operator<< (ostream& os, const Vector& v)
{
	os << '<' << v._x << ',' << v._y << ',' << v._z << '>';

	return os;
}

istream& operator>> (istream& is, Vector& v)
{
	char c;

	is >> c >> v._x >> c >> v._y >> c >> v._z >> c;

	return is;
}

Vector Vector::operator+ (const Vector& v) const
{
	return Vector(*this)+=v;
}

Vector Vector::operator- (const Vector& v) const
{
        return Vector(*this)-=v;
}

Vector Vector::operator* (double d) const
{
	return Vector(*this) *= d;
}

Vector operator* (double d, const Vector& v)
{
	return v*d;
}

Vector Vector::operator/ (double d) const
{
	return Vector(*this) /= d;
}

bool Vector::operator== (const Vector& v) const
{
	return (_x == v._x) && (_y == v._y) && (_z == v._z);
}

bool Vector::operator!= (const Vector& v) const
{
	return !(*this == v);
}

bool Vector::parallel (const Vector& v) const
{
	return (dotProduct(v) == 1);
}

bool Vector::perpendicular(const Vector& v) const
{
 	return (dotProduct(v) == 0);
}

void Vector::normalize()
{
	operator/=(length());
}

double Vector::length() const
{
	return sqrt(_x * _x + _y * _y + _z * _z);
}

double Vector::dotProduct ( const Vector& v)const
{
	return (_x * v._x) + (_y * v._y) + (_z * v._z);
}

Vector Vector::crossProduct (const Vector& v)const
{
	return Vector((_y * v._z - _z * v._y),(-_x * v._z + _z * v._x),(_x * v._y - _y * v._x));
}

Vector Vector::operator- () const
{
	return *this * -1;
}

Vector Vector::operator+ () const
{
	return *this;
}
