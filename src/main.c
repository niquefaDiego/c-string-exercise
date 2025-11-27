//#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "str.h"

void assert_eq_str(str s, const char* cstr)
{
    printf(" -> Asserting s == \"%s\"\n", cstr);
    size_t len = strlen(cstr);
    assert(s.length == len);
    assert(s.capacity > s.length);
    assert(memcmp(s.data, cstr, len) == 0);
    printf(" -> Assertion passed: \"%s\"\n", cstr);
}

void println_and_flush(const char* msg)
{
    printf("%s\n", msg);
    fflush(stdout);
}

void run_tests()
{
    println_and_flush("Testing str_from_cstr:");
    char* cstr = "Hello, ";
    str s = str_from_cstr(cstr);
    assert_eq_str(s, "Hello, ");

    println_and_flush("Testing str_append_char:");
    str_append_char(&s, 'W');
    assert_eq_str(s, "Hello, W");

    println_and_flush("Testing str_append_str:");
    str_append_str(&s, str_from_cstr("orld!"));
    assert_eq_str(s, "Hello, World!");

    println_and_flush("Testing str_split_into_cstrings:");
    char **tokens;
    size_t *token_length;
    size_t num_tokens = str_split_into_cstrings(s, ' ', &tokens, &token_length);
    assert(num_tokens == 2);
    assert(token_length[0] == 6); // "Hello,"
    assert(token_length[1] == 6); // "World!"
    for (int i = 0; i < num_tokens; i++) {
        printf("tokens[%d] = \"%.*s\"\n", i, token_length[i], tokens[i]);
    }

    println_and_flush("Testing str_split:");
    str* tokens2;
    size_t num_tokens2 = str_split(s, ' ', tokens2);
    assert(num_tokens2 == 2);
    assert_eq_str(tokens2[0], "Hello,");
    assert_eq_str(tokens2[1], "World!");
}

int main()
{
    run_tests();
    return 0;
}