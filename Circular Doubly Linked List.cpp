/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-19-2020
*/

#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    string name;
    node *prev;
    node *next;
};

void Insert(string item, struct node *&head)
{
    node *nn = new node;
    nn->name = item;

    if(!head)
    {
        nn->prev = nn;
        nn->next = nn;
        head = nn;
    }
    else
    {
        nn->prev = head->prev;
        nn->next = head;
        head->prev = nn;
        nn->prev->next = nn;
        head = nn;
    }
}

void Del(int num, struct node *&head)
{
    for(int i = 0; i < num; i++)
    {
        head++;
    }
}

int main()
{
    struct node *head = NULL;

    string in;
    ifstream inF;

    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> in;
        Insert(in ,head);
    }
    inF.close();

    int d = 0;
    cout << "How many nodes would you like to delete?: ";
    cin >> d;
    cout << endl;

    Del(d, head);

    return 0;
}
