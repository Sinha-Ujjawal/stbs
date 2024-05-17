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

