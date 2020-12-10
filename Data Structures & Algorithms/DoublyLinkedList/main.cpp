/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-19-2020
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct node
{
    string name;
    node *prev;
    node *next;
};

void Insert(string item, struct node *&head, struct node *&tail, struct node *&curr)
{
    struct node *nn = new node;

    nn->name = item;
    nn->prev = NULL;
    nn->next = NULL;

    if(!head)
    {
        nn->next = NULL;
        tail = nn;
        head = nn;
    }
    else if(nn->name < head->name)
    {
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    else if(nn->name > tail->name)
    {
        nn->prev = tail;
        tail->prev = nn;
        tail= nn;
    }
    else
    {
        while(nn->name > curr->name)
        {
            curr = curr->next;
        }
        nn->next = curr;
        nn->prev = curr->prev;
        curr->prev = nn;
    }
}

/*void Remove(struct node *&head, struct node *&tail, struct node *&curr)
{
    if(curr->prev)
    {
        curr->prev->next = curr->next;
    }
    else
    {
        head = curr->next;
        head->prev = NULL;
    }
}*/

void Traverse(node* head, node* tail)
{
    ofstream outF;
    outF.open("output.txt");

    while(head)
    {
        cout << head->name << endl;
        outF << head->name << endl;
        head = head->next;
    }
    cout << "===============" << endl;
    outF << "===============" << endl;
    while(tail)
    {
        cout << tail->name << endl;
        outF << tail->name << endl;
        tail = tail->prev;
    }
    outF.close();
}

int main()
{
    struct node *head = NULL, *tail = NULL, *curr = NULL;

    string in;
    ifstream inF;

    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> in;
        Insert(in ,head, tail, curr);
    }
    inF.close();

    Traverse(head, tail);
    return 0;
}
