#include "str.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

str str_from_cstr(const char* cstr)
{
    size_t len = strlen(cstr);
    char *data = (char*)malloc(len + 1);
    memcpy(data, cstr, len + 1);
    return (str) {
        .data = data,
        .length = len,
        .capacity = len + 1
    };
}

str str_concat(str a, str b)
{
    // TODO
    return a;
}

void str_append_char(str *s, char c)
{
    // TODO
}

void str_append_str(str *s, const str x)
{
    // TODO
}

size_t str_split_into_cstrings(const str s, char delimiter, char*** tokens, size_t **token_length)
{
    // TODO:
    return 0;
}

size_t str_split(const str s, char delimiter, str* tokens)
{
    // TODO:
    return 0;
}