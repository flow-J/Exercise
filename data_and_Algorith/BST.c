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


