#include "str.h"
#include <stddef.h>
#include <string.h>

str str_from_cstr(char* cstr)
{
    size_t len = strlen(cstr);
    return (str) {
        .data = cstr,
        .length = len,
        .capacity = len + 1
    };
}

str str_concat(str a, str b)
{
    // TODO
    return a;
}

str str_append_char(str s, char c)
{
    // TODO
    return s;
}

str str_append_str(str s, str x)
{
    // TODO
    return s;
}


size_t str_split_into_cstrings(str s, char delimiter, char** tokens, size_t *token_length)
{
    // TODO:
    return 0;
}

size_t str_split(str s, char delimiter, str* tokens)
{
    // TODO:
    return 0;
}