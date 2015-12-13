#define TREE_TYPE int


/*insert*/
void insert( TREE_TYPE value );


TREE_TYPE *find( TREE_TYPE value );

void pre_order_traverse(void (*callback)( TREE_TYPE value ));

