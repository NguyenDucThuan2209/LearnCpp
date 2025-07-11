// Integers are great for counting whole numbers, but sometimes we need to store very large (positive or negative) numbers, or numbers with a fractional component. A floating point type variable that can hold a number with a fractional component, such as 4320.0, -3.33 or 0.01226. The floating part of the name floating point refers to the fact that the decimal point can "float" -- that is, it can support a variable number of digits before and after the decimal point. Floating point data types are always signed (can hold positive and negative values).
// When writing floating point numbers in your code, the decimal separator must be a decimal point. If you're from a country that uses a decimal comma, you'll need to get used to using a decimal point instead.
/*------------------------------------------*/
// C++ FLOATING POINT TYPES
// C++ has three fundamental floating point data types: a single-precision float, a double-precision double, and an extended-precision long double. As with integers, C++ does not define the actual size of these types.
// On modern architectures, floating-point types are conventionally implemented using one of the floating-point formats defined in the IEEE 754 standard. As a result, float is almost always 4 bytes and double is almost always 8 bytes.
// On the other hand, long double is a strange type. On different platforms, its size can vary between 8 and 16 bytes, and it may or may not use an IEEE 754 compliant format. We recommend avoiding long double.
// float is almost always implemented using the 4-byte IEEE 754 single-precision format.
// double is almost always implemented using the 8-byte IEEE 754 double-precision format.
// However, the format used to implement long double varies by platform. Common choices include:
/*
    + 8-byte IEEE 754 double-precision format (same as double).
    + 80-bit (often padded to 12 or 16 bytes) x87 extended-precision format (compatible with IEEE 754).
    + 16-byte IEEE 754 quadruple-precision format.
    + 16-byte double-double format (not compatible with IEEE 754).
*/
/*------------------------------------------*/
// FLOATING POINT VARIABLES AND LITERALS
// When using float point literals, always include at least one decimal place (even if the decimal is 0). This helps the compiler understand that the number is a floating point number and not an integer.
// Note that by default, floating point literals default to type double. An f suffix is used to denote a literal of type float.
// Best practice: Always make sure the type of your literals match the type of the variables they're being assigned to or used to initialize. Otherwise an unnecessary conversion will result, possibly with a loss of precision.
/*------------------------------------------*/
// FLOATING POINT RANGE
/*
IEEE 754 single-precision (4 bytes)
    Range: ±1.18x10^-38 to ±3.4x10^38 and 0.0
    Precision: 6-9 significant digits, typically 7
IEEE 754 double-precision (8 bytes)
    Range: ±2.23x10^-308 to ±1.80x10^308 and 0.0
    Precision: 15-18 significant digits, typically 16
IEEE 754 -precision ( bytes)
    Range: ±3.36x10^-4932 to ±1.18x10^4932 and 0.0
    Precision: 18-21 significant digits
IEEE 754 quadruple-precision (16 bytes) 
    Range: ±3.36x10^-4932 to ±1.18x10^4932 and 0.0
    Precision: 33-36 significant digits
*/
// The 80-bit x87 extended-precision floating point type is a bit of a historical anomaly. On modern processors, objects of this type are typically padded to 12 or 16 bytes (which is a more natural size for processors to handle). This means those objects have 80-bits of floating point data, and the remaining memory is filler.
// It may seem a little odd that the 80-bit floating point type has the same range as the 16-byte floating point type. This is because they have the same number of bits dedicated to the exponent -- however, the 16-byte number can store more significant digits.
/*------------------------------------------*/
// FLOATING POINT PRECISION
// Consider the fraction 1/3. The decimal representation of this number is 0.333333... with 3's going out to infinity. If you were writing this number on a piece of paper, your arm would get tired at some point, and you'd eventually stop writing. And the number you were left with would be close to 0.33333333... (with 3's going out to infinity) but not exactly.
// On a computer, an infinite precision number would require infinite memory to store, and we typically only have 4 or 8 bytes per value. This limited memory means floating point numbers can only store a certain number of significant digits -- any additional significant digits are either lost or represented imprecisely. Then number that is actually stored may be close to the desired number, but not exact.
// The precision of a floating point type defines how many significant digits it can represent without information loss.
// The number of digits of precision a floating point type has depends on both the size (floats have less precision than doubles) and the particular value being stored (some values can be represented more precisely than others).
// For example, a float has 6 to 9 digits of precision. This means that a float can exactly represent any number with up to 6 significant digits. A number with 7 to 9 significant digits may or may not be represented exactly depending on the specific value. And a number with more than 9 digits of precision will definitely not be represented exactly.
// Double values have between 15 to 18 digits of precision, with most double values having at least 16 significant digits. Long double has a minimum precision of 15, 18, or 33 significant digits depending on how many bytes it occupies.
// A floating point type can only precisely represent a certain number of significant digits. Using a value with more significant digits than the minimum may result in the value being stored inexactly.
/*------------------------------------------*/
// OUTPUTTING FLOATING POINT VALUES
// When outputting floating point numbers, std::cout has a default precision of 6 -- that is, it assumes all floating point variables are only significant to 6 digits (the minimum precision of a float), and hence it will truncate anything after that.
// The following program shows std::cout truncating to 6 digits:
#if 0
#include <iostream>
int main()
{
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    return 0;
}
#endif
// This program will outputs:
/*
    9.87654
    987.645
    987654
    9.87654e+006
    9.87654e-005 
*/
// Note that each of these only have 6 significant digits.
// Also note that std::cout will switch to outputting numbers in scientific notation in some cases. Depending on the compiler, the exponent will typically be padded to a minimum number of digits. Fear not, 9.87654e+006 is the same as 9.87654e6, just with some padding 0's. The minimum number of exponent digits displayed is compiler-specific.
// We can override the default precision that std::cout shows by using an output manipulator function named std::setprecision(). Output manipulator alter how data is output, and are defined in the iomanip header.
#if 0
#include <iomanip>
#include <iostream>
int main()
{
    std::cout << std::setprecision(9);
    
    // f suffix means float
    std::cout << 3.3333333333333333333333333333333333333f << '\n';
    
    // No suffix means double
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; 

    return 0;
}
#endif
/* Outputs:
    3.3333332538604736
    3.3333333333333335
*/
// Because we set the precision to 17 digits using std::setprecision(), each of the above numbers is printed with 17 digits. But, as you can see, the numbers certainly aren't precise to 17 digits! And because floats are less precise than doubles, the float has more error.
// Output manipulators (and input manipulators) are sticky -- mean if you set them, they will remain set.
// The one exception is std::setw. Some IO operations reset std::setw, so std::setw should be used every time it is needed.
// Precision issues don't just impact fractional numbers, they impact any number with too many significant digits.
#if 0
#include <iomanip>
#include <iostream>
int main()
{
    float f { 123456789.0f };

    std::cout << std::setprecision(9);
    std::cout << f;

    return 0;
}
#endif
// Output: 123456792
// 123456792 is greater than 123456789. The value 123456789.0 has 10 significant digits, but float values typically have 7 digits of precision (and the result of 123456792 is precise only to 7 significant digits). We lost some precision! When precision is lost because a number can't be stored precisely, this is called a arounding error.
// Consequently, one has to be careful when using floating point numbers that require more precision than the variables can hold.
// Best practice: favor double over float unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.
/*------------------------------------------*/
// ROUNDING ERRORS MAKE FLOATING POINT COMPARISONS TRICKY
// Floating point numbers are tricky to work with due to non-obvious differences between binary (how data is stored) and decimal (how we think) numbers. Consider the fraction 1/10. In decimal, this is easily represented as 0.1, and we are used to thinking of 0.1 as an easily representable number with 1 significant digit. However, in binary, decimal value 0.1 is represented by the infinite sequence: 0.0001100110011 ... Because of this, when we assign 0.1 to a floating point number, we'll run into precision problems.
// Rounding errors occur when a number can't be stored precisely. This can happen even with simple numbers, like 0.1. Therefore, rounding errors can, and do, happen all the time. Rounding errors aren't the exception -- they're the norm. Never assume your floating point numbers are exact.
// A corollary of this rule is: be wary of using floating point numbers for financial or currency data.
/*------------------------------------------*/
// Nan AND Inf
// IEEE 754 compatible formats additionally support some special values:
/*
    + Inf, which represents infinity. Inf is signed, and can be positive (+Inf) or negative (-Inf).
    + Nan, which stands for "Not a number". There are several different kinds of NaN.
    + Signed zero, meaning there are separate representations for "positive zero" or "negative zero".
*/
// Formats that are not compatible with IEEE 754 may not support some (or any) of these values. In such case, code that uses or generates these special values will produce implementation-defined behavior.
// Avoid division by 0.0, even if your computer supports it.
/*------------------------------------------*/
// CONCLUSION
// To summarize, the two things you should remember about floating point numbers:
/*
    1. Floating point numbers are useful for storing very large or very small numbers, including those with factional components.
    2. Floating point numbers often have small rounding errors, even when the number has fewer significant digits than the precision. Many times these go unnoticed because they are so small, and because the numbers are truncated for output. However, comparisons of floating point numbers may not give the expected results. Performing mathematical operations on these value will cause the rounding errors to grow larger.
*/