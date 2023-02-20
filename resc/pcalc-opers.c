/**
    @file pcalc-opers.c
    @author GalacticSandwich
    
    This file provides the functions needed to perform mathematical operations, along with checking for
    correct mathematical style, and any associated overflow which may occur. There is currently support
    for eleven different numerical operations, 5 for basic arithmetic, and 6 for bitwise arithmetic.
    Error codes used by these functions are specified among the constants below.
*/

#include <stdlib.h>
#include <stdbool.h>

#include "pcalc-err.h"

/** Error code used for when an overflow or underflow occurs */
#define ERR_OVERFLOW 0x01
/** Error code used for an attempted division by zero */
#define ERR_DIVIDE_BY_ZERO 0x20
/** Error code used for when a negative exponent is passed */
#define ERR_NEGATIVE_EXPONENT 0x21
/** Error code used for when a negative bitshift factor is passed */
#define ERR_NEGATIVE_BITSHIFT 0x22





// // // PLAIN ARITHMETIC FUNCTIONS // // //





long negative_long(long n) {
    return ~n + 1;  // return the negative counterpart of the integer
}

long plus_longs(long a, long b) {
    long res = a + b;               // compute the sum of the two integer arguments

    bool both_pos = a > 0 && b > 0; // check to see if both numbers are positive
    bool both_neg = a < 0 && b < 0; // check to see if both numbers are negative

    // if both numbers are positive, and produce a negative result, an overflow has occured
    if (both_pos && res < 0)
        escape(ERR_OVERFLOW);
    // if both numbers are negative, and produce a positive result, an overflow has occured
    if (both_neg && res > 0)
        escape(ERR_OVERFLOW);
    
    return res; // return the sum of the two integers
}

long minus_longs(long a, long b) {
    long res = a - b;               // compute the difference of the two integer arguments

    bool both_pos = a > 0 && b > 0; // check to see if both numbers are positive
    bool both_neg = a < 0 && b < 0; // check to see if both numbers are negative

    // if both numbers are positive, and produce a positive result, an overflow has occured
    if (both_pos && res > 0)
        escape(ERR_OVERFLOW);
    // if both numbers are negative, and produce a negative result, an overflow has occured
    if (both_neg && res < 0)
        escape(ERR_OVERFLOW);
    
    return res; // return the difference of the two integers
}

long times_longs(long a, long b) {
    long res = a * b;                       // compute the product of the two integer arguments
    bool either_zero = a == 0 || b == 0;    // check to see if either factor is zero
    
    // if the result divided by one factor does not equal the other factor, an overflow has occured
    if (!either_zero && a != res / b)
        escape(ERR_OVERFLOW);

    return res; // return the product of the two integers
}

long divide_longs(long a, long b) {
    // division by zero prohibited
    if (b == 0)
        escape(ERR_DIVIDE_BY_ZERO);
    
    long res = a / b;   // compute the quotient of the two integer elements
    long rem = a % b;   // compute the remainder/carry of the two integer elements

    // if the result multiplied by one factor does not equal the other factor, an overflow 
    // has occured
    if (a != 0 && a != ((res * b) + rem))
        escape(ERR_OVERFLOW);

    return res; // return the quotient of the two integers
}

long modulo_longs(long a, long b) {
    // division by zero prohibited
    if (b == 0)
        escape(ERR_DIVIDE_BY_ZERO);

    divide_longs(a, b);  // utilize the division function to check for overflow

    return a % b; // return the remainder/carry of the two integers
}

long exponent_longs(long a, long b) {
    // negative exponents prohibited
    if (b < 0)
        escape(ERR_NEGATIVE_EXPONENT);
    
    long res = 1;                   // initialize the value to be multiplied repeatedly
    for (long i = 0; i < b; i++)    // multiply the value by the base factor the times of the power value
        res = times_longs(res, a);  // utilize the overflow checks in the multiplication function

    return res; // return the exponentiation of the two integers
}





// // // BITWISE ARITHMETIC FUNCTIONS // // //





long shift_left_longs(long a, long b) {
    // negative shift factors prohibited
    if (b < 0)
        escape(ERR_NEGATIVE_BITSHIFT);

    return a << b;  // return the first integer left-shifted the factor of the second integer
}

long shift_right_longs(long a, long b) {
    // negative shift factors prohibited
    if (b < 0)
        escape(ERR_NEGATIVE_BITSHIFT);

    return a >> b;  // return the first integer right-shifted the factor of the second integer
}

long not_long(long n) {
    return ~n;  // return the integer with all bits flipped
}

long and_longs(long a, long b) {
    return a & b;   // return the bitwise-and of the two integers
}

long or_longs(long a, long b) {
    return a | b;   // return the bitwise-or of the two integers
}

long eor_longs(long a, long b) {
    return a ^ b;   // return the bitwise-exclusive-or of the two integers
}
