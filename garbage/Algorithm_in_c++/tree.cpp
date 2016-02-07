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
    void displayPreorder() {preorder(root); cout << endl;  }
    void displayInorder() { inorder(root); cout << endl;  }
    void displayPostoder() { postorder(root); cout << endl; }
    int count(tree *);
    int findleaf(tree *);
    int findnode(tree *);
/*    void show(tree *t,int height)
    {
        if (t == 0) { printroot('*', height); return ;}
        show (t->right, height+1);
        printroot(t->data, hegiht);
        show(t->left, height+1);
    }*/
    void printroot(tree *x, int height)
    {
        for (int i = 0; i < height; i++)
        cout << " "; cout << x << endl;
    }

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
            if (current->data>x)
                current = current->left;
            else
                current = current->right;
        }
        if (back->data>x)
            back->left = newnode;
        else
            back->right = newnode;
    }
}

int Btree::count(tree *p)
{
    if (p == NULL)
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
        return n;
    }
}

int Btree::findnode(tree *temp)
{
    if (temp == NULL) return 0;
    else
    {
        if (temp->left!=NULL && temp->right!=NULL)
        {
            findnode(temp->left);
            findnode(temp->right);
        }
        if (temp->left!=NULL && temp->right==NULL)
        {
            m += 1;
            findnode(temp->left);
        }
        if (temp->left == NULL && temp->right != NULL)
        {
            m += 1;
            findnode(temp->right);
        }
    }
    return m;
}

int main()
{
    Btree fuck;
    int array[] = {100, 4, 2, 3, 44, 55, 78, 95, 45,111};
    int k;
    k = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < k; i++)
    {
        cout << array[i] << " ";
        fuck.create_Btree(array[i]);
    }
    cout << "Tree node "  << fuck.count(fuck.root) << endl;
    cout << "tree leaf" << fuck.findleaf(fuck.root) << endl;
    cout << " node of finded" << fuck.findnode(fuck.root) << endl;
    cout << "preorder" << endl;
    fuck.displayPreorder();
    cout << "Inorder" << endl;
    fuck.displayInorder();
    cout << "postorder" << endl;
    fuck.displayPostoder();
}
