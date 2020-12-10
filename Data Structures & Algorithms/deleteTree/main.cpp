/*
Alexander Alestra
Prof. Sabzevary
CISP 430
03-29-2020
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct TreeNode
{
    int num;
    TreeNode* left;
    TreeNode* right;
};

void AddT(TreeNode *&leaf, int num)
{
    leaf  = new TreeNode;
    leaf->num = num;
    leaf->left = NULL;
    leaf->right = NULL;
}

void Insert(TreeNode *&root, int num)
{
    bool done = false;
    TreeNode *leaf = root;

    if(!root)
    {
        AddT(root, num);
    }
    else
    {
        while(!done)
        {
            if(num == leaf->num)
            {
                done = true;
            }
            else if(num < leaf->num)
            {
                if(leaf->left != NULL)
                {
                    leaf = leaf->left;
                }
                else
                {
                    AddT(leaf->left, num);
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
                    AddT(leaf->right, num);
                    done = true;
                }
            }
        }
    }
}

void preOrder(TreeNode* root)
{
    if(root != NULL)
    {
        cout << root->num << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->num << " ";
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->num << " ";
    }
}

bool searchT(TreeNode* leaf, int num)
{
	bool found = false;

	while(leaf && !found)
	{
		if(num == leaf->num)
		{
		    found = true;
		}
		else if(num < leaf->num)
        {
            leaf = leaf->left;
        }
        else
        {
            leaf = leaf->right;
        }
    }
    return found;
}

TreeNode* minV(TreeNode* leaf)
{
    TreeNode* curr = leaf;
    while(curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

TreeNode* delN(TreeNode* leaf, int num)
{
    if(leaf == NULL)
    {
        return leaf;
    }
    if(num < leaf->num)
    {
        leaf->left = delN(leaf->left, num);
    }
    else if(num > leaf->num)
    {
        leaf->right = delN(leaf->right, num);
    }
    else
    {
        if(leaf->left == NULL && leaf->right == NULL)
        {
            return leaf = NULL;
        }
        else if(leaf->left == NULL)
        {
            TreeNode* temp = leaf->right;
            delete(leaf);
            return temp;
        }
        else if(leaf->right == NULL)
        {
            TreeNode* temp = leaf->left;
            delete(leaf);
            return temp;
        }

        TreeNode* temp = minV(leaf->right);
        leaf->num = temp->num;
        leaf = delN(leaf->right, temp->num);

    }
    return leaf;
}

int main()
{
    TreeNode* root = NULL;
    string del;
    int num;
    ifstream inF;
    inF.open("input.txt");
    while(!inF.eof())
    {
        inF >> del;
        if(del == "delete")
        {
            inF >> del;
            num = atoi(del.c_str());
            //searchT(root, num);
            if(searchT(root, num) == false)
            {
                Insert(root, num);
                cout << "Inserting number: " << num << endl;
            }
            else
            {
                root = delN(root, num);
                cout << "Deleting number: " << num << endl;
            }
        }
        else
        {
            num = atoi(del.c_str());
            Insert(root, num);
            cout << "Inserting number: " << num << endl;
        }
    }
    inF.close();

    cout << endl << "PreOrder:" << endl;
    preOrder(root);

    cout << endl << "InOrder:" << endl;
    inOrder(root);

    cout << endl << "PostOrder:" << endl;
    postOrder(root);

    cout << endl;

    return 0;
}
