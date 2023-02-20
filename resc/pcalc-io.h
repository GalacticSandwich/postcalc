/**
    @file pcalc-io.h
    @author GalacticSandwich

    This header provides the definitions for custom input/output functions, mostly necessary for parsing
    while disregarding whitespace.
*/

#include <stdio.h>
#include <stdbool.h>

/**
    Checks to see if a character is one of a group of specified whitespace characters.

    @param ch the character to check
    @return true if the character is valid whitespace
*/
bool is_whitespace(int ch);

/**
    Fetches the next character from an input stream that is not a whitespace character, i.e., fetches
    a character from input while disregarding whitespace.

    @param stream the input stream to fetch a character from
    @return the character fetched from the input stream
*/
int get_next_char(FILE* stream);