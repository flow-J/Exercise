#include "tree.h"
#include <assert.h>
#include <stdio.h>

#define TREE_SIZE 100
#define ARRAY_SIZE  ( TREE_SIZE + 1)

static TREE_TYPE tree[ ARRAY_SIZE ];


/* left child */
static int left_child(int current )
{
    return current * 2;
}


/* right child*/
static int right_child(int current)
{
    return current * 2 + 1;
}


/* insert 
 * */
void insert(TREE_TYPE value)
{
    int current;

    assert( value != 0);
    current = 1;

    while( tree[ current ] != 0 )
    {
        if( value < tree[ current ])
            current = left_child( current );
        else {
            assert( value != tree[ current ]);
            current = right_child( current );
        }
        assert( current < ARRAY_SIZE );
    }
    tree[ current ] = value;
}


/*find
 * */
TREE_TYPE *find(TREE_TYPE value)
{
    int current;

    current = 1;

    while( current < ARRAY_SIZE && tree[ current ] != vaule )
    {
        if(value < tree[ current ] )
            current = left_child( current );
        else
            current = right_child( current );
    }
    if( current < ARRAY_SIZE )
        return tree + current;
    else
        return 0;
}

static void do_pre_order_traverse( int current,
        void (*callback)(TREE_TYPE value) )
{

}
