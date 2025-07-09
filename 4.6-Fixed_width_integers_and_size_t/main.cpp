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
    std::int8_t    1 byte signed    -128 to 127
    std::uint8_t   1 byte unsigned  0 to 255
    std::int16_t   2 byte signed    -32,768 to 32,767
    std::uint16_t  2 byte unsigned  0 to 65,535
    std::int32_t   4 byte signed    -2,147,483,648 to 2,147,483,647
    std::uint32_t  4 byte unsigned  0 to 4,294,967,295
    std::int64_t   8 byte signed    -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    std::uint64_t  8 byte unsigned  0 to 18,446,744,073,709,551,615
*/
// Best practice: Use a fixed-width integer type when you need an integral type that has a guaranteed range.
/*------------------------------------------*/
// WARNING: std::int8_t and std::uint8_t typically behave like chars
// Due to an oversight in the C++ specification, modern compilers typically treat std::int8_t and std::uint8_t (and the corresponding fast and least fixed-width types, which we will introduce in a moment) the same as signed char and unsigned char respectively. Thus on most modern systems, the 8-bit fixed-width integral types will behave like char types.
// The 8-bit fixed-width integer types are often treated like char instead of integer values (and this may vary per system). The 16-bit and wider integral types are not subject to this issue.
// The fixed-width integers actually don't define new types -- they are just aliases for existing integral types with the desired size. For each fixed-width type, the implementation (the compiler and standard library) gets to determine which existing type is aliased. As an example, on a platform where int is 32-bits, std::int32_t will be an alias for int. On a system where int is 16-bits (and long is 32-bits), std::int32_t will be an alias for long instead.
// So what about the 8-bit fixed-width types?
// In most cases, std::int8_t is an alias for signed char because it is the only available 8-bit signed integral type (bool and char are not considered to be signed integral types). And when this is the case, std::int8_t will behave just like a char on that platform.
// However, in rare cases, if a platform has an implementation-specific 8-bit signed integral type, the implementation may decide to make std::int8_t an alias for that type instead. In that case, std::int8_t will behave like that type, which may be more like an int than a char. 
// std::uint8_t behaves similarly.
/*------------------------------------------*/
// OTHER FIXED-WIDTH DOWNSIDES
// The fixed-width integers have some potential downsides:
// First, the fixed-width integers are not guaranteed to be defined on all architectures. They only exist on systems where there are fundamental integral types that match their widths and following a certain binary representation. Your program will fail to compile on any such architecture that does not support a fixed-width integer that your program is using. However, given that modern architectures have standardized around 8/16/32/64-bit variables, this is unlikely to be a problem unless your program needs to be portable to some exotic mainframe or embedded architectures.
// Second, if you use a fixed-width integer, it may be slower than a wider type on some architectures. For example, if you need an integer that is guaranteed to be 32-bits, you might decide to use std::int32_t, but your CPU might actually be faster at processing 64-bit integers. However, just because your CPU can process a given type faster doesn't mean your program will be faster overall -- modern programs are often constrained by memory usage rather than CPU, and the larger memory footprint may slow your program more than the faster CPU processing accelerates it. It's hard to know without actually measuring.
// These are just minor quibbles though.
/*------------------------------------------*/
// FAST AND LEAST INTEGRAL TYPES
// To help address the above downsides, C++ also defines two alternative sets of integers that are guaranteed to exist.
// The fast types (std::int_fast#_t and std::uint_fast#_t) provide the fastest signed/unsigned integer type with a width of at least # bits (where # is 8, 16, 32, or 64). For example, std::int_fast32_t will give you the fastest signed integer type that's at least 32-bits. By fastest, we mean the integral type that can be processed most quickly by the CPU.
// The least types (std::int_least#_t and std::uint_least#_t) provide the smallest signed/unsigned integer type with a width of at least # bits (where # is 8, 16, 32, or 64). For example, std::uint_least32_t will give you the smallest unsigned integer type that's at least 32-bits.
// However, these fast and least integers have their own downsides. First, not many programmers actually use them, and a lack of familiarity can lead to errors. Then the fast types can also lead to memory wastage, as their actual size may be significantly larger than indicated by their name.
// Most seriously, because the size of the fast/least integers is implementation-defined, your program may exhibit different behaviors on architectures where they resolve to different sizes.
// Best practice: Avoid the fast and least integral types because they may exhibit different behaviors on architectures where they resolve to different sizes.
/*------------------------------------------*/
// BEST PRACTICES FOR INTEGRAL TYPES
// Given the various pros and cons of the fundamental integral types, the fixed-width integral types, the fast/least integral types, and signed/unsigned challenges, there is little consensus on integral best practices.
// Our stance is that it's better to be correct than fast, and better to fail at compile time than runtime. Therefore, if you need an integral type with a guaranteed range, we recommend avoiding the fast/least types in favor of the fixed-width types. If you later discover the need to support an esoteric platform for which a specific fixed-width integral type won't compile, then you can decide how to migrate your program (and thoroughly retest) at that point.
// Best practice:
/*
    + Prefer int when the size of the integer doesn't matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you're asking the user to enter their age, or counting from 1 to 10, it doesn't matter whether int is 16-bits or 32-bits (the numbers will fit either way). This will cover the vast majority of the cases you're likely to run across.
    + Prefer std::int#_t when storing a quantity that needs a guaranteed range.
    + Prefer std::uint#_t when doing bit manipulation or well-defined wrap-around behavior is required (e.g. for cryptography or random number generation).
Avoid the following when possible:
    + short and long integers (prefer a fixed-width integer type instead).
    + The fast and least integral types (prefer a fixed-width integer type instead).
    + Unsigned types for holding quantities (prefer a signed integer type instead).
    + The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
    + Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc).
*/
/*------------------------------------------*/
// WHAT IS std::size_t?
// std::size_t is an alias for an implementation-defined unsigned integral type. It is used within the standard library to represent the byte-size or length of objects.
// std::size_t is actually a typedef.
// std::size_t is defined in a number of different headers. If you need to use std::size_t, <cstddef> is the best header to include, as it contains the least number of other defined identifiers.
// Best practice: 
/*
    + If you use std::size_t explicitly in your code, #include one of the headers that defines std::size_t (we recommend <cstddef>).
    + Using sizeof  does not require a header (even though it returns a value whose type is std::size_t).
*/
// Much like an integer can vary in size depending on the system, std::size_t also varies in size. std::size_t is guaranteed to be unsigned and at least 16 bits, but on most systems will be equivalent to the address-width of the application. That is, 32-bit applications, std::size_t will typically be a 32-bit unsigned integer, and for a 64-bit application, std::size_t will typically be a 64-bit unsigned integer.
/*------------------------------------------*/
// THE sizeof OPERATOR RETURNS A VALUE OF TYPE std::size_t
/*------------------------------------------*/
// std::size_t imposes an upper limit on the size of an object
// The sizeof operator must be able to return the byte-size of an object as a value of type std::size_t. Therefore, the byte-size of an object can be no larger than the largest value std::size_t can hold.
// The C++20 standard says: "Constructing a type such that the number of bytes in its object representation exceeds the maximum value representable in the type std::size_t is ill-formed."
// If it were possible to create a larger object, sizeof would not be able to return its byte-size, as it would be outside the range that a std::size_t could hold. Thus, creating an object with a size (in bytes) larger than the largest value an object of type std::size_t can hold is invalid (and will cause a compile error).
// The size of std::size_t imposes a strict mathematical upper limit on an object's size. In practice, the largest creatable object may be smaller than this amount. (perhaps significantly so)
// Some compilers limit the largest creatable object to half the maximum value of std::size_t.
// Other factors may also play a role, such as how much contiguous memory your computer has available for allocation.
// When 8-bit and 16-bit applications were the norm, this limit imposed a significant constraint on the size of objects. In the 32-bit and 64-bit era, this is rarely an issue, and therefore not something you generally need to worry about.