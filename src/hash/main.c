#include "include.h"

// create hash table
    Hash hash;
Hash hash_init(size_t max){
    hash.max = max;
    hash.data = malloc(sizeof(void*)*max);
    return hash;
}
// turn a string into a hash index
int hash_to_index(Hash* hash,char* key){
    unsigned long new_key = 5381;
    int c;
    while ((c = *key++)) {
        new_key = ((new_key << 5) + new_key) + c; 
    }
    return new_key % hash->max;
}
