// IMPLICIT TYPE CONVERSION
#if 0
#include <iostream>
void print(double x)
{
    std::cout << x << '\n';
}
int main()
{
    print(5);
    return 0;
}
#endif
// In the above example, the std::cout function has a parameter of type double but the caller is passing in the value 5 which is of type int. What happens in this case?
// In most cases, C++ will allow us to convert values of one fundamental type to another fundamental type. The process of converting data from one type to another type is called type conversion. Thus, the int argument 5 will be converted to doubler value 5.0 and then copied into parameter x. The print() function will print this value, resulting in the following input: 5
// By default, floating point values whose decimal part is 0 print without the decimal places (e.g. 5.0 prints as 5).
// When the compiler does type conversion on our behalf without us explicitly asking, we call this implicit type conversion. The above example illustrates this -- nowhere do we explicitly tell the compiler to convert integer value 5 to double value 5.0. Rather, the function is expecting a double value, and we pass in an integer argument. The compiler will notice the mismatch and implicitly convert the integer to a double.
/*------------------------------------------*/
// TYPE CONVERSION OF A VALUE PRODUCES A NEW VALUE
// The type conversion process does not modify the value (or object) supplying the data to be converted. Instead, the conversion process uses that data as input, and produces the converted result.
// The type conversion of a value to another type of value behaves much like a call to a function whose return type matches the target type of the conversion. The data to be converted is passed in as an argument, and the converted result is returned (in a temporary object) to be used by the caller.
// Some advanced type conversions (e.g. those involving const_cast or reinterpret_cast) do not return temporary objects, but instead reinterpret the type of an existing value or object.
/*------------------------------------------*/
// IMPLICIT TYPE CONVERSION WARNINGS
// Although implicit type conversion is sufficient for most cases where type conversion is needed, there are a few cases where it is not. Consider the following program, which is similar to the example above:
#if 0
#include <iostream>
void print(int x)
{
    std::cout << x << '\n';
}
int main()
{
    print(5.5);
    return 0;
}
#endif
// In this program, we've changed print() to take an int parameter, and the function call to print() is now passing in double value 5.5. Similar to the above, the compiler will use implicit type conversion in order to convert double value 5.5 into a value of type int, so that it can be passed to function print().
// Unlike the initial example, when this program is compiled, your compiler will generate some kind of a warning about a possible loss of data. And because you have "treat warnings as errors" turned on (you do, right?), your compiler will abort the compilation process.
// You will need to disable "treat warnings as errors" temporarily if you want to compile this example.
// When compiled and run, this program prints the following: 5
// Note that although we passed in value 5.5, the program printed 5. Because integral values can't hold fractions, when double value 5.5 is implicitly converted to an int, the fractional component is dropped, and only the integral value is retained.
// Because converting a floating point value to an integral value results in any fractional component being dropped, the compiler will warn us when it does an implicit type conversion from a floating point to an integral value. This happens even if we were to pass in a floating point value with no fractional component, like 5.0 -- no actual loss of value occurs during the conversion to integral value 5 in this specific case, but the compiler may still warn us that the conversion is unsafe.
// Some type conversions (such as a char to an int) always preserve the value being converted, whereas others (such as double to int) may result in the value being changed during conversion. Unsafe implicit conversions will typically either generate a compiler warning, or (in the case of brace initialization) an error.
// This is one of the primary reasons brace initialization is the preferred initialization form. Brace initialization will ensure we don't try to initialize a variable with an initializer that will lose value when it is implicitly type converted.
#if 0
int main()
{
    double d { 5 }; // Okay: int to double is safe
    int x { 5.5 }; // Error: double to int is not safe

    return 0;
}
#endif
// Implicit type conversion is a meaty topic. We dig into this topic in more depth in future lessons.
/*------------------------------------------*/
// AN INTRODUCTION TO EXPLICIT TYPE CONVERSION VIA THE static_cast OPERATOR
// Back to our most recent print() example, what if we intentionally wanted to pass a double value to a function taking an integer (knowing that the converted value would drop any fractional component?) Turning off "treat warnings as errors" just to make our program compile is a bad idea, because then we will have warnings every time we compile (which we will quickly learn to ignore), and we risk overlooking warnings about more serious issues.
// C++ supports a second method of type conversion, called explicit type conversion. Explicit type conversion allow us (the programmer) to explicitly tell the compiler to convert a value from one type to another type, and that we take full responsibility for the result of that conversion. If such a conversion results in the loss of value, the compiler will not warn us.
// To perform an explicit type conversion, in most cases we will use the static_cast operator. The syntax for the static cast looks a little funny:
/* static_cast<new_type>(expression) */
// static_cast takes the value from an expression as input, and returns that value converted into the type specified by new_type.
// Whenever you see C++ syntax (excluding the preprocessor) that makes use of angled brackets (<>), the thing between the angled brackets will most likely be a type. This is typically how C++ deals with code that need a parameterized type.
// Let's update our prior program using static_cast:
#if 0
#include <iostream>
void print(int x)
{
    std::cout << x << '\n';
}
int main()
{
    print(static_cast<int>(5.5));
    return 0;
}
#endif
// Because we're now explicitly requesting that double value 5.5 to be converted to an int value, the compiler will not generate a warning about a possible loss of data upon compilation (meaning we can leave "treat warnings as error" enabled).
// C++ supports other types of casts. We talk more about the different types of casts in future lessons
/*------------------------------------------*/
// USING static_cast TO CONVERT CHAR TO INT
// It worth nothing that the argument to static_cast evaluates as an expression. When we pass in a variable, that variable is evaluated to produce its value, and that value is then converted to the new type. The variable itself is not affected by casting its value to a new type.
/*------------------------------------------*/
// SIGN CONVERSIONS USING STATIC_CAST
// Signed integral values can be converted to unsigned integral values, and vice-versa, using a static_cast.
// If the value being converted can be represented in the destination type, the converted value will remain unchanged (only the type will change).
// If the value being converted cannot be represented in the destination type:
/*
    If the destination type is unsigned, the value will be modulo wrapped.
    If the destination type is signed, the value is implementation-defined prior to C++20, and will be modulo wrapped as of C++20.
*/