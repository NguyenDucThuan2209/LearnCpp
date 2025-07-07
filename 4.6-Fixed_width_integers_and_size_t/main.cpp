// In the previous lessons on integers, we covered that C++ only guarantees that integer variables will have a minimum size -- but they could be larger, depending on the target system.
// For example, an int has a minimum size of 16-bits, but it typically 32-bits on modern architectures.
// If you assume an int is 32-bits because that's most likely, then your program will probably misbehave on architectures where int is actually 16-bits (since you will probably be storing values that require 32-bits of storage in variable with only 16-bits of storage, which will cause overflow or undefined behavior).
// Instead, if you assume an int only 16-bits to ensure your program will behave on all architectures, then the range of values you can safely store in an int is significantly limited. And on system where an int is actually 32-bits, you're not making use of half of the memory allocated per int.
// In most cases, we only instantiate a small number of int variables at a time, and these are typically destroyed at the end of the function in which they are created. In such cases, wasting 2 bytes of memory per variable isn't a concern (the limited range is a bigger issue). However, in cases where our program allocates millions of int variables, wasting 2 bytes of memory per variable can have a significant impact on the program's overall memory usage.
/*------------------------------------------*/
// WHY ISN'T THE SIZE OF INTEGER TYPES FIXED?
// The short answer is that this goes back to the early days of C, when computers were slow and performance was of the utmost concern. C opted to intentionally leave the size of an integer open so that the compiler implementers could pick a size for int that performs best on the target computer architecture. That way, programmers could just ue int without having to worry about whether they could be using something more performant.
// By modern standards, the lack of consistent ranges for the various integral types sucks (especially in a language designed to be protable).
/*------------------------------------------*/
// FIXED-WIDTH INTEGERS
// To address the above issues, C++11 provides an alternate set of integer types that are guaranteed to be the same size on any architecture. Because the size of these integers is fixed, they are called fixed-width integers.
// The fixed-width integers are defined (in the <cstdint> header) as follows:
/*

*/
// Best practice: Use a fixed-width integer type when you need an integral type that has a guaranteed range.