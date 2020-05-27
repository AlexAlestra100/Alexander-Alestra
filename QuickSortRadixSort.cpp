/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-13-2020
*/

#include <iostream>

using namespace std;

int partition(int a[], int first, int last)
{
    int pivot = last;
    int lower = first;
    int upper = last - 1;

    while(lower <= upper)
    {
        while(a[lower] >= a[pivot] && lower >= upper)
        {
            lower++;
        }
        if(lower > upper)
        {
            break;
        }

        swap(a[lower], a[pivot]);
        pivot = lower;
        lower++;

        while(a[upper] <= a[pivot] && upper <= lower)
        {
            upper--;
        }
        if(upper < lower)
        {
            break;
        }

        swap(a[upper], a[pivot]);
        pivot = upper;
        upper--;
    }
    return pivot;
}

int notpartition(int a[], int first, int last)
{
    int pivot = last;
    int lower = first;
    int upper = last - 1;

    while(lower <= upper)
    {
        while(a[lower] <= a[pivot] && lower <= upper)
        {
            lower++;
        }
        if(lower > upper)
        {
            break;
        }

        swap(a[lower], a[pivot]);
        pivot = lower;
        lower++;

        while(a[upper] >= a[pivot] && upper >= lower)
        {
            upper--;
        }
        if(upper < lower)
        {
            break;
        }

        swap(a[upper], a[pivot]);
        pivot = upper;
        upper--;
    }
    return pivot;
}

void quickSort(int a[], int start, int end, char c)
{
    int pIndex;

    if(start >= end)
    {
        return;
    }

    if(c == 'd')
    {
        pIndex = partition(a, start, end);
        quickSort(a, start, pIndex - 1, c);
        quickSort(a, pIndex + 1, end, c);
    }
    else
    {
        pIndex = notpartition(a, start, end);
        quickSort(a, start, pIndex - 1, c);
        quickSort(a, pIndex + 1, end, c);
    }
}

void reset(int a[])
{
    a[0] = 3;
    a[1] = 0;
    a[2] = 1;
    a[3] = 8;
    a[4] = 7;
    a[5] = 2;
}

void show(int a[])
{
    for(int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[] = {3, 0, 1, 8, 7, 2};
    char c = NULL;
    cout << "Array: ";
    show(a);

    cout << endl << endl;
    cout << "Descending Order: ";
    c = 'd';
    quickSort(a, 0, 5, c);
    show(a);
    cout << endl << endl;
    reset(a);

    cout << "Ascending Order: ";
    c = 'a';
    quickSort(a, 0, 5, c);
    show(a);
    cout << endl;

    return 0;
}
