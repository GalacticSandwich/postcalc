/**
    @file pcalc-io.c
    @author GalacticSandwich
    
    This file provides special functions needed to handle custom input/output functionality from a specified
    stream, in the main program this is stdin by default, but can be directed towards a file input of some
    kind.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_whitespace(int ch) {
    // check to see if the character passed is a specified whitespace character
    // the newline character "\n" is used to separate sets of operations, so it is not taken into account
    switch (ch) {
        case ' ':   // space
        case '\t':  // horizontal tab
        case '\v':  // vertical tab
        case '\r':  // carriage return
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
