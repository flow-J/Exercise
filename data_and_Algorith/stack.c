#include "stack.h"
#include <assert.h>

#define STACK_SIZE  100

static STACK_TYPE   stack[ STACK_SIZE ];
static int          top_element = -1;

/* push */
void push( STACK_TYPE value)
{
    assert( !is_full() );
    top_element += 1;
    stack[ top_element ] = value;
    /*if isno't full the can push data in there*/
}


/* pop */
void pop( void )
{
    assert( !is_empty() );/* if isno't empty then can pop data out there*/
    top_element -= 1;
}

/* top */
STACK_TYPE top( void )
{
    assert(  !is_empty() );
    return stack[ top_element ];
}

/*is_empty*/
int is_empty( void )
{
    return top_element == -1;
}

int is_full( void )
{
    return top_element == STACK_SIZE -1;/*top element = zhan ding yuan su*/
}
