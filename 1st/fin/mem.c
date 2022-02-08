#include <stdlib.h>

void * my_malloc( size_t size, size_t front_size , size_t *available_front_size)
{
    size_t *after = (size_t*)realloc(available_front_size, size+front_size);  
    return after+front_size;
}

void my_push( void **ptr, size_t size, size_t *available_front_size )
{
    *ptr = available_front_size+size;
}

void my_free( void *ptr, size_t available_front_size )
{
    free(ptr+available_front_size);   
}