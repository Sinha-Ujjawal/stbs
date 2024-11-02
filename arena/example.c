#include <stdio.h>
#include <assert.h>
#include <string.h>

#define ARENA_DEFAULT_REGION_CAPACITY 512
#define ARENA_TYPE ARENA_TYPE_SCAN_HEAP
#define ARENA_IMPLEMENTATION
#include "arena.h"

arena default_arena = {0};
arena* context_arena = &default_arena;

void* context_arena_alloc(size_t bytes) {
  assert(context_arena != NULL);
  return arena_alloc(context_arena, bytes);
}

typedef struct Person Person;
struct Person {
  char name[255];
};

void dummy_allocate(size_t bytes) {
  char *text = context_arena_alloc(bytes);
  for (size_t i = 0; i < bytes; i++) {
    text[i] = 'a';
  }
}

int main() {
  printf("Intially\n");
  arena_debug(context_arena); printf("\n");

  size_t count = 70;
  int* arr = context_arena_alloc(sizeof(int) * count);
  for (size_t i = 0; i < count; i++) {
    arr[i] = i + 256;
  }
  printf("After allocating integer array\n");
  arena_debug(context_arena); printf("\n");

  Person* person;
  person = context_arena_alloc(sizeof(Person));
  strcpy(person->name, "Ujjawal Sinha");
  printf("After allocating a Person struct\n");
  arena_debug(context_arena); printf("\n");

  person = context_arena_alloc(sizeof(Person));
  strcpy(person->name, "Saumya Raj");
  printf("After allocating another Person struct\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(10);
  printf("After allocating 10 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(250);
  printf("After allocating 250 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(300);
  printf("After allocating 300 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(300);
  printf("After allocating 300 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(300);
  printf("After allocating 300 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(300);
  printf("After allocating 300 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(300);
  printf("After allocating 300 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(200);
  printf("After allocating 200 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  dummy_allocate(200);
  printf("After allocating 200 additional bytes\n");
  arena_debug(context_arena); printf("\n");

  arena_free(context_arena);
  return 0;
}
