// An integer is an integral type that can represent positive and negative whole numbers, including 0. C++ has 4 primary fundamental integer types available for use:
/*
    short int: 16 bits
    int: 16 bits
    long int: 32 bits
    long long int: 64 bits
*/
// The key different between the various integer types is that they have varying sizes -- the larger integers can hold bigger numbers.
// C++ only guarantees that integers will have a certain minimum size, not that they will have a specific size.
// Technically, the bool and char types are considered to be integral types (because these types store their values as integer values). 
/*------------------------------------------*/
// SIGNED INTEGERS
// When writing negative numbers in everyday life, we use a negative sign. For example, -3 means "negative 3". We'd also typically recognize +3 as "positive 3" (though common convention dictates that we typically omit plus prefixes).
// This attribute of being positive, negative, or zero is called the number's sign.
// By default, integers in C++ are signed, which means the number's sign is stored as part of the value. Therefore, a signed integer can hold both positive and negative numbers (and 0).
// In this lesson, we'll focus on signed integers. We'll discuss unsigned integers in the next lesson.
/*------------------------------------------*/
// DEFINING SIGNED INTEGERS
// Here is the preferred way to define the four types of signed integers:
#if 0
short s;
int i;
long l;
long long ll;
#endif
// Although short int, long int, or long long int will work, we prefer the short names for these types (that do not use the int suffix). In addition to being more typing, adding the int suffix makes the type harder to distinguish from variables of type int. This can lead to mistakes if the short or long modifier is inadvertently missed.
// The integer types can also take an optional signed keyword, which by convention is typically placed before the type name:
#if 0
signed short s;
signed int i;
signed long l;
signed long long ll;
#endif

// However, this keyword should not be used, as it is redundant, since integers are signed by default.
// Prefer the shorthand types that do not use the int suffix or signed prefix.
/*------------------------------------------*/
// SIGNED INTEGER RANGES
// As you learned in the last section, a variable with n bits can hold 2^n possible values. But which specific values? We call the set of specific values that a data type can hold its range. The range of an integer variable is determined by two factors: its size (in bits), and whether it is signed or not.
// For example, an 8-bit signed integer has a range of -128 to 127. This means an 8-bit signed integer can store any integer value between -128 and 127 (inclusive) safely.
// Here is the range of signed integers of different sizes:
/*
    8-bit signed    -128 to 127
    16-bit signed   -32,768 to 32,767
    32-bit signed   -2,147,483,648 to 2,147,483,647
    64-bit signed   -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
*/
// For the math inclined, an n-bit signed variable has a range of -[2^(n-1)] to [2^(n-1)] - 1. For the non-math inclined, use the table.
// The above ranges assume "two's complement" binary representation. This representation is the de-facto standard for modern architectures (as it is easier to implement in hardware), and is now required by the C++20 standard.
// In prior standards, sign-magnitude and ones complement representations were permitted for historical reasons. Such representation produce values int the range -[2^(n-1)] to [2^(n-1)] - 1.
/*------------------------------------------*/
// OVERFLOW
// What happens if we try to assign the value 140 to an 8-bit signed integer? This number is outside the range that an 8-bit signed integer can hold. The number 140 requires 9 bits to represent (8 magnitude bits and 1 sign bit), but we only have 8 bits (7 magnitude bits and 1 sign bit) available in an 8-bit signed integer.
// The C++20 standard makes this blanket statement: "If during the evaluation of an expression, the result is not mathematically define or not in the range of representable values for its type, the behavior is undefined". Colloquially, this is called overflow.
// Therefore, assigning value 140 to an 8-bit signed integer will result in undefined behavior. 
// If an arithmetic operation (such as addition or multiplication) attempts to create a value outside the range that can be represented, this is called integer overflow (or arithmetic overflow). For signed integers, integer overflow will result in undefined behavior.
// In general, overflow results in information being lost, which is almost never desirable. If there is any suspicion that an object might need to store a value that falls outside its range, use a type with a bigger range!
/*------------------------------------------*/
// INTEGER DIVISION
// When doing division with 2 integers (called integer division), C++ always produces an integer result. Since integers can't hold fractional values, any fractional portion is simply dropped (not rounded!).
// Be careful when using integer division, as you will lose any fractional parts of the quotient. However, if it's what you want, integer division is safe to use, as the results are predictable.