# **D**ynamic **A**rrays in C
This is a [stb](https://github.com/nothings/stb) style library implementing a [Dynamic Arrays](https://en.wikipedia.org/wiki/Dynamic_array) in C.
This is only for recreational purpose and not for any real world use. If you still want to use this in your project, feel free to do so at your own risk.

# Following functions are supposed to be used by the user

All the functions exposed are C macros

| Function             | Signature           | Description                                                 |
| --------             | ---------           | ----------------------------------------------------------- |
| da\_type             | (name, type)        | declares a da array type                                    |
| da\_init             | (da)                | initialize the da array with initial values                 |
| da\_push             | (da, item)          | appends the item at the end of the da array                 |
| da\_ensure\_capacity | (da, min\_capacity) | grows the dynamic array to ensure the minimum capacity      |
| da\_grow             | (da)                | grows the dynamic array by 1 also set the count by 1        |
| da\_pop              | (da)                | removes and returns the item from the end of the da array   |
| da\_shrink           | (da)                | shrinks the dynamic array by 1                              |
| da\_get\_at          | (da, idx, result)   | get and store the item at index `idx` to result variable    |
| da\_index            | (da, idx)           | helper macro to index into the dynamic array                |
| da\_first            | (da)                | helper macro to index first element in the da               |
| da\_last             | (da)                | helper macro to index last element in the da                |
| da\_put\_at          | (da, idx, item)     | replace the old item with the new one at index `idx`        |
| da\_insert\_at       | (da, idx, item)     | insert the item at index `idx`                              |
| da\_delete\_at       | (da, idx)           | removes the item at index `idx`                             |
| da\_pop\_at          | (da, idx, result)   | stores the item at `idx` to result and deletes it           |

# Example program
```C
#include <stdio.h>

#define da_IMPLEMENTATION
#include "da.h"

da_type(string_da, char);
da_type(int_da, int);

int main() {
    string_da sda = {0};
    da_init(&sda);
    da_push(&sda, 'h');
    da_push(&sda, 'e');
    da_push(&sda, 'l');
    da_push(&sda, 'l');
    da_push(&sda, 'o');
    char cres;
    for (size_t i = 0; i < sda.count; i++) {
        da_get_at(sda, i, &cres);
        printf("%c", cres);
    }
    printf("\n");
    // hello
    da_pop(&sda, &cres); printf("%c\n", cres); // o
    da_pop(&sda, &cres); printf("%c\n", cres); // l
    da_pop(&sda, &cres); printf("%c\n", cres); // l
    da_pop(&sda, &cres); printf("%c\n", cres); // e
    da_pop(&sda, &cres); printf("%c\n", cres); // h

    int_da ida = {0};
    da_init(&ida);
    da_push(&ida, 1);
    da_push(&ida, 2);
    da_push(&ida, 3);
    da_push(&ida, 4);
    da_insert_at(&ida, 0, 5);
    da_insert_at(&ida, 0, 6);
    int ires;
    for (size_t i = 0; i < ida.count; i++) {
        da_get_at(ida, i, &ires);
        printf("%d", ires);
    }
    printf("\n");
    // 651234
    da_delete_at(&ida, 4);
    for (size_t i = 0; i < ida.count; i++) {
        da_get_at(ida, i, &ires);
        printf("%d", ires);
    }
    printf("\n");
    // 65124

    if (sda.data != NULL) {
        free(sda.data);
    }
    if (ida.data != NULL) {
        free(ida.data);
    }
    return 0;
}
```
