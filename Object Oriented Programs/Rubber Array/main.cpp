#include <iostream>
#include <iomanip>
#include <fstream>
#include "RubberArray.h"

using namespace std;

int main()
{
    RubberArray<double> ra(-5);
    unsigned MAX = 10;   //for first day code
    double d[MAX];
    for (unsigned i = 0; i < MAX; ++i)
        d[i] = i * i;

    RubberArray<double> ra(d, MAX, -10);

    RubberArray<int> raI;

    cout << raI[-4] << endl;

    /*unsigned MAX = 100;  //for when my array is finished

    RubberArrray<int> ra;
    for (unsigned i = 0; i < MAX; ++i)
    {
        ra += i +1;
    }

    cout << ra << endl;
    cout << ra(5, 18) << endl;
    while (ra.Length() != 0)
    {
        ra.delete(0);
        cout << ra << endl;
        cin.get();
    }

    cout << ra <<endl;
    ofstream fout ("test.txt", ios::out|ios::binary);
    ra.write(fout);
    fout.close();

    ifstream fin ("test.txt", ios::in|ios::binary)

    RubberArray<int> ra2;
    ra2.read(fin);
    cout << ra2 << endl;*/

    return 0;
}
