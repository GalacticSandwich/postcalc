/**
    @file pcalc-opers.h
    @author GalacticSandwich

    This header declares the functions needed to perform all supported mathematical operations, along
    with checking for any overflow associated with each one.
*/





// // // PLAIN ARITHMETIC FUNCTIONS // // //





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





// // // BITWISE ARITHMETIC FUNCTIONS // // //





/**
    Performs a left bitshift on a long signed integer, using another long signed integer as a shift factor.
    If the shift factor is negative, the program exits with code 0x22 (ERR_NEGATIVE_BITSHIFT).

    @param a the number to shift
    @param b the factor to shift by
    @return the number shifted to the left by the bit-factor
*/
long shift_left_longs(long a, long b);

/**
    Performs a right bitshift on a long signed integer, using another long signed integer as a shift factor.
    If the shift factor is negative, the program exits with code 0x22 (ERR_NEGATIVE_BITSHIFT).

    @param a the number to shift
    @param b the factor to shift by
    @return the number shifted to the right by the bit-factor
*/
long shift_right_longs(long a, long b);

/**
    Flips the bits of a long signed integer.

    @param n the number to flip
    @return the number with all its bits flipped
*/
long not_long(long n);

/**
    Performs a bitwise and operation on two long signed integers, where the bits of both numbers are compared
    and zeroes are preserved in the result.

    @param a the first number to compare
    @param b the second number to compare
    @return the bitwise-and of both numbers
*/
long and_longs(long a, long b);

/**
    Performs a bitwise or operation on two long signed integers, where the bits of both numbers are compared
    and ones are preserved in the result.

    @param a the first number to compare
    @param b the second number to compare
    @return the bitwise-or of both numbers
*/
long or_longs(long a, long b);

/**
    Performs a bitwise exclusive-or operation on two long signed integers, where the bits of both numbers 
    are compared and ones in different digits, along with zeroes and ones in the same digit, are preserved 
    in the result.

    @param a the first number to compare
    @param b the second number to compare
    @return the bitwise-exclusive-or of both numbers
*/
long eor_longs(long a, long b);