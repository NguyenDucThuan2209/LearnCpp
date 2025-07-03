// OBJECT SIZES
// As you learned in the lesson 4.1, memory on modern machines is typically organized into byte-sized units, with each byte of memory having a unique address. Up to this point, it has been useful to think of memory as a bunch of cubbyholes or mailboxes where we can put and retrieve information, and variables as names for accessing those cubbyholes or mailboxes.
// However, this analogy is not quite correct in one regard -- most objects actually take up more than 1 byte of memory. A single object may use 1, 2, 4, 8, or even more consecutive memory addresses. The amount of memory that an object uses is based on its data type.
// Because we typically access memory through variable names (and not directly via memory addresses), the compiler is able to hide the details of how many byte a given object uses from us. When we access some variable x in our source code, the compiler knows how many bytes of data need to be retrieved (based on the type of variable x), and will output the appropriate machine language code to handle that detail for us.
// Even so, there are several reasons it is useful to know how much memory an object uses.
// First, the more memory an object uses, the more information it can hold.
/*
+ A single bit can hold 2 possible values: bit 0
→ 0 | 1

+ Two bits can hold 4 possible value: bit 0 + bit 1
→ 00 | 01 | 10 | 11

+ Three bits can hold 8 possible value: bit 0 + bit 1 + bit 2
→ 000 | 001 | 010 | 011 | 100 | 101| 110 | 111

+ To generalize, an object with n bits (where n is an integer) can hold 2^n (2 to the power of n) unique values. Therefore, with an 8-bit byte, a byte-sized object can hold 2^8 (256) different values. An object that uses 2 bytes can hold 2^16 (65536) different values!

+ Thus, the size of the object puts a limit on the amount of unique values it can store -- objects that utilize more bytes can store a large number of unique values. We will explore this further when we talk more about integers.
*/
// Second, computers have a finite amount of free memory. Every time we define an object, a small portion of that free memory is used for as long as the object is in existence. Because modern computers have a lot of memory, this impact is usually negligible. However, for programs that need a large amount of objects or data (e.g. a game that is rendering millions of polygons), the difference between using 1 byte and 8 byte objects can be significant.
// New programmers often focus too much on optimizing their code to use as little memory as possible. In most cases, this makes a negligible difference. Focus on writing maintainable code, and optimize only when and where the benefit will be substantive.
/*------------------------------------------*/
// FUNDAMENTAL DATA TYPE SIZES
// The obvious next question is "how much memory do objects of a given data type use?". Perhaps surprisingly, the C++ standard does not define the exact size (in bits) of any of the fundamental types.
// Instead, the standard says the following:
/*
    + An object must occupy at least 1 byte (so that each object has a distinct memory address).
    + A byte must be at least 8 bits.
    + The integral types char, short, int, long, and long long have a minimum size of 8, 16, 32, and 64 bits respectively.
    + char and char8_t are exactly 1 byte (at lease 8 bits).
*/
// When we talk about the size of a type, we really mean the size of an instantiated object of that type.
// In this tutorial series, we will present a simplified view, by making some reasonable assumptions that are generally true for modern architectures:
/*
    + A byte is 8 bits.
    + Memory is byte addressable (we can access every byte of memory independently).
    + Floating point support is IEEE-754 compliant.
    + We are on a 32-bit or 64-bit architecture.
*/
// Given the above assumptions, we can reasonably state the following:
/*
Category: [Type | Minimum Size | Typical Size]
------------------------------------------
Boolean: 
    bool | 1 byte | 1 byte
Character: 
    char | 1 byte | 1 byte
    wchar_t | 1 byte | 2 or 4 bytes
    char8_t | 1 byte | 1 byte
    char16_t | 2 bytes | 2 bytes
    char32_t | 4 bytes | 4 bytes
Integral:
    short | 2 bytes | 2 bytes
    int | 2 bytes | 4 bytes
    long | 4 bytes | 4 or 8 bytes
    long long | 8 bytes | 8 bytes
Floating point:
    float | 4 bytes | 4 bytes
    double | 8 bytes | 8 bytes
    long double | 8 bytes | 8, 12, or 16 bytes
Pointer:
    std::nullptr_t | 4 bytes | 4 or 8 bytes
*/
// For maximum portability, you shouldn't assume that objects are larger than the specified minimum size.
// Alternatively, if you want to assume that a type has some non-minimum size (e.g. that an int is at least 4 bytes), you can use static_assert to have the compiler fail a build if it is compiled on an architecture where this assumption is not true. 
/*------------------------------------------*/
// THE sizeof OPERATOR
// In order to determine the size of data types on a particular machine, C++ provides an operator named sizeof. The sizeof operator is a unary operator that takes either a type or a variable, and returns the size of an object of that type (in bytes). You can compile and run the following program to find out how large some of your data types are:
#include <iostream>
#include <climits>

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << "bool: " << sizeof(bool) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "short: " << sizeof(short) << " bytes\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "long: " << sizeof(long) << " bytes\n";
    std::cout << "long long: " << sizeof(long long) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
    std::cout << "long double: " << sizeof(long double) << " bytes\n";

    return 0;
}
// Your results may vary based on compiler, computer architecture, OS, compilation settings, etc
// Trying to use sizeof on an incomplete type (such as void) will result in a compilation error.
// You can also use the sizeof operator on a variable name
// sizeof does not include dynamically memory used by an object. We discuss dynamic memory allocation in a future lesson.
/*------------------------------------------*/
// FUNDAMENTAL DATA TYPE PERFORMANCE
// On modern machines, objects of the fundamental data types are fast, so performance while using or copying these types should generally not be a concern.
// You might assume that types that use less memory would be faster than types that use more memory. This is not always true. CPUs are often optimized to process data of a certin size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, a 32-bit int could be faster than a 16-bit short or an 8-bit char.