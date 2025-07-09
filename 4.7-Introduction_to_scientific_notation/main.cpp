// Scientific notation is a useful short hand for writing lengthy numbers in a concise manner. And although scientific notation may seem foreign at first, understanding scientific notation will help you understand how floating point numbers work, and more importantly, what their limitations are.
// Number in scientific notation take the following form: significand*10^exponent. For example, in scientific notation 1.2*10^4, 1.2 is the significand and 4 is the exponent. Since 10^4 evaluates to 10'000, the evaluation of 1.2*10^4 is 12'000.
// By convention, numbers in scientific notation are written with one digit before  the decimal point, and the rest of the digits afterward.
// Scientific notation has the added benefit of making it easier to compare the magnitude of two extremely large or small numbers simply by comparing the exponent.
// Because it can be hard to type or display exponents in C++, we use the letter 'e' (sometimes 'E') to represent the "times 10 to the power of" part of the equation.
/*------------------------------------------*/
// SIGNIFICANT DIGITS
// Let's say you need to know the value of the mathematical constant pi for some equation, but you've forgotten. You ask two people. One tells you the value of pi is 3.14. The other tells you the value fo pi is 3.14159. Both of these values are "correct", but the latter is far more precise.
// Here's the most important thing to understand about scientific notation: The digits in the significand (the part before the 'e') are called the significant digits (or significant figures). The more significant digits, the more precise a number is.
// The more digits in the significand, the more precise a number is.
// In scientific notation, we'd write 3.14 as 3.14e0. Since there are 3 numbers in the significand, this number has 3 significant digits.
/*------------------------------------------*/
// HOW TO CONVERT DECIMAL NUMBERS TO SCIENTIFIC NOTATION
// Use the following procedure:
/*
    + Your exponent starts at zero.
    + If the number has no explicit decimal point (e.g. 123), it is implicitly on the right end (e.g. 123)
    + Slide the decimal point left or right so there is only one non-zero digit to the left of the decimal.
        + Each place you slide the decimal point to the left increases the exponent by 1.
        + Each place you slide the decimal point to the right decreases the exponent by 1.
    + Trim off any leading zeros (on the left end of the significand)
    + Trim off any trailing zeros (on the right end of the significand) only if the original number hand no decimal point. We're assuming they're not significant. If you have additional information to suggest they are significant, you can keep them.
*/
/*------------------------------------------*/
// HANDLING TRAILING ZEROS
// You may occasionally see a number written with an explicit trailing decimal point. This is an indication that the preceding zeros are significant.
// One of the nice things about scientific notation is that it always makes clear how many digits are significant.
