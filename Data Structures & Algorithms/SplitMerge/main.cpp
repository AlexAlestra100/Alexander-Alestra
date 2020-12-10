/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-09-2020
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    string val;
    Node* next;
};

Node* ReadFile(Node* r);
void SplitAndMerge(Node* s);
void Traverse(Node* current);
Node* Merge(Node* list1, Node* list2);
void Add(Node*& head_a, string val);
int Counter(Node* c);

int main()
{
    Node* n1 = new Node;
    n1 = nullptr;
    n1 = ReadFile(n1);
    cout << "Read file into node one." << endl << endl;
    cout << "Traversing..." << endl;
    Traverse(n1);
    cout << endl;
    if(!(Counter(n1) % 2 == 0))
    {
        cout << "Must have an even number of names!" << endl;
        return 1;
    }
    cout << "Quantity of elements: " << Counter(n1) << endl << endl;
    cout << "Split and Merge:" << endl << endl;
    SplitAndMerge(n1);

    return 0;
}

Node* ReadFile(Node* r)
{
    string in;
    cout << "Reading...   ";
    ifstream inF;
    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> in;
        Add(r, in);
    }
    inF.close();
    cout << "Done!" << endl;
    return r;
}

void SplitAndMerge(Node* s)
{
    Node* mL1 = new Node;
    Node* mL2 = new Node;
    mL1 = nullptr;
    mL2 = nullptr;
    /*int c = 0;
    while(s)
    {
        ++c;
        s = s->next;
    }*/
    int split = Counter(s)/2;
    int c = Counter(s);

    for(int i = 0; i < split; i++)
    {
        Add(mL1, s->val);
        s = s->next;
    }
    for(int i = split; i < c; i++)
    {
        Add(mL2, s->val);
        s = s->next;
    }

    cout << "List 1: "<< endl;
    Traverse(mL1);
    cout << endl;
    cout << "List 2: "<< endl;
    Traverse(mL2);
    cout << endl;

    cout << "Merging: " << endl;
    Node* remerge = new Node;
    remerge = Merge(mL1, mL2);
    Traverse(remerge);
}

void Traverse(Node* current)
{
    while(current)
    {
        cout << current->val << endl;
        current = current->next;
    }
}

Node* Merge(Node* list1, Node* list2)
{
    Node* merg = new Node;
    merg = list1;

    for(; list2; list2 = list2->next)
    {
        Add(merg, list2->val);
    }
    return merg;
}

void Add(Node*& head_a, string val)
{
    Node* nn = new Node;
    nn->val = val;
    nn->next = head_a;
    head_a = nn;
}

int Counter(Node* c)
{
    int cot = 0;
    while(c)
    {
        ++cot;
        c = c->next;
    }
    return cot;
}
