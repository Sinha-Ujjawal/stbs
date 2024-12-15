#include <stdio.h>

#define ARENA_IMPLEMENTATION
#include "arena/arena.h"

void *context_arena_realloc(void *old_ptr, size_t old_bytes, size_t new_bytes);

#define BITARRAY_IMPLEMENTATION
#define BITARRAY_REALLOC(old_ptr, old_bytes, new_bytes) context_arena_realloc((old_ptr), (old_bytes), (new_bytes))
#include "bitarray/bitarray.h"

arena context_arena = {0};
void *context_arena_realloc(void *old_ptr, size_t old_bytes, size_t new_bytes) {
    printf("Allocating %zu byte(s) of memory from context_arena_realloc\n", new_bytes);
    printf("Previously the size of old_ptr was: %zu byte(s)\n", old_bytes);
    return arena_realloc(&context_arena, old_ptr, old_bytes, new_bytes);
}

int main(void) {
    bitarray bits = {0}; bitarray_reset(&bits, 1000000);
    for (size_t i = 0; i < 1000000; i += 2) {
        bitarray_set(&bits, i);
    }
    arena_free(&context_arena);
    return 0;
}
