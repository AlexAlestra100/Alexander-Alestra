/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-29-2020
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string names[10];

struct node
{
    string name;
    node* next;
};

void AddN(node* head, string val)
{
    node* nn = new node;
    nn->name = val;
    nn->next = head;
    head = nn;
}

void ReadFile()
{
    int i = 0;
    string in;
    ifstream inF;
    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> in;
        names[i] = in;
        i++;
    }
    inF.close();
}

struct TreeNode
{
    string name;
    node* head;
    TreeNode* left;
    TreeNode* right;
};

void AddT(TreeNode *&leaf, string name)
{
    leaf  = new TreeNode;
    leaf->name = name;
    leaf->left = NULL;
    leaf->right = NULL;
}

void Insert(TreeNode *&root, string name)
{
    bool done = false;
    TreeNode *leaf = root;

    if(!root)
    {
        AddT(root, name);
    }
    else
    {
        while(!done)
        {
            if(name == leaf->name)
            {
                AddN(leaf->head, name);
                done = true;
            }
            else if(name > leaf->name)
            {
                if(leaf->left != NULL)
                {
                    leaf = leaf->left;
                }
                else
                {
                    AddT(leaf->left, name);
                    done = true;
                }
            }
            else
            {
                if(leaf->right != NULL)
                {
                    leaf = leaf->right;
                }
                else
                {
                    AddT(leaf->right, name);
                    done = true;
                }
            }
        }
    }
}

bool searchR(TreeNode* leaf, string name)
{
    bool found = false;
    if(leaf)
    {
        if(name == leaf->name)
        {
            int c = 0;
            found = true;
            cout << "Found: " << name << " ";
            if(leaf->head)
            {
                c++;
            }
            cout << "Count: " << c << endl;
        }
        else if(name > leaf->name)
        {
            found = searchR(leaf->left, name);
            cout << "Left side: " << name << endl;
        }
        else
        {
            found = searchR(leaf->right, name);
            cout << "Right side: " << name << endl;
        }
    }
}

int main()
{
    ReadFile();
    TreeNode* root = NULL;
    string name;

    for(int i = 0; i < 10; i++)
    {
        Insert(root, names[i]);
    }

    cout << "Insert a string name to search: ";
    cin >> name;
    cout << endl;

    searchR(root, name);

    return 0;
}
