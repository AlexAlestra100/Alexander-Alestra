/*
Alexander Alestra
Prof. Sabzevary
CISP 430
02-16-2020
*/

#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    char item;
    node* next;

};

void Push(char item, struct node *&front, struct node *&rear)
{
    struct node *nn = new node;

    nn->item = item;
    nn->next = NULL;

    if(rear)
    {
        rear->next = nn;
        rear = nn;
    }
    else
    {
        front = rear = nn;
    }
}

void Pop(struct node *&front, struct node *&rear)
{
    cout << rear->item;

    struct node *temp;

    if(front)
    {
        temp = front;
        front = front->next;
        delete temp;
        /*if(!front)
        {
            rear = NULL;
        }*/
    }
}

/*void enqueue(char item, struct node *&front, struct node *&rear)
{
    struct node *nn = new node;

    nn->item = item;
    nn->next = NULL;
    if(rear)
    {
        rear->next = nn;
        rear = nn;
    }
    else
    {
        front = rear = nn;
    }
}*/

/*void dequeue(struct node *&front, struct node *&rear)
{
    struct node *temp;

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
}*/

void Traverse(node* front, node* rear)
{
    while(front)
    {
        cout << front->item;
        front = front->next;
    }
    cout << endl;
}

int main()
{
    char in;

    ifstream inF;
    inF.open("input.txt");

    struct node *front, *rear;
    front = rear = NULL;

    int size = 0;
    while(inF >> in)
    {
        ++size;
    }
    inF.close();
    inF.open("input.txt");

    int i = 0;
    int now = 6;
    int then = 0;
    while(i < size)
    {
        i++;
        inF >> in;
        if(isdigit(in))
           {
                cout << in;
           }
        else if(in == '^')
        {
            now = 5;
            if(now <= then)
            {
                Pop(front, rear);
                Push(in, front, rear);
            }
            else
            {
                Push(in, front, rear);
            }
            then = 5;
        }
        else if(in == '*' || in == '/')
        {
            now = 4;
            if(now <= then)
            {
                Pop(front, rear);
                Push(in, front, rear);
            }
            else
            {
                Push(in, front, rear);
            }
            then = 4;
        }
        else if(in == '+' || in == '-')
        {
            now = 3;
            if(now <= then)
            {
                Pop(front, rear);
                Push(in, front, rear);
            }
            else
            {
                Push(in, front, rear);
            }
            then = 3;
        }
        else if(in == '(' || in == ')')
        {
            now = 2;
            Pop(front, rear);
            then = 2;
        }
        else if(in == '=')
        {
            now = 1;
            if(now <= then)
            {
                Pop(front, rear);
                Push(in, front, rear);
            }
            else
            {
                Push(in, front, rear);
            }
            then = 1;
        }
        /*switch(in)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':

                break;
            case '^':

                break;
            case '*':
            case '/':

                break;
            case '+':
            case '-':

                break;
            case '(':

                break;
            case '=':

                break;
        }*/
    }
    inF.close();
    Traverse(front, rear);
    return 0;
}
