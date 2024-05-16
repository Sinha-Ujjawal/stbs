# **D**ouble **E**nded **D**ynamic **A**rrays in C
This is a [stb](https://github.com/nothings/stb) style library implementing a [Double Ended Dynamic Array](https://en.wikipedia.org/wiki/Double-ended_queue) in C.
This is only for recreational purpose and not for any real world use. If you still want to use this in your project, feel free to do so at your own risk.

# Following functions are supposed to be used by the user

All the functions exposed are C macros

| Function          | Signature           | Description                                                   |
| --------          | ---------           | -----------------------------------------------------------   |
| deda\_type        | (name, type)        | declares a deda array type                                    |
| deda\_init        | (deda)              | initialize the deda array with initial values                 |
| deda\_push        | (deda, item)        | appends the item at the end of the deda array                 |
| deda\_pop         | (deda)              | removes and returns the item from the end of the deda array   |
| deda\_push\_front | (deda, item)        | prepends the item at the front of the deda array              |
| deda\_pop\_front  | (deda)              | removes and returns the item from the front of the deda array |
| deda\_get\_at     | (deda, idx result)  | get and store the item at index `idx` to result variable      |
| deda\_put\_at     | (deda, idx, item)   | replace the old item with the new one at index `idx`          |
| deda\_insert\_at  | (deda, idx, item)   | insert the item at index `idx`                                |
| deda\_delete\_at  | (deda, idx)         | removes the item at index `idx`                               |
| deda\_pop\_at     | (deda, idx, result) | stores the item at `idx` to result and deletes it             |

# Example program
```C
#include <stdio.h>

#define DEDA_IMPLEMENTATION
#include "deda.h"

deda_type(string_deda, char);
deda_type(int_deda, int);

int main() {
    string_deda sdeda = {0};
    deda_init(&sdeda);
    deda_push(&sdeda, 'h');
    deda_push(&sdeda, 'e');
    deda_push(&sdeda, 'l');
    deda_push(&sdeda, 'l');
    deda_push(&sdeda, 'o');
    char cres;
    for (size_t i = 0; i < sdeda.count; i++) {
        deda_get_at(sdeda, i, &cres);
        printf("%c", cres);
    }
    printf("\n");
    // hello
    deda_pop(&sdeda, &cres); printf("%c\n", cres); // o
    deda_pop(&sdeda, &cres); printf("%c\n", cres); // l
    deda_pop(&sdeda, &cres); printf("%c\n", cres); // l
    deda_pop(&sdeda, &cres); printf("%c\n", cres); // e
    deda_pop(&sdeda, &cres); printf("%c\n", cres); // h

    int_deda ideda = {0};
    deda_init(&ideda);
    deda_push(&ideda, 1);
    deda_push(&ideda, 2);
    deda_push(&ideda, 3);
    deda_push(&ideda, 4);
    deda_push_front(&ideda, 5);
    deda_push_front(&ideda, 6);
    int ires;
    for (size_t i = 0; i < ideda.count; i++) {
        deda_get_at(ideda, i, &ires);
        printf("%d", ires);
    }
    printf("\n");
    // 651234
    deda_delete_at(&ideda, 4);
    for (size_t i = 0; i < ideda.count; i++) {
        deda_get_at(ideda, i, &ires);
        printf("%d", ires);
    }
    printf("\n");
    // 65124

    if (sdeda.data != NULL) {
        free(sdeda.data);
    }
    if (ideda.data != NULL) {
        free(ideda.data);
    }
    return 0;
}
```
