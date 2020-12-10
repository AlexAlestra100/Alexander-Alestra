/*
Alexander Alestra
Prof. Tak
CISP 440
4-27-2020
*/
#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

vector<char> del(vector<char> arr, int i)
{
    arr.erase(arr.begin() + i);

    return arr;
}

vector<char> perm(vector<char> arr, int tr, int ch)
{
    vector<char> result;

    if(tr == 1)
    {
        result = arr;
        cout << endl;
        return result;
    }
    else
    {
        for(int i = 0; i < ch; i++)
        {
            for(int j = 0; j < ch - 1; j++)
            {
                cout << arr[i] << perm(del(arr, i), tr - 1, ch - 1)[j];
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    int trial = 0;
    int choice = 0;

    if(argc == 3)
    {
        trial = atoi(argv[1]);
        choice = atoi(argv[2]);
        cout << "There are " << trial << " trials and " << choice << " choices.";
    }
    else
    {
        cout << "Need a number of trial and choices.";
        return 0;
    }

    char start = 'a';
    cout << endl;
    vector<char> arr(choice);

    if(choice > 26 || trial > 26)
    {
        cout << "Too large of numbers!";
        return 0;
    }
    else if(choice == 1)
    {
        cout << start;
    }

    for(int i = 0; i < choice; i++)
    {
        arr[i] = start++;
    }
    cout << endl;
    for(int j = 0; j < choice; j++)
    {
        cout << arr[j];
    }
    cout << endl << "-----" << endl;

    perm(arr, trial, choice);

    return 0;
}
