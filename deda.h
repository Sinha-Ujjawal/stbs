// Copyright 2024 <Sinha-Ujjawal>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef DEDA_H
#define DEDA_H

#ifdef DEDA_IMPLEMENTATION
#include <stdlib.h>
#include <assert.h>

#define DEDA_INIT_CAP          64
#define DEDA_GROWTH_FACTOR     2.5
#define DEDA_SHRINK_FACTOR     0.5
#define DEDA_SHRINK_THRESHOLD  0.25
#define DEDA_BEGIN_POSN_FACTOR 0.5

/* `deda` is a structure matching below signature-
    `t` is a type parameter
    typedef struct {
        size_t begin;
        size_t count;
        size_t capacity;
        t*     data;
        ...
    };
*/

#define deda_type(name, t) typedef struct {\
    size_t begin;\
    size_t count;\
    size_t capacity;\
    t*     data;\
} name;\

#define deda_init(deda) {\
    (deda)->capacity = DEDA_INIT_CAP;\
    (deda)->begin    = DEDA_INIT_CAP * DEDA_BEGIN_POSN_FACTOR;\
    (deda)->count    = 0;\
    (deda)->data     = malloc(sizeof(*(deda)->data) * (deda)->capacity);\
}\

#define _deda_resize(deda, new_capacity) {\
    size_t new_begin              = (new_capacity) * DEDA_BEGIN_POSN_FACTOR;\
    typeof((deda)->data) new_data = malloc(sizeof(*(deda)->data) * (new_capacity));\
    for (size_t i = 0; i < (deda)->count; i++) {\
        new_data[(new_begin + i) % (new_capacity)] = (deda)->data[((deda)->begin + i) % (deda)->capacity];\
    }\
    free((deda)->data);\
    (deda)->capacity = (new_capacity);\
    (deda)->begin    = new_begin;\
    (deda)->data     = new_data;\
}\

#define _deda_grow(deda) {\
    size_t new_capacity = (deda)->capacity * DEDA_GROWTH_FACTOR;\
    _deda_resize(deda, new_capacity);\
}\

#define _deda_shrink(deda) {\
    size_t new_capacity = (deda)->capacity * DEDA_SHRINK_FACTOR;\
    _deda_resize(deda, new_capacity);\
}\

#define deda_push(deda, item) {\
    if ((deda)->count >= (deda)->capacity) {\
        _deda_grow(deda);\
    }\
    (deda)->data[((deda)->begin + (deda)->count) % (deda)->capacity] = (item);\
    (deda)->count += 1;\
}\

#define deda_pop(deda, result) {\
    if ((deda)->count > 0) {\
        (deda)->count -= 1;\
        *(result) = (deda)->data[((deda)->begin + (deda)->count) % (deda)->capacity];\
        if ((deda)->count <= (deda)->capacity * DEDA_SHRINK_THRESHOLD) {\
            _deda_shrink(deda);\
        }\
    }\
}\

#define deda_push_front(deda, item) {\
    if ((deda)->count >= (deda)->capacity) {\
        _deda_grow(deda);\
    }\
    if ((deda)->begin == 0) {\
        (deda)->begin = (deda)->capacity;\
    }\
    (deda)->begin -= 1;\
    (deda)->data[(deda)->begin] = (item);\
    (deda)->count += 1;\
}\

#define deda_pop_front(deda, result) {\
    if ((deda)->count > 0) {\
        (deda)->count -= 1;\
        *(result) = (deda)->data[(deda)->begin];\
        (deda)->begin = ((deda)->begin + 1) % (deda)->capacity;\
        if ((deda)->count <= (deda)->capacity * DEDA_SHRINK_THRESHOLD) {\
            _deda_shrink(deda);\
        }\
    }\
}\

#define deda_get_at(deda, idx, result) {\
    assert((((idx) >= 0) && ((idx) < (deda).count)) && "Index out of bounds!");\
    *(result) = (deda).data[((idx) + (deda).begin) % (deda).capacity];\
}\

#define deda_put_at(deda, idx, item) {\
    assert((((idx) >= 0) && ((idx) < (deda).count)) && "Index out of bounds!");\
    (deda).data[((idx) + (deda).begin) % (deda)->capacity] = (item);\
}\

