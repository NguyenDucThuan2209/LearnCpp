/*------------------------------------------*/
// UNSIGNED INTEGERS
// In the previous lesson 4.4, we covered signed integers, which are a set of types that can hold positive and negative whole number, including 0.
// C++ also support unsigned integers. Unsigned integers are integers that can only hold non-negative whole numbers.
/*------------------------------------------*/
// DEFINING UNSIGNED INTEGERS
// To define an unsigned integer, we use the unsigned keyword. By convention, this is placed before the type:
#if 0
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;
#endif
/*------------------------------------------*/
// UNSIGNED INTEGER RANGE
// A 1-byte unsigned integer has a range of 0 to 255. Compare this to the 1-byte signed integer range of -128 to 127. Both can store 256 different values, but signed integers use half of their range for negative numbers, whereas unsigned integers can store positive numbers that are twice as large.
// Here's a table showing the range for unsigned integers:
/*
    8 bit unsigned  0 to 255
    16 bit unsigned 0 to 65,535
    32 bit unsigned 0 to 4,294,967,295
    64 bit unsigned 0 to 18,446,744,073,709,551,615
*/
// An n-bit unsigned variable has a range of 0 to (2^n) - 1.
// When no negative numbers are required, unsigned integers are well-suited for networking and systems with little memory, because unsigned integers can store more positive numbers without asking up extra memory.
/*------------------------------------------*/
// REMEMBERING THE TERMS SIGNED AND UNSIGNED
// New programmers sometimes get signed and unsigned mixed up. The following is a simple way to remember the different: in order to differentiate negative numbers from positive ones, we use a negative sign. If a sign is not provided, we assume a number is positive. Consequently, an integer with a sign (a signed integer) can tell the difference between positive and negative. An integer without a sign (an unsigned integer) assumes all values are positive.
/*------------------------------------------*/
// UNSIGNED INTEGER OVERFLOW
// What happens if we try to store the number 280 (which requires 9 bits to represent) in a 1-byte (8 bit) unsigned integer? The answer is overflow.
// Oddly, the C++ standard explicitly says "a computation involving unsigned operands can never overflow". This is contrary to general programming consensus that integer overflow encompasses both signed and unsigned use cases. Given that most programmers would consider this overflow, we'll call this overflow despite the C++ standard's statements to the contrary.
// If an unsigned value is out of range, it is divide by one greater than the largest number of the type, and only the remainder kept.
// The number 280 is too big to fit in our 1-byte range of 0 to 255. 1 greater than the largest number of the type is 256. Therefore, we divide 280 by 256, geting 1 and remainder 24. The remainder of 24 is what is stored.
// Here's another way to think about the same thing. Any number is bigger than the largest number representable by the type simply "wraps around" (sometimes called "modulo wrapping"). 255 is in the range of a 1-byte integer, so 255 is fine. 256, however, is outside the range, so it wraps around the value 0. 257 wraps around to the value 1. 280 wraps around to the value 24.
// Many notable bugs in video game history happened due to wrap around behavior with unsigned integers. In the arcade game Donkey Kong, it's not possible to go past level 22 due to an overflow bug that leaves the user with not enough bonus time to complete the level.
// In the PC game Civilization, Gandhi was known for often being the first one to use nuclear weapons, which seems contrary to his expected passive nature. Players had a theory that Gandhi's aggression setting was initially set at 1, but if he chose a democratic government, he'd get a -2 aggression modifier (lowering his current aggression value by 2). This would cause his aggression to overflow to 255, making him maximally aggressive! However, more recently Sid Meier (the game's author) clarified that this wasn't actually the case.
/*------------------------------------------*/
// THE CONTROVERSY OVER UNSIGNED NUMBERS
// Many developers (and some large development houses, such as Google) believe that developers should generally avoid unsigned integers.
// This is largely because of two behaviors that can cause problems.
// First, with signed values, it takes a little work to accidentally overflow the top or bottom of the range because those values are far from 0. With unsigned numbers, it is much easier to overflow the bottom of the range, because the bottom of the range is 0, which is close to where the majority of our values are.
// Favor signed numbers over unsigned numbers for holding quantities (even quantities that should be non-negative) and mathematical operations. Avoid mixing signed and unsigned numbers.
/*------------------------------------------*/
// SO WHEN SHOULD YOU USE UNSIGNED NUMBERS?
// There are still a few cases in C++ where it's okay/necessary to use unsigned numbers. 
// First, unsigned numbers are preferred when dealing with bit manipulation. They are also useful when well-defined wrap-around behavior is required.
// Second, use of unsigned numbers is still unavoidable in some cases, mainly those having to do with array indexing. We'll talk more about this in the lessons on arrays and array indexing.
// Also note that if you're developing for an embedded system or some other processor/memory limited context, use of unsigned numbers is more common and accepted for performance reasons.
