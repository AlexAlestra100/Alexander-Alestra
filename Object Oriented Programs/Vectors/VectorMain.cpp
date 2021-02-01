/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 2
September 22, 2019
*/

#include "Vector.h"

int main ()
{
	Vector v1(4, 6, 10);
	Vector v2(4, 5, 6);
	cout << endl;
	v1.display();
	cout << endl;
	v1.display();
	cout << endl;
	v1.div(2);
	cout << endl;
	v1.display();
	cout << endl;
	v1.mult(2);
	v1.display();
	cout << endl;

	return 0;
}
