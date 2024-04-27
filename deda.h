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

#ifdef DEDA_IMPLEMENTATION
#include <stdlib.h>
#include <assert.h>

#define DEDA_INIT_CAP          64
#define DEDA_GROWTH_FACTOR     2.5
#define DEDA_SHRINK_FACTOR     0.5
#define DEDA_SHRINK_THRESHOLD  0.25
#define DEDA_BEGIN_POSN_FACTOR 0.3

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
        new_data[new_begin + i] = (deda)->data[(deda)->begin + i];\
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
    if ((deda)->begin + (deda)->count >= (deda)->capacity) {\
        _deda_grow(deda);\
    }\
    (deda)->data[(deda)->begin + (deda)->count] = (item);\
    (deda)->count += 1;\
}\

#define deda_pop(deda, result) {\
    if ((deda)->count > 0) {\
        (deda)->count -= 1;\
        *(result) = (deda)->data[(deda)->begin + (deda)->count];\
        if ((deda)->count <= (deda)->capacity * DEDA_SHRINK_THRESHOLD) {\
            _deda_shrink(deda);\
        }\
    }\
}\

#define deda_push_front(deda, item) {\
    if ((deda)->begin <= 0) {\
        _deda_grow(deda);\
    }\
    (deda)->begin -= 1;\
    (deda)->data[(deda)->begin] = (item);\
    (deda)->count += 1;\
}\

#define deda_pop_front(deda, result) {\
    if ((deda)->count > 0) {\
        (deda)->count -= 1;\
        *(result) = (deda)->data[(deda)->begin];\
        (deda)->begin += 1;\
        if ((deda)->count <= (deda)->capacity * DEDA_SHRINK_THRESHOLD) {\
            _deda_shrink(deda);\
        }\
    }\
}\

#define deda_get_at(deda, idx, result) {\
    assert((((idx) >= 0) && ((idx) < (deda).count)) && "Index out of bounds!");\
    *(result) = (deda).data[(idx) + (deda).begin];\
}\

#define deda_put_at(deda, idx, item) {\
    assert((((idx) >= 0) && ((idx) < (deda).count)) && "Index out of bounds!");\
    (deda).data[(idx) + (deda).begin] = (item);\
}\

#define _deda_shift_left(deda, idx) {\
    for (size_t j = (deda)->begin; j <= (deda)->begin + (idx); j++) {\
        (deda)->data[j-1] = (deda)->data[j];\
    }\
    (deda)->begin -= 1;\
}\

#define _deda_shift_right(deda, idx) {\
    for (size_t j = (deda)->begin + (deda)->count; j > (deda)->begin + (idx); j--) {\
        (deda)->data[j] = (deda)->data[j-1];\
    }\
}\

#define _deda_make_room(deda, idx) {\
    if ((deda)->count == (deda)->capacity) {\
        _deda_grow(deda);\
    }\
    if ((idx) >= (deda)->count >> 1) {\
        if ((deda)->begin + (deda)->count >= (deda)->capacity) {\
            _deda_shift_left(deda, idx);\
        }\
        else {\
            _deda_shift_right(deda, idx);\
        }\
    }\
    else {\
        if ((deda)->begin <= 0) {\
            _deda_shift_right(deda, idx);\
        }\
        else {\
            _deda_shift_left(deda, idx);\
        }\
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
        (deda)->data[(idx) + (deda)->begin] = (item);\
        (deda)->count += 1;\
    }\
}\

#define _deda_move(deda, start, end, off) {\
    if ((off) > 0) {\
        for (size_t j = end; j >= start; j--) {\
            (deda)->data[j + off] = (deda)->data[j];\
        }\
    }\
    else if ((off) < 0) {\
        for (size_t j = start; j <= end; j++) {\
            (deda)->data[j + off] = (deda)->data[j];\
        }\
    }\
}\

#define deda_delete_at(deda, idx) {\
    assert((((idx) >= 0) && ((idx) < (deda)->count)) && "Index out of bounds!");\
    if ((idx) == 0) {\
        (deda)->begin += 1;\
    }\
    else if ((idx) == (deda)->count - 1) {\
        goto update;\
    }\
    else if ((idx) >= (deda)->count >> 1) {\
        _deda_move(deda, (deda)->begin + (idx) + 1, (deda)->begin + (deda)->count - 1, -1);\
    }\
    else {\
        _deda_move(deda, (deda)->begin, (deda)->begin + (idx) - 1, 1);\
        (deda)->begin += 1;\
    }\
update:\
    (deda)->count -= 1;\
    if ((deda)->count <= (deda)->capacity * DEDA_SHRINK_THRESHOLD) {\
        _deda_shrink(deda);\
    }\
}\

#endif
