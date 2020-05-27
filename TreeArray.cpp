/*
Alexander Alestra
Prof. Sabzevary
CISP 430
05-03-2020
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

Node* SAtoBST(int arr[], int st, int en)
{
    if(st > en || arr[st] == 0)
    {
        return NULL;
    }
    int mid = (st + en) / 2;
    Node* root = newNode(arr[mid]);
    root->left = SAtoBST(arr, st, mid - 1);
    root->right = SAtoBST(arr, mid + 1, en);

    return root;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int maxDepth(Node* root)
{
    if(!root)
    {
        return -1;
    }
    else
    {
        int LDepth = maxDepth(root->left);
        int RDepth = maxDepth(root->right);
        if(LDepth > RDepth)
        {
            return (LDepth + 1);
        }
        else
        {
            return (RDepth + 1);
        }
    }
}

void BSTtoUA(Node* n, int a[], int i)
{
    if(n)
    {
        a[i] = n->key;
        BSTtoUA(n->left, a, (2 * i) + 1);
        BSTtoUA(n->right, a, (2 * i) + 2);
    }
}
Node* UAtoBST(int a[], int i, int len)
{
    Node* nn = NULL;
    if(a[i] != 0)
    {
        nn = newNode(a[i]);
        if(((i * 2) + 2) <= len)
        {
            nn->left = UAtoBST(a, (i * 2) + 1, len);
            nn->right = UAtoBST(a, (i * 2) + 2, len);
        }
    }
    return nn;
}

int main()
{
    Node* root = NULL;
    int num, count = 0;
    int SA[10] = {0};
    ifstream inF;
    inF.open("input.txt");
    cout << "File Number: ";
    while(!inF.eof())
    {
        inF >> num;
        cout << num << " ";
        SA[count] = num;
        count++;
    }
    inF.close();
    cout << endl;

    if(count > 10)
    {
        cout << endl << "Too many numbers in the file! Only can have 10 digits in the file!" << endl;
        return 0;
    }

    root = SAtoBST(SA, 0, count);

    int depth = maxDepth(root);
    int len = (pow(2, (depth + 1)) - 1);
    int a[len] = {0};

    BSTtoUA(root, a, 0);

    cout << endl << "PreOrder 1st BST: ";
    preOrder(root);
    cout << endl;

    cout << endl << "Unsorted Array: ";
    for(int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    Node* rooot = NULL;
    rooot = UAtoBST(a, 0, len);

    cout << endl << "PreOrder 2nd BST: ";
    preOrder(rooot);
    cout << endl;

    cout << endl << "InOrder: ";
    inOrder(root);
    cout << endl;

    return 0;
}
