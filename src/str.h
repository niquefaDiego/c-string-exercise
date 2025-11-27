#ifndef STR_H
#define STR_H
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
#include <stddef.h>

// Simple growable string type.
// data[length-1] is always 0 to keep compatibility with cstrings.
typedef struct {
    char* data;
    size_t length; // length does not include the 0 terminator
    size_t capacity; // capacity is the number of allocated bytes in data
} str;

// Creates a str from a null-terminated cstring,
// be mindful that we are duplicating the data.
str str_from_cstr(const char* cstr);

// Returns a new str with the concatenation of a and b.
str str_concat(str a, str b);

// Appends c into s, resizing if necessary.
void str_append_char(str *s, char c);

// Appends x into s, resizing if necessary.
void str_append_str(str *s, const str x);

// Splits s into tokens by delimiter, returns number of tokens.
size_t str_split_into_cstrings(const str s, char delimiter, char*** tokens, size_t **token_length);

// Splits s into tokens by delimiter, returns number of tokens.
size_t str_split(const str s, char delimiter, str* tokens);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // STR_H