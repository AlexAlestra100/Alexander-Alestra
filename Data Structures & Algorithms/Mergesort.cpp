/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-10-2020
*/

#include <iostream>

using namespace std;

int numbers[7] = {1, 5, 8, 3, 6, 9, 11};
int number = 7;

struct node
{
    int data;
    node* next;
};

void Add(node*& head, int val)
{
    node* nn = new node;
    nn->data = val;
    nn->next = head;
    head = nn;
}

void Fill(node*& head)
{
    for(int i = number - 1; i >= 0; i--)
    {
        Add(head, numbers[i]);
    }
}

void Traverse(node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void split (node* head, node*& a, node*& b)
{
    int j = 0;
    while(head)
    {
        a = a->next;
        j++;
    }
    for(int i = 0; i <= j / 2; i++)
    {
        b = b->next;
    }
}

node* merge(node* a, node* b)
{
    int temp;
    if(a->data > b->data)
    {
        temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
}

node* mergeSort(node* head)
{
    node* a = head;
    node* b = head;
    node* c = nullptr;

    split(head, a, b);

    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return head;
    }

    a = mergeSort(a);
    b = mergeSort(b);
    c = merge(a, b);

   return (c);
}

int main()
{
    node* n1 = new node;
    n1 = NULL;

    Fill(n1);

    Traverse(n1);

    mergeSort(n1);

    Traverse(n1);
    return 0;
}
