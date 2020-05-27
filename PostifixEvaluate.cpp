/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-16-2020
*/

#include <iostream>
#include <fstream>

using namespace std;

int size()
{
    char i;
    ifstream inf;
    inf.open("input.txt");
    int size = 0;
    while(inf >> i)
    {
        ++size;
    }
    inf.close();
    return size;
}

int main()
{
    char in[size()];
    int out[size()];

    ifstream inF;
    inF.open("input.txt");
    for(int i = 0; i < size(); i++)
    {
        inF >> in[i];
    }
    inF.close();

    int x = 0;
    int now = 3;
    int then = 0;
    for(int i = 0; i < size();i++)
    {
        if(isdigit(in[i]))
        {
            x = static_cast<int>(in[i]) - 48;
            out[i] = x;
        }
        else if(in[i] == '*' || in[i] == '/')
        {
            if(now > then)
            {
                if(in[i] == '*')
                {
                    x = out[i-2] * out[i-1];
                }
                else
                {
                    x = out[i-2] / out[i-1];
                }
            }
        }
        else if(in[i] == '+' || in[i] == '-')
        {
            if(in[i] == '+')
            {
                x = out[i-2] + out[i-1];
            }
            else
            {
                x = out[i-2] - out[i-1];
            }
        }
    }
    cout << x;
    return 0;
}
