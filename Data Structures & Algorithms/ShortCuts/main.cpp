/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-02-2020
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void stringCopy(char *A, char *B); //done Y
bool stringCompare(char *A, char *B); //done Y
void stringConcatenation (char *A, char *B); //done Y
int stringPosition(char *A, char B); //done Y
int stringLength(char *A); //done Y

int main()
{
    char a[20],b[20];
    in >> a >> b;
    cout << a << " " << b << endl;
    stringCopy(a,b);
    cout << a << " " << b << endl;
    in >> a >> b;
    cout << stringCompare(a,b) << endl;
    in >> a >> b;
    cout << a << " " << b << endl;
    stringConcatenation(a,b);
    cout << a << " " << b << endl;
    in >> a >> b;
    cout << stringPosition(a,b) << endl;
    in >> a >> b;
    cout << stringLength(a) << endl;

    in.close();
    return 0;
}

int stringLength(char *A)
{
    int sum = 0;
    for (int i = 0; A[i] != 0; i++)
    {
        sum++;
    }
    return sum;
}

void stringCopy(char *A, char *B)
{
    if ((NULL != A) && (NULL != B))
        {
        while (NULL != *B){
        *A++ = *B++;
        }
        *A = NULL;
    }
}

void stringConcatenation(char *A, char *B)
{
    if((NULL != A) && (NULL != B)){
        while(NULL != *A){
            A++;
        }
        while(NULL != *B){
            *A++ = *B++;
        }
    *A = NULL;
    }
}

bool stringCompare(char *A, char *B)
{
    for(int i = 0; i < stringLength(A); i++)
    {
        if(A[i] != B[i])
        {
            return 0;
        }
    }
	return 1;
}

int stringPosition(char *A, char B)
{
    for(int i = 0; i < stringLength(A); i++)
    {
        if(A[i] == B)
        {
            return i;
        }
    }
    return -1;
}
