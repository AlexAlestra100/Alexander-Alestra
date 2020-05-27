/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-09-2020
*/

#include <iostream>
#include <stack>

using namespace std;

void binary(int inp);
void hexd(int inp);

int main()
{

    int input = 0;
    cout << "Enter a non negative integer:" << " ";
    cin >> input;
    cout << endl;

    binary(input);

    hexd(input);
}


void binary(int inp)
{
    stack<int> mstack;
    int bi = 0; //binary digit
    int d = inp; //divide variable.
    do{
        bi = d % 2;
        d = d / 2;
        mstack.push(bi);
    }while(d > 0);

    while(!mstack.empty())
    {
        cout << mstack.top();
        mstack.pop();
    }
}

void hexd(int inp)
{
    cout << endl;

    stack<int> nstack;
    int h = 0; //hex digit
    int d = inp; //divide variable.
    do{
        h = d % 16;
        d = d / 16;
        nstack.push(h);
    }while(d > 0);

    while(!nstack.empty())
    {
        if(nstack.top() < 10)
        {
            cout << nstack.top();
        }
        if(nstack.top() > 9)
        {
            if(nstack.top() == 10)
            {
                cout << "A";
            }
            if(nstack.top() == 11)
            {
                cout << "B";
            }
            if(nstack.top() == 12)
            {
                cout << "C";
            }
            if(nstack.top() == 13)
            {
                cout << "D";
            }
            if(nstack.top() == 14)
            {
                cout << "E";
            }
            if(nstack.top() == 15)
            {
                cout << "F";
            }
        }
        nstack.pop();
    }
}
