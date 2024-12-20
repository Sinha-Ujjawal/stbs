#include <stdio.h>

#define ARENA_IMPLEMENTATION
#include "arena/arena.h"

void *context_arena_alloc(size_t bytes);

#define DEDA_IMPLEMENTATION
#define DEDA_MALLOC context_arena_alloc
#define DEDA_FREE
#include "deda/deda.h"

deda_type(int_deque, int);

arena context_arena = {0};
void *context_arena_alloc(size_t bytes) {
    printf("Allocating %zu byte(s) of memory from context_arena_realloc\n", bytes);
    return arena_alloc(&context_arena, bytes);
}
void *context_arena_realloc(void *old_ptr, size_t old_bytes, size_t new_bytes) {
    printf("Allocating %zu byte(s) of memory from context_arena_realloc\n", new_bytes);
    printf("Previously the size of old_ptr was: %zu byte(s)\n", old_bytes);
    return arena_realloc(&context_arena, old_ptr, old_bytes, new_bytes);
}

int main(void) {
    int_deque deq = {0}; deda_init(&deq);
    for (int i = 0; i < 1000000; i++) {
        deda_push(&deq, i);
    }
    arena_free(&context_arena);
    return 0;
}
