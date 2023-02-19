
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/** Error code used for when an overflow or underflow occurs */
#define ERR_OVERFLOW 0x01
/** Error code used for an attempted division by zero */
#define ERR_DIVIDE_BY_ZERO 0x20
/** Error code used for when a negative exponent is passed */
#define ERR_NEGATIVE_EXPONENT 0x21

long plus_ints(long a, long b) {
    long res = a + b;               // compute the sum of the two integer arguments

    bool both_pos = a > 0 && b > 0; // check to see if both numbers are positive
    bool both_neg = a < 0 && b < 0; // check to see if both numbers are negative

    // if both numbers are positive, and produce a negative result, an overflow has occured
    if (both_pos && res < 0)
        exit(ERR_OVERFLOW);
    // if both numbers are negative, and produce a positive result, an overflow has occured
    if (both_neg && res > 0)
        exit(ERR_OVERFLOW);
    
    return res; // return the sum of the two integers
}

long minus_ints(long a, long b) {
    long res = a - b;               // compute the difference of the two integer arguments

    bool both_pos = a > 0 && b > 0; // check to see if both numbers are positive
    bool both_neg = a < 0 && b < 0; // check to see if both numbers are negative

    // if both numbers are positive, and produce a positive result, an overflow has occured
    if (both_pos && res > 0)
        exit(ERR_OVERFLOW);
    // if both numbers are negative, and produce a negative result, an overflow has occured
    if (both_neg && res < 0)
        exit(ERR_OVERFLOW);
    
    return res; // return the difference of the two integers
}

long times_ints(long a, long b) {
    long res = a * b;                       // compute the product of the two integer arguments
    bool either_zero = a == 0 || b == 0;    // check to see if either factor is zero
    
    // if the result divided by one factor does not equal the other factor, an overflow has occured
    if (!either_zero && a != res / b)
        exit(ERR_OVERFLOW);

    return res; // return the product of the two integers
}

long divide_ints(long a, long b) {
    // division by zero prohibited
    if (b == 0)
        exit(ERR_DIVIDE_BY_ZERO);
    
    long res = a / b;   // compute the quotient of the two integer elements

    // if the result multiplied by one factor does not equal the other factor, an overflow has occured
    if (a != 0 && a != res * b)
        exit(ERR_OVERFLOW);

    return res; // return the quotient of the two integers
}

long exponent_ints(long a, long b) {
    // negative exponents prohibited
    if (b < 0)
        exit(ERR_NEGATIVE_EXPONENT);
    
    long res = 1;                   // initialize the value to be multiplied repeatedly
    for (long i = 0; i < b; i++)    // multiply the value by the base factor the times of the power value
        res = times_ints(res, a);   // utilize the overflow checks in the multiplication function

    return res; // return the exponentiation of the two integers
}
