/*
Alexander Alestra
Prof. Sabzevary
CISP 430
04-05-2020
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

struct tree
{
    char item;
    tree* left;
    tree* right;
};

tree* AddT(tree *&leaf, char item)
{
    leaf = new tree;
    leaf->item = item;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

struct stackT
{
    tree* item;
    stackT* prev;
};

void pop(stackT *&top)
{
    stackT* temp;
    if(top)
    {
        temp = top;
        top = top->prev;
        delete temp;
    }
}

void push(tree* item, stackT *&top)
{
    stackT* nn = new stackT;

    nn->item = item;
    nn->prev = top;
    top = nn;
}

void infix(tree* root)
{
    if(root != NULL)
    {
        if(root->left && root->right)
        {
            cout << "(";
        }
        infix(root->left);
        cout << root->item;
        infix(root->right);
        if(root->left && root->right)
        {
            cout << ")";
        }
    }
}

bool isOperator(char op)
{
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int evaluate(int left, int right, char op)
{
    int result;

    switch (op) {
      case '+':
         result = left + right;
         break;

      case '-':
         result = left - right;
         break;

      case '*':
         result = left * right;
         break;

      case '/':
         result = left * right;
         break;

      case '^':
         result = pow(left, right);
         break;
    }

    return result;
}

int postOrder(tree* leaf)
{
    int result;

    if(leaf == NULL)
    {
        return 0;
    }
    int left = postOrder(leaf->left);
    int right = postOrder(leaf->right);
    if(isOperator(leaf->item))
    {
        return result = evaluate(left, right, leaf->item);
    }
    else
    {
        int num = (leaf->item - 48);
        return num;
    }
}

void pushnlock(tree *&leaf, stackT *&top, char item)
{
    push(AddT(leaf, item), top);
}

void popnlock(tree *&leaf, stackT *&top, char item)
{
    leaf  = new tree;
    leaf->item = item;
    leaf->right = top->item;
    pop(top);
    leaf->left = top->item;
    pop(top);
    push(leaf, top);
}

int main()
{
    string post;
    cout << "Enter in your postfix notation: ";
    cin >> post;

    stackT* top = NULL;
    tree* root = NULL;

    for(int i = 0; i < post.length(); i++)
    {
        if(isdigit(post[i]))
        {
            pushnlock(root, top, post[i]);
        }
        else
        {
            popnlock(root, top, post[i]);
        }
    }

    cout << endl << "Post Order Evaluation: ";
    cout << postOrder(root);
    cout << endl;

    cout << endl << "Infix Notation: ";
    infix(root);
    cout << endl;

    return 0;
}
