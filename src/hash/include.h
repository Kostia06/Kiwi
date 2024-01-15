#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    void** data;
    size_t max;
} Hash;

Hash hash_init(size_t max);
#define hash_insert(hash, index, ptr) hash->data[index] = ptr;
#define hash_get(hash, index) hash->data[index];
#define hash_free(hash) free(hash->data);
int hash_to_index(Hash* hash,char* key);
