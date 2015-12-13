#define STACK_TYPE int
#include <stddef.h>
/* push */

void push( STACK_TYPE value );

/* pop */
void pop( void );

/* top */
STACK_TYPE top( void );

/* is empty*/
int it_empty( void );

/* is full */

int if_full( void );




/*create stack*/
void create_stack( size_t size );



/* destroy stack*/
void destrop_stack( void );
