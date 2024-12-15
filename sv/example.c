#include <stdio.h>
#include <string.h>

#define SV_IMPLEMENTATION
#include "sv.h"

void test_sv_from_ptr() {
    printf("test_sv_from_ptr\n");
    char *data = "Hello, world!";
    size_t count = 5;
    sv result = sv_from_ptr(data, count);
    assert(result.data == data);
    assert(result.count == count);

    // Edge case: NULL data
    result = sv_from_ptr(NULL, count);
    assert(result.data == NULL);
    assert(result.count == count);
}

void test_sv_from_cstr() {
    printf("test_sv_from_cstr\n");
    const char *data = "Hello";
    sv result = sv_from_cstr(data);
    assert(result.data == data);
    assert(result.count == strlen(data));

    // Edge case: Empty string
    result = sv_from_cstr("");
    assert(result.data != NULL); // Should not be NULL
    assert(result.count == 0);
}

void test_sv_take_n() {
    printf("test_sv_take_n\n");
    sv input = sv_from_cstr("Hello, world!");
    size_t n = 5;
    sv result = sv_take_n(input, n);
    assert(result.count == n);
    assert(strncmp(result.data, "Hello", n) == 0);

    // Edge case: n greater than string length
    result = sv_take_n(input, 50);
    assert(result.count == input.count);
    assert(strncmp(result.data, input.data, input.count) == 0);

    // Edge case: n is zero
    result = sv_take_n(input, 0);
    assert(result.count == 0);
    assert(strncmp(result.data, "", 0) == 0);
}

void test_sv_drop_n() {
    printf("test_sv_drop_n\n");
    sv input = sv_from_cstr("Hello, world!");
    size_t n = 7;
    sv result = sv_drop_n(input, n);
    assert(result.count == (strlen("Hello, world!") - n));
    assert(strncmp(result.data, "world!", result.count) == 0);

    // Edge case: n greater than string length
    result = sv_drop_n(input, 50);
    assert(result.count == 0);
    assert(strncmp(result.data, "", 0) == 0);

    // Edge case: n is zero
    result = sv_drop_n(input, 0);
    assert(result.count == input.count);
    assert(strncmp(result.data, input.data, input.count) == 0);
}

void test_sv_trim_left() {
    printf("test_sv_trim_left\n");
    sv input = sv_from_cstr("   leading space");
    sv result = sv_trim_left(input);
    assert(result.count == strlen("leading space"));
    assert(strncmp(result.data, "leading space", result.count) == 0);

    // Edge case: No leading spaces
    input = sv_from_cstr("NoSpace");
    result = sv_trim_left(input);
    assert(result.count == input.count);
    assert(strncmp(result.data, input.data, input.count) == 0);

    // Edge case: All spaces
    input = sv_from_cstr("     ");
    result = sv_trim_left(input);
    assert(result.count == 0);
    assert(strncmp(result.data, "", 0) == 0);
}

void test_sv_split_at() {
    printf("test_sv_split_at\n");
    sv input = sv_from_cstr("SplitHere");
    size_t idx = 5;
    sv_pair result = sv_split_at(input, idx);
    assert(result.fst.count == 5);
    assert(strncmp(result.fst.data, "Split", 5) == 0);
    assert(result.snd.count == 4);
    assert(strncmp(result.snd.data, "Here", 4) == 0);

    // Edge case: idx is 0
    result = sv_split_at(input, 0);
    assert(result.fst.count == 0);
    assert(result.snd.count == input.count);

    // Edge case: idx is equal to string length
    result = sv_split_at(input, input.count);
    assert(result.fst.count == input.count);
    assert(result.snd.count == 0);
}

void test_sv_split_by_char() {
    printf("test_sv_split_by_char\n");
    sv input = sv_from_cstr("Key:Value");
    sv_pair result = sv_split_by_char(input, ':');
    assert(result.fst.count == 3);
    assert(strncmp(result.fst.data, "Key", 3) == 0);
    assert(result.snd.count == 5);
    assert(strncmp(result.snd.data, "Value", 5) == 0);

    // Edge case: Character not present
    result = sv_split_by_char(input, '-');
    assert(result.fst.count == input.count);
    assert(result.snd.count == 0);

    // Edge case: Empty string
    input = sv_from_cstr("");
    result = sv_split_by_char(input, ':');
    assert(result.fst.count == 0);
    assert(result.snd.count == 0);
}

