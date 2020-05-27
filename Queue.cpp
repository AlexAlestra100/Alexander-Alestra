/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-09-2020
*/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

/*&struct Node
{
    int value;
    Node* next;
};*/
void traverse(queue <int> tq);
void enqueue(queue <int> eq);
int dequeue(queue <int> dq);

int main()
{
    int fnum = 0;
    queue <int> q;
    ifstream inF;
    cout << "Opening file input.txt." << endl;
    inF.open("input.txt");
    if(!inF.is_open())
    {
        cout << "Could not open file input.txt." << endl;
        return 1;
    }
    while(!inF.eof())
    {
        inF >> fnum;
        q.push(fnum);
    }
    cout << "Unmodified queue:" << endl;
    traverse(q);
    //enqueue(q);
    cout << "Modified queue:" << endl;
    dequeue(q);
    inF.close();
    return 0;
}

void traverse(queue <int> tq)
{
    for(; tq.front(); tq.pop())
    {
        cout << tq.front() << endl;
    }
}

void enqueue(queue <int> eq)
{
    for(int i = 0; i < eq.size(); i++)
    {
        eq.push(eq.front());
        eq.pop();
    }
    traverse(eq);
}

int dequeue(queue <int> dq)
{
    for(int i = 0; i < dq.size(); i++)
    {
        if(dq.front() > 0)
        {
            dq.push(dq.front());
            dq.pop();
        }
        if(dq.front() < 0)
        {
            dq.pop();
        }
    }
    traverse(dq);
}

/*void traverse(Node *curr)
{
    while(curr)
    {
        cout << curr->value;
        curr = curr->next;
    }
}
void enqueue(Node *&front, Node *rear, int value)
{
    Node *nn = new node;
    nn->value = value;
    nn->next = null;
    if(!front)
    {
        rear = front = nn;
    }
    else
    {
        rear->next = nn;
        rear = nn;
    }
}

int dequeue(Node *&front, Node *&rear)
{
    if(front)
    {
        temp = front;
        front = front->next;
        temp2 = temp->value;
        delete temp;
        if(!front)
        {
            rear = front;
        }
    }
}*/
