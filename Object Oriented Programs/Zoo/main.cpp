/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/


#include <iostream>
using namespace std;
#include "animal.h"
#include "mammal.h"
#include "reptile.h"
#include "giraffe.h"
#include "raccoon.h"
#include "greenseaturtle.h"
#include "crocodilia.h"

int main()
{
	Giraffe g("Bob");
	mammal m("Bobo");

	m.display();
	cout << endl;
	m.cageMaintenance();
	cout << endl;

	Animal* aptr = &g;
	Guraffe* gptr = &g;

	cout << aptr->name() << endl;
	cout << eptr->name() << endl;

	return 0;
}
