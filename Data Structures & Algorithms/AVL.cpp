/*
Alexander Alestra
Prof. Sabzevary
CISP 430
04-26-2020
*/

#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    int num;
    int height;
    node* left;
    node* right;
};

int height(node* h)
{
    if(h == NULL)
    {
        return -1;
    }
    else
    {
        return h->height;
    }
}

node *leftRotate(node *x)
{
   node *y = x->right;
   node *z = y->left;
   x->right = z;
   y->left = x;
   x->height = max(height(x->left), height(x->right)) + 1;
   y->height = max(height(y->left), height(y->right)) + 1;
   return y;
}

node *rightRotate(node *x)
{
   node *y = x->left;
   node *z = y->right;
   x->left = z;
   y->right = x;
   x->height = max(height(x->left), height(x->right)) + 1;
   y->height = max(height(y->left), height(y->right)) + 1;
   return y;
}

int getBalance(node* node)
{
    int bal = 0;
    bal = height(node->left) - height(node->right);
    return bal;
}

node *rebalance(node *leaf)
{
    leaf->height = max(height(leaf->left), height(leaf->right)) + 1;
    int balance = getBalance(leaf);
    int Lbal = getBalance(leaf->left);
    int Rbal = getBalance(leaf->right);

    if(balance == 2 && Lbal > 0)
    {
        return rightRotate(leaf);
    }
    else if(balance == -2 && Rbal < 0)
    {
        return leftRotate(leaf);
    }
    else if(Lbal < 0 && balance == 2)
    {
        leaf->left = leftRotate(leaf->left);
        return rightRotate(leaf);
    }
    else if(Rbal > 0 && balance == -2)
    {
        leaf->right = leftRotate(leaf->right);
        return leftRotate(leaf);
    }
    else
    {
        return leaf;
    }
}

node *insert(node* leaf, int num)
{
    if (!leaf)
    {
        leaf = new node;
        leaf->num = num;
        leaf->height = 0;
        leaf->left = NULL;
        leaf->right = NULL;
        return leaf;
    }

    else if(num < leaf->num)
    {
        leaf->left  = insert(leaf->left, num);
    }
    else if(num > leaf->num)
    {
        leaf->right = insert(leaf->right, num);
    }

    leaf = rebalance(leaf);
    return leaf;
}

void inOrder(node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->num << " ";
        inOrder(root->right);
    }
}

struct que
{
    node* item;
    que* next;
};

void enqueue(node* leaf, que *&front, que *&rear)
{
    que* newNode = new que;
    newNode->item = leaf;
    newNode->next = NULL;
    if(rear)
    {
        rear->next = newNode;
        rear = newNode;
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

int main()
{
    node* root = NULL;
    int num;
    ifstream inF;
    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> num;
        cout << "Inserting number: " << num << endl;
        root = insert(root, num);
    }
    inF.close();

    ofstream outF;
    que *currentLevel, *nextLevel, *crear, *nrear;
    currentLevel = nextLevel = crear = nrear = NULL;

    outF.open("output.txt");

    enqueue(root, currentLevel, crear);
    outF << "Level " << root->height << ": ";
    while(currentLevel)
    {
        outF << root->num << " ";
        dequeue(currentLevel, crear);
        enqueue(root->left, nextLevel, nrear);
        enqueue(root->right, nextLevel, nrear);

        if(currentLevel == NULL)
        {
            currentLevel = nextLevel;
            nextLevel = NULL;
            outF << endl;
        }
    }
    outF.close();

    return 0;
}
