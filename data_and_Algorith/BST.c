typedef int Type;

typedef struct BSTreeNode{
    Type    Key;
    struct  BSTreeNode *left;
    struct  BSTreeNode *right;
    struct  BSTreeNode *parent;
}Node, *BSTree;


static Node* create_bstree_node(Type key, Node *parent, Node *left, Node* right)
{
    Node* p;

    if((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;

    return p;
}

void preorder_bstree(BSTree tree)
{
    if(tree != NULL)
    {
        printf("%d ", tree->key);
        preorder_bstree(tree->left);/*first left ,so this is preorder bstree*/
        preorder_bstree(tree->right);
    }
}

void inorder_bstree(BSTree tree)/*Zhong*/
{
    if(tree != NULL)
    {
        inorder_bstree(tree->left);
        printf("%d ", tree->key);
        inorder_bstree(tree->right);
    }
}


void postorder_bstree(BSTree tree)
{
    if(tree != NULL)
    {
        postorder_bstree(tree->left);
        postorder_bstree(tree->right);
        printf("%d ",tree->key);
    }
}


Node* iterative_bstree_search(BSTree x, Type key)
{
    while((x!=NULL) && (x->key!=key) )
    {
        if(key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}


Node* bstree_maximum(BSTree tree)
{
    if(tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}


Node* bstree_minimum(BSTree tree)
{
    if(tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}


Node* bstree_predecessor(Node *x)
{
    if(x->left != NULL)
        return bstree_maximum(x->left);

    Node* y = x->parent;
    while((y!=NULL) && (x==y->left) )
    {
        x = y;
        y = y->parent;
    }

    return y;
}


Node* bstree_successor(Node *x)
{
    if(x->right != NULL)
        return bstree_minimum(x->right);

    Node* y = x->parent;
    while((y!NULL) && (x==y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}


/*

static Node* bstree_insert(BSTree tree, Node *z)
{
    Node *y = NULL;
    Node *x = tree;

    while(x != NULL)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y==NULL)
        tree = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}

*
*
*
*/



static Node* bstree_insert(BSTree tree, Node *z)
{
    Node *y = NULL;
    Node *x = tree;

    while(x != NULL)
    {
        y = x;
        if(z->key < x->key)
            x = x->left;
        else if(z->key > x-key)
            x = x->right;
        else
        {
            free(z);
            return tree;
        }
    }

    z->parent = y;
    if(y==NULL)
        tree = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}


