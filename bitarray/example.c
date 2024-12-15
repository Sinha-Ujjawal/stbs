#include <stdio.h>
#include <assert.h>

// Enable the implementation
#define BITARRAY_IMPLEMENTATION
#include "bitarray.h"


int main() {
    bitarray bits = {0};

    // Test 1: Reset the bitarray
    bitarray_reset(&bits, 16); // Reset with capacity of 16 bits
    assert(bits.capacity == 16);
    assert(bits.count == 0);

    // Test 2: Set a bit and check
    assert(bitarray_set(&bits, 3) == true);  // Set bit at position 3
    assert(bitarray_isset(bits, 3) == true); // Ensure bit is set
    assert(bits.count == 1);

    // Test 3: Set the same bit again (should fail)
    assert(bitarray_set(&bits, 3) == false);
    assert(bits.count == 1); // Count should not increase

    // Test 4: Set another bit
    assert(bitarray_set(&bits, 10) == true);  // Set bit at position 10
    assert(bitarray_isset(bits, 10) == true); // Ensure bit is set
    assert(bits.count == 2);

    // Test 5: Unset a bit and check
    assert(bitarray_unset(&bits, 3) == true);   // Unset bit at position 3
    assert(bitarray_isset(bits, 3) == false);  // Ensure bit is unset
    assert(bits.count == 1);

    // Test 6: Unset the same bit again (should fail)
    assert(bitarray_unset(&bits, 3) == false); // Unset already unset bit
    assert(bits.count == 1);                  // Count should not decrease

    // Test 7: Attempt to set a bit out of bounds
    assert(bitarray_set(&bits, 17) == false);  // Out of bounds
    assert(bitarray_isset(bits, 17) == false); // Should be false

    // Test 8: Attempt to unset a bit out of bounds
    assert(bitarray_unset(&bits, 17) == false); // Out of bounds

    // Test 9: Attempt to check a bit out of bounds
    assert(bitarray_isset(bits, 17) == false); // Out of bounds

    // Test 10: Print the bitarray
    printf("Bitarray after operations: ");
    bitarray_print(bits); // Expect output to match bit pattern

    // Test 11: Reset the bitarray and check
    bitarray_reset(&bits, 8);   // Reset with capacity of 8 bits
    assert(bits.capacity == 8); // Capacity should now be 8
    assert(bits.count == 0);    // All bits should be cleared

    printf("Bitarray after reset: ");
    bitarray_print(bits); // Should be empty

    // Clean up
    free(bits.buckets);

    printf("All tests passed!\n");
    return 0;
}
