#include "include.h"


// create a new vector
void* vec_init(size_t element_size){
    Vector* vec = malloc(sizeof(Vector));
    vec->allocated = 0;
    vec->length = 0;
    vec->element_size = element_size;
    return &vec->data;
}

// realloc the vector
Vector* vec_realloc(Vector* vec){
    size_t new_allocated = vec->allocated == 0 ? 1 : vec->allocated * 2;
    Vector* new_vec = realloc(vec, sizeof(Vector) + new_allocated * vec->element_size);
    new_vec->allocated = new_allocated;
    return new_vec;
}
// allocate the vector
Vector* vec_alloc(size_t allocated){
    Vector* vec = malloc(sizeof(Vector) + allocated * vec->element_size);
    vec->allocated = allocated;
    return vec;
}
// get a space for an element
void* _vec_insert(void** vec_ptr, size_t pos){
    Vector* vec = vec_get_data(*vec_ptr);
    size_t new_length = vec->length + 1;
    if(!vec_has_space(vec)){
        vec = vec_realloc(vec);
        *vec_ptr = &vec->data;
    }
    // move the elements after the insertion point
    memmove(&vec->data[(pos+1) * vec->element_size], &vec->data[pos * vec->element_size], (vec->length - pos) * vec->element_size);
    vec->length = new_length;
    return &vec->data[pos * vec->element_size];
}
// erase an element(s) from the vector
void _vec_erase(void** vec_ptr, size_t pos, size_t count){
    Vector* vec = vec_get_data(*vec_ptr);
    // move the elements after the erased elements  
    memmove(&vec->data[pos * vec->element_size], &vec->data[(pos + count) * vec->element_size], (vec->length - pos - count) * vec->element_size);
    vec->length -= count; 
}
// get space to push item at the back of the vector 
void* _vec_push(void** vec_ptr){
    Vector* vec = vec_get_data(*vec_ptr);
    if(!vec_has_space(vec)){
        vec = vec_realloc(vec);
        *vec_ptr = &vec->data;
    }
    return (void*)&vec->data[vec->length++ * vec->element_size];
}
