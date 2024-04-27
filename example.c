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
