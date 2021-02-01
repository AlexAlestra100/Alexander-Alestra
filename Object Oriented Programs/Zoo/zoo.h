/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include "animal.h"
#include "mammal.h"
#include "reptile.h"
#include "giraffe.h"
#include "raccoon.h"
#include "crocodilia.h"
#include "greenseaturtle.h"

#ifndef _ZOO_H_ABA_
#define _ZOO_H_ABA_

const unsigned MAX_ANIMALS = 10;

class Zoo
{
	Animal* _zoo[MAX_ANIMALS];
	unsigned _num_animals;
	void _add_animal();
	void _add_giraffe();
	void _add_raccoon();
	void _add_crocodilia();
	void _add_greenseaturtle();
	void _do_cagemaintenance();
	void _feed_animals();
	void _display() const;

public:
	zoo();
	~zoo();
};

#endif
