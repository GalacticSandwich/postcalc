/**
    @file pcalc-opers.h
    @author GalacticSandwich

    This header declares the functions needed to perform all supported mathematical operations, along
    with checking for any overflow associated with each one.
*/

/**
    Computes the opposite, or negative, of a positive integer passed.

    @param n the integer to negate
    @return the negative form of the integer
*/
long negative_long(long n);

/**
    Computes the sum of two long signed integers. If an overflow occurs in the addition, the program exits 
    with code 0x01 (ERR_OVERFLOW).

    @param a the first number to add
    @param b the second number to add
    @return the sum of both integers
*/
long plus_longs(long a, long b);

/**
    Computes the difference of two long signed integers. If an overflow occurs in the subtraction, the 
    program exits with code 0x01 (ERR_OVERFLOW).

    @param a the number to subtract from
    @param b the number to subtract with
    @return the difference between both integers
*/
long minus_longs(long a, long b);

/**
    Computes the product of two long signed integers. If an overflow occurs in the multiplication, the 
    program exits with code 0x01 (ERR_OVERFLOW).

    @param a the first number to multiply
    @param b the second number to multiply
    @return the product of both integers
*/
long times_longs(long a, long b);

/**
    Computes the integer quotient of two long signed integers. If an overflow occurs in the division, the
    program exits with code 0x01 (ERR_OVERFLOW), if the divisor is zero, the program exits with code 0x20
    (ERR_DIVIDE_BY_ZERO).

    @param a the number to divide
    @param b the number to divide with
    @return the quotient of both integers
*/
long divide_longs(long a, long b);

/**
    Provides the remainder resulting from the integer division of two long signed integers. If an overflow
    occurs in the division, the program exits with code 0x01 (ERR_OVERFLOW), if the divisor is zero, the
    program exits with code 0x20 (ERR_DIVIDE_BY_ZERO).

    @param a the number to divide
    @param b the number to divide with
    @return the remainder of the first integer divided by the second
*/
long modulo_longs(long a, long b);

/**
    Computes the exponentiation of two long signed integers, the first being the base, and the second
    being the exponent. If an overflow occurs during the exponentiation, the program exits with code
    0x01 (ERR_OVERFLOW). If the exponent value is negative, the program exits with code 0x21
    (ERR_NEGATIVE_EXPONENT).

    @param a the number to multiply
    @param b the exponent to scale with
    @return the first integer raised to the power of the second
*/
long exponent_longs(long a, long b);

