/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-04-2020
*/

#include <iostream>

using namespace std;

const int nsize = 8;
const int num = 10;
int arr1[nsize] = {170, 45, 75, 90, 2, 802, 24, 66};
int arr2[nsize], arr3[nsize], arr4[nsize], arr5[nsize];

struct node
{
    int data;
    node *next;
};

struct nodeQ
{
    node *front;
    node *rear;
};

void enqueue(nodeQ &q, int data)
{
    struct node *nn = new node;

    nn->data = data;
    nn->next = nullptr;

    if(!q.rear)
    {
        q.front = q.rear = nn;
        cout << "First" << endl;
    }
    else
    {
        q.rear->next = nn;
        q.rear = nn;
        cout << "Next" << endl;
    }
}

int dequeue(nodeQ &q)
{
    struct node *temp;

    int val = q.front->data;

    if(q.front)
    {
        temp = q.front;
        q.front = q.front->next;
        delete temp;
        if(!q.front)
        {
            q.rear = nullptr;
        }
    }
    cout << val << " ";
    return val;
}

void forw()
{
    int away = 0;
    int fs, ss, ts;
    nodeQ q[num];

    for(int i = 0; i < num; i++)
    {
        q[i].front = nullptr;
        q[i].rear = nullptr;
    }

    cout << "First" << endl << endl;
    for(int j = 0; j < nsize; j++)
    {
        fs = (arr1[j] % 10) / 1;
        cout << j << " " << fs << " ";
        enqueue(q[fs], arr1[j]);
    }
    cout << endl;
    for(int j = 0; j < num; j++)
    {
        while(q[j].rear)
        {
            arr2[away] = dequeue(q[j]);
            away++;
        }
    }
    cout << endl;
    cout << "Done 1!" << endl << endl;

    away = 0;
    cout << "Second" << endl;
    for(int j = 0; j < nsize; j++)
    {
        ss = (arr2[j] % 100) / 10;
        cout << j << " " << ss << " ";
        enqueue(q[ss], arr2[j]);
    }
    cout << endl;
    for(int j = 0; j < num; j++)
    {
        while(q[j].rear)
        {
            arr3[away] = dequeue(q[j]);
            away++;
        }
    }
    cout << endl;
    cout << "Done 2!" << endl << endl;

    away = 0;
    cout << "Third" << endl;
    for(int j = 0; j < nsize; j++)
    {
        ts = (arr3[j] % 1000) / 100;
        cout << j << " " << ts << " ";
        enqueue(q[ts], arr3[j]);
    }
    cout << endl;
    for(int j = 0; j < num; j++)
    {
        while(q[j].rear)
        {
            arr4[away] = dequeue(q[j]);
            away++;
        }
    }
    cout << endl;
    cout << "Done 3!" << endl << endl;

    cout << "Sorted" << endl;
    for(int i = 0; i < nsize; i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl;
    cout << "Done 4!" << endl << endl;
}

void backw()
{
    cout << "Reverse" << endl;
    int j = nsize - 1;

    for(int i = 0; i < nsize; i++)
    {
        arr5[j--] = arr4[i];
    }
    for(int i = 0; i < nsize; i++)
    {
        cout << arr5[i] << " ";
    }
    cout << endl;
    cout << "Done 5!" << endl;
}

int main()
{

    for(int i = 0; i < nsize; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl << endl;

    forw();

    backw();

    return 0;
}
