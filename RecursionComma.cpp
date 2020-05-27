/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-08-2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

void reccom(int n)
{
    /*int x = (n % 1000);
    if(n < 1000)
    {
         return n;
    }
    else if(reccom(n / 1000) == -5)
    {
        cout << "," << setw(3) << setfill('0') << x;
    }
    else
    {
        cout << reccom(n / 1000) << "," << setw(3) << setfill('0') << x;
    }
    return -5;*/
      //base case
    if (n <= 0)
    {
        return;
    }
    //main logic
    reccom(n/1000);
    if(n >1000)
    {
        cout<<",";
        cout<<setfill('0')<<setw(3)<<(n%1000);  //stores on stack waiting for return
    }
    else
        cout<<(n%1000);  //stores on stack waiting for return
    return;
}

int main()
{
    int num = 0;
    cout << "Enter in any large number: ";
    cin >> num;
    reccom(num);
    return 0;
}
