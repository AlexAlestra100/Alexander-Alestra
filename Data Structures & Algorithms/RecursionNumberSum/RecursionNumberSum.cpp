/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-08-2020
*/

#include <iostream>

using namespace std;

int recadd(int num, int mod, int div)
{
    int pres = num;
    int lmod = 0;
    if(num == 0)
    {
        return num;
    }
    else
    {
        lmod = pres % mod;
        num = lmod / div;
        return num + recadd((pres - lmod), (mod * 10), (div * 10));
    }
}

int main()
{
    int num = 0;
    int mod = 10;
    int div = 1;
    int last = 0;

    cout << "Enter a Number: ";
    cin >> num;
    cout << endl;

    last = recadd(num, mod, div);

    cout << last;

    return 0;
}