void test_sv_substring() {
    printf("test_sv_substring\n");
    sv input = sv_from_cstr("Extract substring");
    size_t begin = 8;
    size_t count = 9;
    sv result = sv_substring(input, begin, count);
    assert(result.count == count);
    assert(strncmp(result.data, "substring", count) == 0);

    // Edge case: begin > input.count
    result = sv_substring(input, 50, 5);
    assert(result.count == 0);
    assert(result.data == NULL);

    // Edge case: begin + count > input.count
    result = sv_substring(input, 10, 50);
    assert(result.count == input.count - 10);
}

void test_sv_find() {
    printf("test_sv_find\n");
    sv input = sv_from_cstr("Find the substring");
    sv to_find = sv_from_cstr("substring");
    int idx = sv_find(input, to_find);
    assert(idx == 9);

    // Edge case: to_find is not in input
    sv not_found = sv_from_cstr("missing");
    assert(sv_find(input, not_found) == -1);

    // Edge case: to_find is empty
    sv empty = sv_from_cstr("");
    assert(sv_find(input, empty) == 0);
}

void test_sv_starts_with() {
    printf("test_sv_starts_with\n");
    sv input = sv_from_cstr("Hello, world!");
    sv prefix = sv_from_cstr("Hello");

    // Regular case: Input starts with prefix
    assert(sv_starts_with(input, prefix) == true);

    // Edge case: Input does not start with prefix
    sv not_prefix = sv_from_cstr("world");
    assert(sv_starts_with(input, not_prefix) == false);

    // Edge case: Prefix is longer than input
    sv long_prefix = sv_from_cstr("Hello, world! Extended");
    assert(sv_starts_with(input, long_prefix) == false);

    // Edge case: Prefix is empty
    sv empty_prefix = sv_from_cstr("");
    assert(sv_starts_with(input, empty_prefix) == true);

    // Edge case: Input is empty
    sv empty_input = sv_from_cstr("");
    assert(sv_starts_with(empty_input, prefix) == false);

    // Edge case: Both input and prefix are empty
    assert(sv_starts_with(empty_input, empty_prefix) == true);
}

void test_sv_parse_long() {
    printf("test_sv_parse_long\n");
    long parsed_value;

    // Parsing positive value
    assert(sv_parse_long(sv_from_cstr("123"), &parsed_value, NULL) == true);
    assert(parsed_value == 123);

    // Parsing negative value
    assert(sv_parse_long(sv_from_cstr("-456"), &parsed_value, NULL) == true);
    assert(parsed_value == -456);

    // Parsing invalid string
    assert(sv_parse_long(sv_from_cstr("something not a long"), &parsed_value, NULL) == false);

    // Parsing empty
    assert(sv_parse_long(sv_from_cstr(""), &parsed_value, NULL) == false);
}

void test_sv_parse_longlong() {
    printf("test_sv_parse_longlong\n");
    long long parsed_value;

    // Parsing positive value
    assert(sv_parse_longlong(sv_from_cstr("123"), &parsed_value, NULL) == true);
    assert(parsed_value == 123);

    // Parsing negative value
    assert(sv_parse_longlong(sv_from_cstr("-456"), &parsed_value, NULL) == true);
    assert(parsed_value == -456);

    // Parsing invalid string
    assert(sv_parse_longlong(sv_from_cstr("something not a long"), &parsed_value, NULL) == false);

    // Parsing empty
    assert(sv_parse_longlong(sv_from_cstr(""), &parsed_value, NULL) == false);
}

int main() {
    test_sv_from_ptr();
    test_sv_from_cstr();
    test_sv_take_n();
    test_sv_drop_n();
    test_sv_trim_left();
    test_sv_split_at();
    test_sv_split_by_char();
    test_sv_substring();
    test_sv_find();
    test_sv_starts_with();
    test_sv_parse_long();
    test_sv_parse_longlong();
    printf("All tests (including edge cases) passed!\n");
    return 0;
}
