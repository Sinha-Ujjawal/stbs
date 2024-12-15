# Bitarray in C
This is a [stb](https://github.com/nothings/stb) style library implementing an [Bitarray](https://en.wikipedia.org/wiki/Bit_array) in C.
This is only for recreational purpose and not for any real world use. If you still want to use this in your project, feel free to do so at your own risk.

# Following functions are supposed to be used by the user

| Function                                              | Description                                                                                                   |
| ----------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| void bitarray\_reset(bitarray *bits, size_t capacity) | Resets a bitarray with a given capacity                                                                       |
| bool bitarray_set(bitarray *bits, size_t posn)        | Set a given position in the bitarray. Returns true if the position is newly set                               |
| bool bitarray_unset(bitarray *bits, size_t posn)      | Unset a given position is the bitarray. Returns  true if the position is previously set and now has been uset |
| bool bitarray_isset(bitarray bits, size_t posn)       | Checks if a given position is set in the bitarray                                                             |
| void bitarray_print(bitarray bits)                    | Helper function to print the contents of the bitarray                                                         |

# Example program
[example.c](./example.c)
