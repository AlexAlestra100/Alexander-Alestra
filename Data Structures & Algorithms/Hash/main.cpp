/*
Alexander Alestra
Prof. Sabzevary
CISP 430
05-10-2020
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int isPrime(int ars)
{
    if(ars <= 2)
    {
        return 1;
    }
    else if(ars <= 3)
    {
        return 2;
    }
    else if(ars <= 5)
    {
        return 3;
    }
    else if(ars <= 7)
    {
        return 5;
    }
    else
    {
        return 7;
    }
}

void lin(int SA[], int ars, int num, int *col, bool *y)
{
    for(int i = 0; i < ars; i++)
    {
        if(!SA[i])
        {
            SA[i] = num;
            return;
        }
        else if(SA[i] == num)
        {
            cout << endl << "Found at index " << i << "." << endl;
            *y = true;
            return;
        }
    }
}

void quad(int SA[], int ars, int num, int *col, bool *y)
{
    for(int i = 0; i < 3; i++)
    {
        int index =(num * pow(i, 2));
        index = index % 10;
        if(!SA[index])
        {
            SA[index] = num;
            return;
        }
        else if(SA[index] == num)
        {
            cout << endl << "Found at index " << index << "." << endl;
            *y = true;
            return;
        }
        *col += 1;
    }
    lin(SA, ars, num, &*col, &*y);
}

void dob(int SA[], int ars, int num, int *col, int in, bool *y)
{
   int index = num % isPrime(ars);
   index = isPrime(ars) - index;
   index = in + index;
   if(!SA[index])
   {
       SA[index] = num;
   }
   else if(SA[index] == num)
   {
       cout << endl << "Found at index " << index << "." << endl;
       *y = true;
       return;
   }
   else
   {
        *col += 1;
        quad(SA, ars, num, &*col, &*y);
   }
}

void mod(int SA[], int ars, int num, int *col, bool *y)
{
    int index = num % 10;
    if(!SA[index])
    {
        SA[index] = num;
    }
    else if(SA[index] == num)
    {
        cout << endl << "Found at index " << index << "." << endl;
        *y = true;
        return;
    }
    else
    {
        *col += 1;
        dob(SA, ars, num, &*col, index, &*y);
    }
}

int main()
{
    string an;
    int SA[10] = {NULL};
    int num, se, col = 0, ars = 0;
    bool y = false;
    ifstream inF;

    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> num;
        ars++;
    }
    inF.close();

    if(ars > 7)
    {
        cout << "Too many digits, can only have 70% of the array filled so 70% of 10." << endl;
        cout << "You can only have up to 7 digits in the list." << endl;
        return 0;
    }

    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> num;
        cout << "Number: " << num << " ";
        mod(SA, ars, num, &col, &y);
        cout << "Collisions: " << col << endl;
        col = 0;
    }
    inF.close();

    cout << endl << "List: ";
    for(int j = 0; j < 10; j++)
    {
        cout << SA[j] << " ";
    }

    cout << endl << endl << "Would you like to search for a number? Type yes or no: ";
    cin >> an;
    cout << endl;
    if(an == "yes")
    {
        cout << "Which number would you like to search for: ";
        cin >> se;
        mod(SA, ars, se, &col, &y);
        if(y == false)
        {
            cout << endl << "Item not in list." << endl;
        }
    }
    return 0;
}
