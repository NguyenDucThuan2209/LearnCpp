// CHAPTER REVIEW
// The smallest unit of memory is a binary digit, also called a bit. The smallest unit amount of memory that can be addressed (accessed) directly is a byte. The modern standard is that a byte equals 8 bits.
// A data type tells the compiler how to interpret the contents of memory in some meaningful way.
// C++ comes with support for many fundamental data types, including floating point numbers, integers, boolean, chars, null pointers, and void.
// Void is used to indicate no type. It is primarily used to indicate that a afunction does not return a value,
// Different types take different amounts of memory, and the amount of memory used may vary by machine.
// The sizeof operator can be used to return the size of a type in bytes.
// Signed integers are used for holding positive and negative whole numbers, including 0. The set of values that a specific data type can hold is called its range. When using integers, keep an eye out for overflow and integer division problems. 
// Unsigned integers only hold positive numbers (and 0), and should generally be avoided unless you're doing bit-level manipulation.
// Fixed-width integers are integers with guaranteed sizes, but they may not exist on all architectures. The fast and least integers are the fastest and smallest integers that are at least some size. std::int8_t and std::uint8_t should generally be avoided, as they tend to behave like chars instead of integers.
// size_t is an unsigned integral type that is used to represent the size or length of objects.
// Scientific notation is a shorthand way of writing lengthy numbers. C++ supports scientific notation in conjunction with floating point numbers. The digits in the significand (the part before the e) are called the significant digits.
// Floating point is a set of types designed to hold real numbers (including those with a fractional component). The precision of a number defines how many significant digits it can represent without information loss. A rounding error can occur when too many significant digits are stored in a floating point number that can't hold that much precision. Rounding errors happen all the time, even with simple numbers such as 0.1. Because of this, you shouldn't compare floating point numbers directly.
// The Boolean type is used to store a true or false value.
// If statements allow us to execute one or more lines of code if some condition is true. The conditional expression of an if-statement is interpreted as a boolean value. An else statement can be used to execute a statement when a prior if-statement condition evaluates to false.
// Char is used to store values that are interpreted as an ASCII character. When using chars, be careful not to mix up ASCII code values and numbers. Printing a char as an integer value requires use of static_cast.
// Angled brackets are typically used in C++ to represent something that needs a parameterizable type. This is used with static_cast to determine what data type that the argument should be converted to (e.g. static_cast<int>(x) will return the value of x as an int).
/*------------------------------------------*/
// QUIZ TIME
// Question 1: Pick the appropriate data type for a variable in each of the following situation.
/*
    a. The age of the user (in years).
    → int
    b. Whether the user wants the application to check for updates.
    → bool
    c. pi (3.141592654).
    → double
    d. The number of pages in a textbook.
    → int
    e. The length of a couch in feet, to 2 decimal places.
    → float
    f. How many times you've blinked since you were borne.
    → std::int32_t
    g. A user selecting an option from a menu by letter.
    → char (only string if that is "letters" with the 's' at the end)
    h. The year someone was born.
    → std::int16_t
*/
// Question 2: Write a calculator program.