#define _deda_move(deda, start, end, off) {\
    if ((off) > 0) {\
        for (size_t j = end; (j <= end) && (j >= start); j--) {\
            (deda)->data[(j + (deda)->begin + off) % (deda)->capacity] = (deda)->data[(j + (deda)->begin) % (deda)->capacity];\
        }\
    }\
    else if ((off) < 0) {\
        for (int j = start; j <= end; j++) {\
            int idx = (j + (int)(deda)->begin + off) % (int)(deda)->capacity;\
            if (idx < 0) {\
               idx += (int)(deda)->capacity;\
            }\
            (deda)->data[idx] = (deda)->data[(j + (deda)->begin) % (deda)->capacity];\
        }\
    }\
}\

#define _deda_make_room(deda, idx) {\
    if ((deda)->count == (deda)->capacity) {\
        _deda_grow(deda);\
    }\
    if ((idx) >= (deda)->count >> 1) {\
        _deda_move(deda, idx, (deda)->count - 1, 1);\
    }\
    else {\
        _deda_move(deda, 0, idx, -1);\
        if ((deda)->begin == 0) {\
            (deda)->begin = (deda)->capacity;\
        }\
        (deda)->begin -= 1;\
    }\
}\

#define deda_insert_at(deda, idx, item) {\
    assert((((idx) >= 0) && ((idx) <= (deda)->count)) && "Index out of bounds!");\
    if ((idx) == 0) {\
        deda_push_front(deda, item);\
    }\
    else if ((idx) == (deda)->count) {\
        deda_push(deda, item);\
    }\
    else {\
        _deda_make_room(deda, idx);\
        (deda)->data[((idx) + (deda)->begin) % (deda)->capacity] = (item);\
        (deda)->count += 1;\
    }\
}\

#define deda_delete_at(deda, idx) {\
    assert((((idx) >= 0) && ((idx) < (deda)->count)) && "Index out of bounds!");\
    if ((idx) == 0) {\
        (deda)->begin = ((deda)->begin + 1) % (deda)->capacity;\
    }\
    else if ((idx) >= (deda)->count >> 1) {\
        _deda_move(deda, (idx) + 1, (deda)->count - 1, -1);\
    }\
    else if ((idx) != (deda)->count - 1) {\
        _deda_move(deda, 0, (idx) - 1, 1);\
        (deda)->begin = ((deda)->begin + 1) % (deda)->capacity;\
    }\
    (deda)->count -= 1;\
    if ((deda)->count <= (deda)->capacity * DEDA_SHRINK_THRESHOLD) {\
        _deda_shrink(deda);\
    }\
}\

#define deda_pop_at(deda, idx, res) {\
    assert((((idx) >= 0) && ((idx) < (deda)->count)) && "Index out of bounds!");\
    *(res) = (deda)->data[(idx + (deda)->begin) % (deda)->capacity];\
    deda_delete_at(deda, idx);\
}\

#define deda_debug(deda, fmt) {\
    printf("Begin   : %zu\n", (deda).begin);\
    printf("Count   : %zu\n", (deda).count);\
    printf("Capacity: %zu\n", (deda).capacity);\
    if ((deda).count > 0) {\
        typeof(*deda.data) res;\
        for (size_t i = 0; i < (deda).count; i++) {\
            deda_get_at(deda, i, &res);\
            printf(fmt, res);\
        }\
        printf("\n");\
        size_t last = ((deda).begin + (deda).count - 1) % (deda).capacity;\
        printf("[");\
        for (size_t i = 0; i < (deda).capacity; i++) {\
            if (\
                   ((last >= (deda).begin) && ((i >= (deda).begin) && (i <= last)))\
                || ((last <  (deda).begin) && ((i >= (deda).begin) || (i <= last)))\
            ) {\
                printf(fmt, (deda).data[i]);\
            }\
            else {\
                printf(" ");\
            }\
        }\
        printf("]");\
        printf("\n");\
        printf("[");\
        for (size_t i = 0; i < (deda).capacity; i++) {\
            if (i == (deda).begin) {\
                printf("^");\
            }\
            else if (i == last) {\
                printf("$");\
            }\
            else {\
                printf(" ");\
            }\
        }\
        printf("]");\
        printf("\n");\
    }\
}\

#endif // DEDA_IMPLEMENTATION

#endif // DEDA_H
