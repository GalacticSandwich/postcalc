/**
    @file pcalc-err.c
    @author GalacticSandwich
    
    This file contains functions for dealing with specialized error handling, where in any errors that are
    encountered are delegated to error output (stderr automatically, but can be changed), and the program
    is exited passing whatever exit code is provided.
*/

#include <stdio.h>
#include <stdlib.h>

/** Output stream specified for generating error messages */
#define OUTPUT_ERR stderr

// Error Codes

/** Error code used for when an overflow or underflow occurs */
#define ERR_OVERFLOW 0x01
/** Error code used for an attempted division by zero */
#define ERR_DIVIDE_BY_ZERO 0x20
/** Error code used for when a negative exponent is passed */
#define ERR_NEGATIVE_EXPONENT 0x21
/** Error code used for when a negative bitshift factor is passed */
#define ERR_NEGATIVE_BITSHIFT 0x22

/**
    Helper function, delegates an error output to whatever error stream is specified, and outputs
    the proper error message for whatever exit code has been passed.
    @param code the exit code to generate an error message for
*/
static void error_message(const unsigned code) {
    switch(code) {
        case ERR_OVERFLOW:
            fprintf(OUTPUT_ERR, "[EXIT 0x01] OVERFLOW");
            break;
        case ERR_DIVIDE_BY_ZERO:
            fprintf(OUTPUT_ERR, "[EXIT 0x20] DIVISION BY ZERO ATTEMPTED");
            break;
        case ERR_NEGATIVE_EXPONENT:
            fprintf(OUTPUT_ERR, "[EXIT 0x21] NEGATIVE EXPONENT PASSED");
            break;
        case ERR_NEGATIVE_BITSHIFT:
            fprintf(OUTPUT_ERR, "[EXIT 0x22] NEGATIVE BITSHIFT FACTOR PASSED");
            break;
        default:
            break;
    }
}

void escape(const unsigned code) {
    error_message(code);    // generate the error message associated with the code passed
    exit(code);             // exit the program with the desired exit code
}
