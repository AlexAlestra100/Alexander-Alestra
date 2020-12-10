/*
Alexander Alestra
Prof. Sabzevary
CISP 430
February 27, 2020
*/

#include <iostream>

using namespace std;

struct node()
{
    int num;
    node *next;
};

void bubble(int arr[SIZE], int limit)
{
    int temp, index;

    for(; limit > 0; limit--)
    {
        for(index = 0; index < limit; index++)
        {
            if(arr[index] > arr[index + 1])
            {
                temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
            }
        }
    }
}

void selection(int arr[SIZE], int limit)
{
    int temp, indexL, index;

    for(; limit > 0; limit--)
    {
        indexL = 0;

        for(index = 1; index <= limit; index++)
        {
            if(arr[index] > arr[indexL])
            {
                indexL = index;
            }
        }
        if(limit != indexL)
        {
            temp = arr[limit];
            arr[limit] = arr[indexL];
            arr[indexL] = temp;
        }
    }
}

void insertion(int arr[])
{
    int i, j, temp;

    for(i = 1; i < SIZE; i++)
    {
        for(j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

void display(int arr[])
{
    cout << "Insertion sort steps: ";

    for(int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    return 0;
}
