# String View implementation in C.

This is a stb style library implementing [String View](https://stackoverflow.com/questions/20803826/what-is-string-view) in C.

# Following functions are supposed to be used by the user

| Function                        | Description                                                                                                                                                              |
| ------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| sv\_from\_ptr(ptr, count)       | creates a string view from a character pointer and given count                                                                                                           |
| sv\_from\_cstr(cstr)            | creates a string view from a null '\0' terminated string                                                                                                                 |
| sv\_take\_n(sv, n)              | creates a new string view from a given string view, but just taking n elements from the begining `sv[:n]`                                                                |
| sv\_drop\_n(sv, n)              | creates a new string view from a given string view, but just taking n elements from the end `sv[n:]`                                                                     |
| sv\_split\_at(sv, idx)          | splits the given string view at index idx. It returns a new string view having elements from [0..idx] `sv[:idx+1]`. The passed string view is mutated to be `sv[idx+1:]` |
| sv\_substring(sv, begin ,count) | creates a new string view that is a substring. `sv[begin:begin+count]`                                                                                                   |

# Example program
```C
#include <stdio.h>

#define SV_IMPLEMENTATION
#include "sv.h"

int main(void) {
    sv x = sv_from_cstr("apple");
    printf("\""SV_FMT"\"\n", SV_DATA(x)); // apple

    sv y;

    y = sv_take_n(x, 3);
    printf("\""SV_FMT"\"\n", SV_DATA(y)); // app

    y = sv_drop_n(x, 3);
    printf("\""SV_FMT"\"\n", SV_DATA(y)); // le

    y = sv_substring(x, 1, 3);
    printf("\""SV_FMT"\"\n", SV_DATA(y)); // ppl

    y = sv_split_at(&x, 1);
    printf("\""SV_FMT"\"\n", SV_DATA(y)); // ap
    printf("\""SV_FMT"\"\n", SV_DATA(x)); // ple

    return 0;
}
```
