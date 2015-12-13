static int arr[] = {1,5,4,3,2,6};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

void main()
{
    int i, ilen;
    BSTree root=NULL;


    printf("== add: ");
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }
    
    printf("\n== preorder traversal: ");
    preorder_bstree(root);


    printf("\n== inorder traversal: ");
    inorder_bstree(root);

    printf("\n== postorder traversal: ");
    postorder_bstree(root);
    printf("\n");

    printf("== minimum: %d\n", bstree_minimum(root)->key);
    printf("== maximum: %d\n", bstree_maximum(root)->key);
    printf("== thr tree: \n");
    print_bstree(root, root->key, 0);

    printf("\n== delete root node: %d", arr[3]);
    root = delete_bstree(root, arr[3]);

    printf("\n== inorder traversal: ");
    inorder_bstree(root);
    printf("\n");

    destroy_bstree(root);
}
