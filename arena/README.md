# Arena in C
This is a [stb](https://github.com/nothings/stb) style library implementing a [Arena](https://github.com/tsoding/arena) in C.
This is only for recreational purpose and not for any real world use. If you still want to use this in your project, feel free to do so at your own risk.

# Allocation strategies
There are currently three strategies of memory allocation implemented, and can be switched by assigning the `ARENA_TYPE` macro to the corresponding macro. By default `ARENA_TYPE` is set to `ARENA_TYPE_SCAN_HEAP`.

| Macro | Description |
| ----- | ----------- |
| ARENA\_TYPE\_SIMPLE | Simple arena type, just creates new region block if the allocated size exceeds last block's remaining capacity |
| ARENA\_TYPE\_SCAN\_LINEAR | This implementation does a linear scan of the blocks to find a block with sufficient size, and then allocates the new memory in that block. If no such blocks found, then create a new block and allocate in that. |
| ARENA\_TYPE\_SCAN\_HEAP | This implementation maintains a binary heap sort by max. remaining capacity. It first checks if the region of max. remaining capacity is enough for the new memory, if yes allocates it there, otherwise creates a new block and allocate the new memory there. |

# Following functions are supposed to be used by the user

| Function        | Signature                                 | Description                                                            |
| --------------- | ----------------------------------------- | ---------------------------------------------------------------------- |
| arena\_alloc    | (arena, bytes)                            | Allocates new memory with given size and returns pointer to the memory |
| arena\_realloc  | (arena, old\_ptr, old\_bytes, new\_bytes) | Resize the given pointer with new size. Similar to C realloc           |
| arena\_reset    | (arena)                                   | Reset's all regions in the arena to 0. Same blocks can be reused again |
| arena\_free     | (arena)                                   | Deallocates all the regions from the global memory                     |
| arena\_debug    | (arena)                                   | Helper function to print memory regions in the arena                   |

# Example program
[example.c](./example.c)
