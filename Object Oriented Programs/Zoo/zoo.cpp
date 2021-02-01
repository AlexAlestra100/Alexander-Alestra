/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 4
November 7, 2019
*/

#include <iostream>
using namespace std;
#include "zoo.h"

char main_menu();

int main()
{

	main_menu();
	Zoo z;

	return 0;
}


Zoo::~Zoo()
{
	for (unsigned i=0; i <_num_animals; ++i)
		delete zoo;
}

void Zoo::_add_animal()
{
	if (_num_animals >= MAXX_ANIMALS)
	{
		cout << "Sorry. The zoo is full\n";
		return;
	}
	cout << "Select an animal to add:\n";
	     << " 1: Giraffe\n"
	     << " 2: Raccoon\n";
	     << " 3: Crocodilia\n";
	     << " 4: Green Sea Turtle\n";

	string nameF;
	cout << "Enter in a name: " << endl;
	cin >> nameF;

	bool addded = true;
	char choice;
	cin >> choice;
	switch (choice)
	{
		case '1' : _add_giraffe(); break;
		case '2' : _add_raccoon(); break;
		case '3' : _add_crocodilia(); break;
		case '4' : _add_greenseaturtle(); break;
		default: cout << "Bad choice! IDIOT\n";  added = false;
	};
	if (added)
		++_num_animals;
}

char main_menu()
{
	cout << "\n1: Place a new animal into the Zoo if there is room.\n"
	     << "2: Do cage maintenance for the Zoo.\n"
	     << "3: Feed the animals.\n"
	     << "4: Display all the animals in he Zoo.\n"
	     << "5: Exit the simulation.\n"

	char choice;
	cin >> choice;
	switch (choice)
	{
		case '1' : _add_animal(); break;
		case '2' : _do_cagemaintanence(); break;
		case '3' : _feed_animals(); break;
		case '4' : _display() const; break;
		case '5' : exit(0);
}

void Zoo::_do_cagemaintenance()
{
	cout << "Which animal are you cleaning up after?\n";

	cout << "1: Giraffe\n";
	     << "2: Raccoon\n";
	     << "3: Crocodilia\n";
	     << "4: Turtle\n";

	giraffe g;
	raccoon r;
	crocodilia c;
	greenseaturtle t;
	char choice;
        cin >> choice;
        switch (choice)
        {
                case '1' : g.cageMaintenance;  break;
                case '2' : r.cagemaintenance; break;
                case '3' : c.cagemaintenance; break;
                case '4' : t.cagemaintenance;  break;
}

void Zoo::_feed_animals()
{
        cout << "Which animal are you feeding?\n";

        cout << "1: Giraffe\n";
             << "2: Raccoon\n";
             << "3: Crocodilia\n";
             << "4: Turtle\n";

        giraffe g;
        raccoon r;
        crocodilia c;
        greenseaturtle t;
        char choice;
        cin >> choice;
        switch (choice)
        {
                case '1' : g.DietType;  break;
                case '2' : r.DietType; break;
                case '3' : c.DietType; break;
                case '4' : t.DietType;  break;
}

void Zoo:: _add_giraffe()
{
	Giraffe* g = new Giraffe (nameF" the Giraffe");
	_zoo [_num_animals] = g;
}

void Zoo:: _add_raccoon()
{
        Raccoon* r = new Raccoon (nameF" the Raccoon");
        _zoo [_num_animals] = r;
}

void Zoo:: _add_crocodilia()
{
        Crocodilia* c = new Crocodilia (nameF" the Crocodilia");
        _zoo [_num_animals] = c;
}

void Zoo:: _add_greenseaturtle()
{
        Turtle* t = new Turtle (nameF" the Green Sea Turtle");
        _zoo [_num_animals] = t;
}

void Zoo::_display() const
{
	for (unsigned i=0; i < _num_animals; ++i)
	{
		_zoo[i] -> display();
		cout << endl;
	}
}
