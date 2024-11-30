#include <stdio.h>

#define DA_IMPLEMENTATION
#include "da.h"
#undef DA_INIT_CAP
#define DA_INIT_CAP 6

da_type(string_da, char);
da_type(int_da, int);

void example1() {
    printf("------------------------------------Example 1--------------------------------------\n");
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
}

void example2() {
    printf("------------------------------------Example 2--------------------------------------\n");
    string_da da = {0};
    da_init(&da);

    da_push(&da, 'a'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'b'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'c'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'd'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'e'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'f'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'g'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'h'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'i'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'j'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'k'); da_debug(da, "%c"); printf("\n");

    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");

    if (da.data != NULL) {
        free(da.data);
    }
}

void example3() {
    printf("------------------------------------Example 3--------------------------------------\n");
    string_da da = {0};
    da_init(&da);

    da_push(&da, 'a'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'b'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'c'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'd'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'e'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'f'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'g'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'h'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'i'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'j'); da_debug(da, "%c"); printf("\n");
    da_push(&da, 'k'); da_debug(da, "%c"); printf("\n");

    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 4, '$'); da_debug(da, "%c"); printf("\n");

    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");
    da_insert_at(&da, 5, '_'); da_debug(da, "%c"); printf("\n");

    char res;
    da_pop_at(&da, 5, &res); da_debug(da, "%c"); printf("\n"); assert(res == '_');
    da_pop_at(&da, 5, &res); da_debug(da, "%c"); printf("\n"); assert(res == '_');
    da_pop_at(&da, 5, &res); da_debug(da, "%c"); printf("\n"); assert(res == '_');
    da_pop_at(&da, 5, &res); da_debug(da, "%c"); printf("\n"); assert(res == '_');
    da_pop_at(&da, 5, &res); da_debug(da, "%c"); printf("\n"); assert(res == '_');
    da_pop_at(&da, 5, &res); da_debug(da, "%c"); printf("\n"); assert(res == '_');

    da_delete_at(&da, 0); da_debug(da, "%c");
    da_delete_at(&da, 0); da_debug(da, "%c");
    da_delete_at(&da, 0); da_debug(da, "%c");
    da_delete_at(&da, 0); da_debug(da, "%c");
    da_delete_at(&da, 0); da_debug(da, "%c");
    da_delete_at(&da, 0); da_debug(da, "%c");
    da_delete_at(&da, 0); da_debug(da, "%c");

    if (da.data != NULL) {
        free(da.data);
    }
}

int main() {
    example1();
    example2();
    example3();
    return 0;
}
