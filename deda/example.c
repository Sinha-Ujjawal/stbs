#include <stdio.h>

#define DEDA_IMPLEMENTATION
#include "deda.h"
#undef DEDA_INIT_CAP
#define DEDA_INIT_CAP 6

deda_type(string_deda, char);
deda_type(int_deda, int);

void example1() {
    printf("------------------------------------Example 1--------------------------------------\n");
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
}

void example2() {
    printf("------------------------------------Example 2--------------------------------------\n");
    string_deda deda = {0};
    deda_init(&deda);

    deda_push(&deda, 'a'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'b'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'c'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'd'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'e'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'f'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'g'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'h'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'i'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'j'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'k'); deda_debug(deda, "%c"); printf("\n");

    deda_push_front(&deda, '0'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '2'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '3'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '4'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '5'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '6'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '7'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '8'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '9'); deda_debug(deda, "%c"); printf("\n");

    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");

    if (deda.data != NULL) {
        free(deda.data);
    }
}

void example3() {
    printf("------------------------------------Example 3--------------------------------------\n");
    string_deda deda = {0};
    deda_init(&deda);

    deda_push(&deda, 'a'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'b'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'c'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'd'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'e'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'f'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'g'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'h'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'i'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'j'); deda_debug(deda, "%c"); printf("\n");
    deda_push(&deda, 'k'); deda_debug(deda, "%c"); printf("\n");

    deda_push_front(&deda, '0'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '2'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '3'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '4'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '5'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '6'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '7'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '8'); deda_debug(deda, "%c"); printf("\n");
    deda_push_front(&deda, '9'); deda_debug(deda, "%c"); printf("\n");

    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");
    deda_insert_at(&deda, 5, '_'); deda_debug(deda, "%c"); printf("\n");

    char res;
    deda_pop_at(&deda, 5, &res); deda_debug(deda, "%c"); printf("\n"); assert(res == '_');
    deda_pop_at(&deda, 5, &res); deda_debug(deda, "%c"); printf("\n"); assert(res == '_');
    deda_pop_at(&deda, 5, &res); deda_debug(deda, "%c"); printf("\n"); assert(res == '_');
    deda_pop_at(&deda, 5, &res); deda_debug(deda, "%c"); printf("\n"); assert(res == '_');
    deda_pop_at(&deda, 5, &res); deda_debug(deda, "%c"); printf("\n"); assert(res == '_');
    deda_pop_at(&deda, 5, &res); deda_debug(deda, "%c"); printf("\n"); assert(res == '_');

    if (deda.data != NULL) {
        free(deda.data);
    }
}

int main() {
    example1();
    example2();
    example3();
    return 0;
}
