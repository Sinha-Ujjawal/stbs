# Hash Tables using Open Addressing in C
This is a [stb](https://github.com/nothings/stb) style library implementing [Hash tables using Open Addressing](https://en.wikipedia.org/wiki/Open_addressing) in C.

# Usage:
User is supposed to call a single macro `ht_type` with below arguments
    1. NAME:         name of the hash table type
    2. KEY:          type of the key in the hash table
    3. VALUE:        type of the value in the hash table
    4. HASH\_FN:     hash function/macro to be used for KEY
    5. IS\_KEY\_EQL: function/macro to check if two keys are equal

Example:
1. Hash table for key as integer, and value as boolean. There is already a hash function implementation for integera in the library. See `hash_int`.

```c
#include <stdbool.h> // for bool type
#include "ht.h"

// hash_int and is_eql is already defined in ht.h
ht_type(int_set, int, bool, hash_int, is_eql);
```
As soon as you do this, this macro will generate below types and functions:
```c
typedef struct {
    int key;
    bool value;
    bool is_occupied;
} ht_slot_int_set;

typedef struct {
    ht_slot_int_set *data;
    size_t count;
    size_t capacity;
} int_set;

// function for initializing a hash table
void ht_init_int_set(int_set *ht);

// function to resetting an hash table to empty state
void ht_reset_int_set(int_set *ht);

// function to fin the slot index in the hash table, given the key
size_t ht_find_slot_int_set(int_set ht, int key);

// function to get the corresponding value stored in the hash table for the given key
bool ht_get_int_set(int_set ht, int key, bool *result);

// function to insert only key into the hash table and get access to the slot pointer which the user can use as they want. Also, this function accepts an option `is_new` pointer which will be set to true if the key is newly added to the table
ht_slot_int_set *ht_insert_key_int_set(int_set *ht, int key, bool *is_new);

// function to insert key and value both in the hash table. It also accepts an optional parameter old_value pointer which will be set to the old value stored at that key position (if exists)
bool ht_insert_int_set(int_set *ht, int key, bool value, bool *old_value);

// function to delete the given key from the hash table.
void ht_delete_int_set(int_set *ht, int key, bool *result);
```
