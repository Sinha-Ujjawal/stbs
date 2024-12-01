#include <stdio.h>
#include <assert.h>

#define ALGO_IMPLEMENTATION
#include "algo.h"

size_t bisect_left_int_arr(int target, size_t low, size_t high, int *arr, size_t count) {
#define fn_key(i) arr[i]
    bisect_left(target, &low, &high, fn_key);
    return low;
#undef fn_key
}

size_t bisect_right_int_arr(int target, size_t low, size_t high, int *arr, size_t count) {
#define fn_key(i) arr[i]
    bisect_right(target, &low, &high, fn_key);
    return low;
#undef fn_key
}

void heapify_int_arr(int *arr, size_t count, size_t root) {
#define fn_compare(x, y) x > y
    heapify(arr, count, fn_compare, root);
#undef fn_compare
}

void build_heap_int_arr(int *arr, size_t count) {
#define fn_compare(x, y) x > y
    build_heap(arr, count, fn_compare);
#undef fn_compare
}

void heapsort_int_arr(int *arr, size_t count) {
#define fn_compare(x, y) x > y
    heapsort(arr, count, fn_compare);
#undef fn_compare
}

void test_bisect_left_int_arr() {
    printf("Testing bisect_left_int_arr\n");
    int arr1[] = {1, 3, 5, 7, 9};
    assert(bisect_left_int_arr(5, 0, 5, arr1, 5) == 2);  // Target is 5, position should be 2

    int arr2[] = {1, 3, 5, 7, 9};
    assert(bisect_left_int_arr(0, 0, 5, arr2, 5) == 0);  // Target is smaller than all elements

    int arr3[] = {1, 3, 5, 7, 9};
    assert(bisect_left_int_arr(10, 0, 5, arr3, 5) == 5); // Target is larger than all elements

    int arr4[] = {1, 3, 5, 7, 9};
    assert(bisect_left_int_arr(6, 0, 5, arr4, 5) == 3);  // Target is between 5 and 7

    int arr5[] = {1, 3, 5, 7, 9};
    assert(bisect_left_int_arr(7, 0, 5, arr5, 5) == 3);  // Target is 7, first occurrence

    int arr6[] = {1, 3, 4, 4, 5, 6};
    assert(bisect_left_int_arr(4, 0, 6, arr6, 6) == 2);  // Target is 4, before second occurrence

    int arr7[] = {};
    assert(bisect_left_int_arr(5, 0, 0, arr7, 0) == 0);  // Empty array

    int arr8[] = {1, 3, 5, 7, 9};
    assert(bisect_left_int_arr(9, 0, 5, arr8, 5) == 4);  // Target is last element

    int arr9[] = {1};
    assert(bisect_left_int_arr(1, 0, 1, arr9, 1) == 0);  // Single element array

    int arr10[100];
    for (int i = 0; i < 100; i++) arr10[i] = i + 1;
    assert(bisect_left_int_arr(50, 0, 100, arr10, 100) == 49);  // Large array, target 50
}

void test_bisect_right_int_arr() {
    printf("Testing bisect_right_int_arr\n");
    int arr1[] = {1, 3, 5, 7, 9};
    assert(bisect_right_int_arr(5, 0, 5, arr1, 5) == 3);  // Target is 5, position should be 3 (after 5)

    int arr2[] = {1, 3, 5, 7, 9};
    assert(bisect_right_int_arr(0, 0, 5, arr2, 5) == 0);  // Target is smaller than all elements

    int arr3[] = {1, 3, 5, 7, 9};
    assert(bisect_right_int_arr(10, 0, 5, arr3, 5) == 5); // Target is larger than all elements

    int arr4[] = {1, 3, 5, 7, 9};
    assert(bisect_right_int_arr(6, 0, 5, arr4, 5) == 3);  // Target is between 5 and 7

    int arr5[] = {1, 3, 5, 7, 9};
    assert(bisect_right_int_arr(7, 0, 5, arr5, 5) == 4);  // Target is 7, after the first 7

    int arr6[] = {1, 3, 4, 4, 5, 6};
    assert(bisect_right_int_arr(4, 0, 6, arr6, 6) == 4);  // Target is 4, after second occurrence

    int arr7[] = {};
    assert(bisect_right_int_arr(5, 0, 0, arr7, 0) == 0);  // Empty array

    int arr8[] = {1, 3, 5, 7, 9};
    assert(bisect_right_int_arr(9, 0, 5, arr8, 5) == 5);  // Target is last element, after 9

    int arr9[] = {1};
    assert(bisect_right_int_arr(1, 0, 1, arr9, 1) == 1);  // Single element array, after 1

    int arr10[100];
    for (int i = 0; i < 100; i++) arr10[i] = i + 1;
    assert(bisect_right_int_arr(50, 0, 100, arr10, 100) == 50);  // Large array, target 50
}

void test_heapify_int_arr() {
    printf("Testing heapify_int_arr\n");
    int arr1[] = {4, 10, 3, 5, 1};
    heapify_int_arr(arr1, 5, 0);
    assert(arr1[0] == 10 && arr1[1] == 5 && arr1[2] == 3);  // Root 1 should become 10, array should become {10, 5, 3, 4, 1}

    int arr2[] = {5};
    heapify_int_arr(arr2, 1, 0);
    assert(arr2[0] == 5);  // Single element, array remains the same
}

void test_build_heap_int_arr() {
    printf("Testing build_heap_int_arr\n");
    int arr1[] = {4, 10, 3, 5, 1};
    build_heap_int_arr(arr1, 5);
    assert(arr1[0] == 10 && arr1[1] == 5 && arr1[2] == 3);  // After build heap, array should become {10, 5, 3, 4, 1}

    int arr2[] = {1, 3, 5, 7, 9};
    build_heap_int_arr(arr2, 5);
    assert(arr2[0] == 9 && arr2[1] == 7 && arr2[2] == 5);  // After build heap, array should become {9, 7, 5, 3, 1}
}

void test_heapsort_int_arr() {
    printf("Testing heapsort_int_arr\n");
    int arr1[] = {4, 10, 3, 5, 1};
    heapsort_int_arr(arr1, 5);
    assert(arr1[0] == 1 && arr1[1] == 3 && arr1[2] == 4 && arr1[3] == 5 && arr1[4] == 10);

    int arr2[] = {9, 7, 5, 3, 1};
    heapsort_int_arr(arr2, 5);
    assert(arr2[0] == 1 && arr2[1] == 3 && arr2[2] == 5 && arr2[3] == 7 && arr2[4] == 9);
}

int main() {
    test_bisect_left_int_arr();
    test_bisect_right_int_arr();
    test_heapify_int_arr();
    test_build_heap_int_arr();
    test_heapsort_int_arr();
    printf("All tests passed!\n");
    return 0;
}

