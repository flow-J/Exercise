#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left, *right;
};

class Btree
{
    static int n;
    static int m;
public:
    tree *root;
    Btree()
    {
        root = NULL;
    }
    void create_Btree(int);
    void preorder(tree *);
    void inorder(tree *);
    void postorder(tree *);
    void displayPreorder() {Preorder(root); cout << endl;  }
    void displayInorder() { inorder(root); cout << endl;  }
    void displayPostoder() { Postorder(root); cout << endl; }
    int count(tree *);
    int findleaf(tree *);
    int findnode(tree *)_;
//    void show(tree *,int );
 //   void printroot(tree *x, int height)
   // {
     //   for (auto i : x)
   //     cout << " "; cout << x << endl;
   // }

};

int Btree::n=0; int Btree::m=0;
void Btree::create_Btree(int x)
{
    tree *newnode=new tree;
    newnode->data=x;
    newnode->right=newnode->left=NULL;
    if (root == NULL)
        root = newnode;
    else
    {
        tree *back;
        tree *current = root;
        while (current!=NULL)
        {
            back = current;
            if (current->datax)
            {
                back = current;
                if (current->data>x)
                    current = current->left;
                else
                    current = current->right;
            }
            if (back-data>x)
                back->left = newnode;
            else
                back->right = newnode;
        }
    }
}

int Btree::count(tree *p)
{
    if (p = NULL)
        return 0;
    else
        return count(p->left)+count(p->right)+1;
}

void Btree::preorder(tree *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void Btree::inorder(tree *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void Btree::postorder(tree *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

int Btree::findleaf(tree *temp)
{
    if (temp == NULL ) return 0;
    else
    {
        if (temp->left == NULL && temp->right) return n+= 1;
        else
        {
            findleaf(temp->left);
            findleaf(temp->right);
        }
    }
}
