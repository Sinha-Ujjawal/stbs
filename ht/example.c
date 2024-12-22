#include <stdio.h>
#include <assert.h>

#define HT_IMPLEMENTATION
#include "ht.h"

ht_type(int_tbl, int, int, hash_int, is_eql);

void test_init() {
    printf("Test 1 (Initialization) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    assert(ht.count == 0);
    assert(ht.capacity == HT_INITIAL_CAP);
    free(ht.data);
    printf("Test 1 (Initialization) passed.\n");
}

void test_insert_and_get() {
    printf("Test 2 (Single Insertion and Retrieval) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    int key = 5, value = 10;
    ht_insert_int_tbl(&ht, key, value, NULL);
    int retrieved_value;
    bool found = ht_get_int_tbl(ht, key, &retrieved_value);
    assert(found);
    assert(retrieved_value == value);
    printf("Test 2 (Single Insertion and Retrieval) passed.\n");
}

void test_collision_handling() {
    printf("Test 3 (Collision Handling) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    int key1 = 5, value1 = 10;
    int key2 = 5 + ht.capacity, value2 = 20; // Force a collision using modulo
    ht_insert_int_tbl(&ht, key1, value1, NULL);
    ht_insert_int_tbl(&ht, key2, value2, NULL);
    int retrieved_value1, retrieved_value2;
    bool found1 = ht_get_int_tbl(ht, key1, &retrieved_value1);
    bool found2 = ht_get_int_tbl(ht, key2, &retrieved_value2);
    assert(found1 && retrieved_value1 == value1);
    assert(found2 && retrieved_value2 == value2);
    printf("Test 3 (Collision Handling) passed.\n");
}

void test_deletion() {
    printf("Test 4 (Deletion) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    int key = 5, value = 10;
    ht_insert_int_tbl(&ht, key, value, NULL);
    int retrieved_value;
    ht_delete_int_tbl(&ht, key, &retrieved_value);
    bool found = ht_get_int_tbl(ht, key, &retrieved_value);
    assert(!found); // Key should no longer exist
    printf("Test 4 (Deletion) passed.\n");
}

void test_resizing_on_insert() {
    printf("Test 5 (Resizing on Insert) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    // Insert enough elements to trigger resize
    size_t initial_capacity = ht.capacity;
    for (int i = 0; i < initial_capacity; i++) {
        ht_insert_int_tbl(&ht, i, i * 10, NULL);
    }
    assert(ht.capacity > initial_capacity); // Verify resizing happened
    // Verify all elements are still accessible
    for (int i = 0; i < initial_capacity; i++) {
        int retrieved_value;
        bool found = ht_get_int_tbl(ht, i, &retrieved_value);
        assert(found && retrieved_value == i * 10);
    }
    printf("Test 5 (Resizing on Insert) passed.\n");
}

void test_lazy_deletion() {
    printf("Test 6 (Lazy Deletion with Probing) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    int keys[] = {5, 10, 15};
    int values[] = {50, 100, 150};
    for (int i = 0; i < 3; i++) {
        ht_insert_int_tbl(&ht, keys[i], values[i], NULL);
    }
    // Delete middle key
    ht_delete_int_tbl(&ht, keys[1], NULL);
    // Ensure other keys are still accessible
    int retrieved_value;
    bool found = ht_get_int_tbl(ht, keys[0], &retrieved_value);
    assert(found && retrieved_value == values[0]);
    found = ht_get_int_tbl(ht, keys[2], &retrieved_value);
    assert(found && retrieved_value == values[2]);
    printf("Test 6 (Lazy Deletion with Probing) passed.\n");
}

void test_shrinking() {
    printf("Test 7 (Shrinking) started.\n");
    int_tbl ht;
    ht_init_int_tbl(&ht);
    // Fill the table and then remove enough elements to trigger shrinking
    for (int i = 0; i < HT_INITIAL_CAP * 2; i++) {
        ht_insert_int_tbl(&ht, i, i * 10, NULL);
    }
    size_t initial_capacity = ht.capacity;
    for (int i = 0; i < initial_capacity * 0.7; i++) {
        ht_delete_int_tbl(&ht, i, NULL);
    }
    assert(ht.capacity < initial_capacity); // Verify shrinking happened
    printf("Test 7 (Shrinking) passed.\n");
}

int main(void) {
    test_init();
    test_insert_and_get();
    test_collision_handling();
    test_deletion();
    test_resizing_on_insert();
    test_lazy_deletion();
    test_shrinking();
    return 0;
}
