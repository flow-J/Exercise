#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

typedef int Type;

typedef struct BSTreeNode{
    Type    key;
    struct  BSTreeNode *left;
    struct  BSTreeNode *right;
    struct  BSTreeNode *parent;
}Node, *BSTree;


void preorder_bstree(BSTree tree);


void inorder_bstree(BSTree tree);

void postorder_bstree(BSTree tree);


Node* bstree_search(BSTree x, Type key);

Node* iterative_bstree_search(BSTree x, Type key);

Node* bstree_minimum(BSTree tree);



Node* bstree_minimum(BSTree tree);

Node* bstree_maximum(BSTree tree);


Node* bstree_succrssor(Node *x);

Node* bstree_predcessor(Node *x);

Node* insert_bstree(BSTree tree, Type key);

Node* delete_bstree(BSTree tree, Type key);



void destroy_bstree(BSTree tree);

void print_bstree(BSTree tree, Type key, int direction);

#endif
