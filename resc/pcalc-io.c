
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_whitespace(int ch) {
    switch (ch) {
        case ' ':
        case '\t':
        case '\v':
        case '\r':
            return true;
        default:
            return false;
    }
}

int get_next_char(FILE* stream) {
    int ch = fgetc(stream); // fetch a character from the stream passed

    // continue fetching characters until a non-whitespace character is fetched
    while (is_whitespace(ch))
        ch = fgetc(stream);

    return ch;  // return the next non-whitespace character from the stream passed
}