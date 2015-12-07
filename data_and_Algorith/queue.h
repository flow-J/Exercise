#include <stdlib.h>

#define QUEUE_TYPE int

void create_queue(size_t size);

void destroy_queue(void);

void insert( QUEUE_TYPE value);

void delete(void);

QUEUE_TYPE first(void);

int is_empty(void);

int is_full(void);
