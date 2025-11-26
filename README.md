# Exercise: Growable string in C

## Requirements

- C compiler

## Part 1

Implement the TODO's in `src/src.h`. Then the program and make sure all the assertions pass.

Compilation script:

```bash
gcc src\main.c src\str.c -Isrc -o main
```

## Part 2

Fix all memory leaks in the program.

## Part 3 - For fun

If you want to play around with your `str` function you might find the following method useful:

```C
char *readline()
{
    #define CHUNK_SZ 8
    int capacity = CHUNK_SZ+1;
    int length = 0;
    char *s = malloc(capacity);
    s[0] = 0; // start with empty string
    while (fgets(s+length, CHUNK_SZ+1, stdin))
    {
        for (; length+1 < capacity; length++)
            if (s[length] == '\n') {
                s[length] = 0;
                return s = realloc(s, length);
            }
        capacity += CHUNK_SZ;
        s = realloc(s, capacity);
    }
    #undef CHUNK_SZ
    return s = realloc(s, length);
}
```
