/*
Alexander Alestra
Prof. Sabzevary
CISP 430
05-03-2020
*/
#include <iostream>
#include <fstream>

using namespace std;

struct que
{
    int item;
    que* next;
};

void enqueue(int item, que *&front, que *&rear)
{
    que* newNode = new que;
    newNode->item = item;
    newNode->next = NULL;
    if(rear)
    {
        rear->next = newNode;
        //rear = newNode;
    }
    else
    {
        front = rear = newNode;
    }
}

void dequeue(que *&front, que *&rear)
{
    que* temp;

    if(front)
    {
        temp = front;
        front = front->next;
        delete temp;

        if(!front)
        {
            rear = NULL;
        }
    }
}

void siftUp(int nodeIndex, int a[], int HS)
{
    if(HS >= 0)
    {
        if(a[(nodeIndex - 1) / 2] > a[nodeIndex])
        {
            swap(a[(nodeIndex - 1) / 2], a[nodeIndex]);
            HS--;
            siftUp(((nodeIndex - 1) / 2), a, HS);
        }
    }
}

void siftDown(int parent, int a[], int HS)
{
    int L = a[(2 * parent) + 1];
    int R = a[(2 * parent) + 2];
    int Li = (2 * parent) + 1;
    int Ri = (2 * parent) + 2;
    if((2 * parent) + 1 < HS)
    {
        if(L < R)
        {
            if(a[parent] > L)
            {
                int temp = a[parent];
                a[parent] = a[(2 * parent) + 1];
                a[(2 * parent) + 1] = temp;
                siftDown(Li, a, HS);
            }
        }
        else if(R < L)
        {
            if(a[parent] > R)
            {
                int temp = a[parent];
                a[parent] = a[(2 * parent) + 2];
                a[(2 * parent) + 2] = temp;
                siftDown(Ri, a, HS);
            }
        }
    }
}

void level(int a[], int st, int hs)
{
    que *currentLevel, *nextLevel, *crear, *nrear;
    currentLevel = nextLevel = crear = nrear = NULL;

    enqueue(a[st], currentLevel, crear);
    while(currentLevel)
    {
        cout << currentLevel->item << " ";
        dequeue(currentLevel, crear);
        if((2 * st) + 1 < hs)
        {
            enqueue(a[(2 * st) + 1], nextLevel, nrear);
            enqueue(a[(2 * st) + 2], nextLevel, nrear);
            st++;
        }
        if(currentLevel == NULL)
        {
            currentLevel = nextLevel;
            crear = nrear;
            nextLevel = NULL;
            nrear = NULL;
            cout << endl;
        }
    }
}

int main()
{
    int num = 0, i = 0, hs = 10;
    int a[hs] = {0};
    ifstream inF;
    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> num;
        cout << "Inserting number: " << num << endl;
        a[i] = num;
        siftUp(i, a, i);
        i++;
    }
    inF.close();
    hs = i;
    cout << endl;
    for(int d = 0; d < hs; d++)
    {
        cout << a[d] << " ";
    }
    cout << endl << endl;
    for(int j = 0; j < 5; j++)
    {
        cout << "Delete: " << j+1 << endl;
        a[j] = a[hs - 1];
        cout << "a[0]: " << a[j] << endl;
        siftDown(j, a, hs);
        a[hs - 1] = NULL;
        hs--;
    }
    cout << endl << endl;

    level(a, 0, hs);

    return 0;
}
