#include <stdio.h>

#define ARENA_IMPLEMENTATION
#include "arena/arena.h"

#define DA_IMPLEMENTATION
#define DA_REALLOC(old_ptr, old_bytes, new_bytes) context_arena_realloc((old_ptr), (old_bytes), (new_bytes))
#include "da/da.h"

da_type(int_arr, int);

arena context_arena = {0};
void *context_arena_realloc(void *old_ptr, size_t old_bytes, size_t new_bytes) {
    printf("Allocating %zu byte(s) of memory from context_arena_realloc\n", new_bytes);
    printf("Previously the size of old_ptr was: %zu byte(s)\n", old_bytes);
    return arena_realloc(&context_arena, old_ptr, old_bytes, new_bytes);
}

int main(void) {
    int_arr arr = {0}; da_init(&arr);
    for (int i = 0; i < 1000000; i++) {
        da_push(&arr, i);
    }
    arena_free(&context_arena);
    return 0;
}
