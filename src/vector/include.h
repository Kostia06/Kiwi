#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    size_t  allocated;
    size_t  length;
    size_t  element_size;
    char    data[];
} Vector;

#define vec_get_data(vec_ptr) &((Vector*)vec_ptr)[-1]
#define vec_free(vec_ptr) free(vec_get_data(vec_ptr))
#define vec_size(vec_ptr) ((Vector*)vec_get_data(vec_ptr))->length
#define vec_allocated(vec_ptr) ((Vector*)vec_get_data(vec_ptr))->allocated
#define vec_has_space(vec_ptr) (vec_size(vec_ptr) < vec_allocated(vec_ptr))
void* vec_init(size_t element_size);
Vector* vec_realloc(Vector* vec);
Vector* vec_alloc(size_t allocated);
#define vec_insert_asg(vec_ptr, pos) ( (typeof(*vec_ptr))( _vec_insert((void**)vec_ptr, pos) ) )
#define vec_insert(vec_ptr, pos, value) (*vec_insert_asg(vec_ptr, pos) = value)
#define vec_push(vec_ptr, value) vec_insert(vec_ptr, vec_size(*vec_ptr), value)
void* _vec_insert(void** vec_ptr, size_t pos);
#define vec_erase(vec_ptr, pos, count) _vec_erase((void**)vec_ptr, pos, count)
void _vec_erase(void** vec_ptr, size_t pos, size_t count);
#define vec_remove(vec_ptr, pos) vec_erase(vec_ptr, pos, 1)
#define vec_pop(vec_ptr) vec_remove(vec_ptr, vec_size(*vec_ptr) - 1)
