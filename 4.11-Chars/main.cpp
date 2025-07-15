// To this point, the fundamental data types we've looked at have been used to hold numbers (integers and floating points) or true/false values (Booleans). But what if we want to store letters or punctuation?
// The char data type was designed to hold a single character. A character can be single letter, number, symbol, or whitespace.
// The char data type is an integral type, meaning the underlying value is stored as an integer. Similar to how a Boolean value 0 is interpreted as false and non-zero is interpreted as true, the integer stored by a char variable are interpreted as an ASCII character.
// ASCII stands for American Standard Code for Information Interchange, and it defines a particular way to represent English characters (plus a few other symbols) as numbers between 0 and 127 (called an ASCII code or code point). For example, ASCII code 97 is interpreted as the character 'a'.
// Character literals are always placed between single quotes (e.g. 'g', '1', '').
// Code 0-31 and 127 are called the unprintable chars. These codes were designed to control peripheral devices such as printers (e.g. by instructing the printer how to move the print head). Most of these are obsolete now. If you try to print these chars, the results are dependent upon your OS (you may get some emoji-like characters).
// Code 32-126 are called the printable characters, and they represent the letters, number characters, and punctuation that most computers use to display basic English text.
// If you try to print a character whose value is outside the range of ASCII, the results are also dependent upon your OS.
/*------------------------------------------*/
// INITIALIZING CHARS
// You can initialize char variables using character literals.
// You can initialize chars with integers as well, but this should be avoided if possible
// Be careful not to mix up character numbers with integer numbers. 
#if 0
char ch1 { 5 } // Initialize with integer 5 (stored as integer 5)
char ch2 { '5' } // Initialize with code point for '5' (stored as integer 53)
#endif
// Character numbers are intended to be used when we want to represent numbers as text, rather than as numbers to apply mathematical operations to.
/*------------------------------------------*/
// PRINTING CHARS
// When using std::cout to print a char, std::cout outputs the char variable as an ASCII character
#if 0
#include <iostream>
int main()
{
    char ch1 { 'a' }; // preferred
    std::cout << ch1 << '\n';

    char ch2 { 98 }; // not preferred (98 is the code point for 'b')
    std::cout << ch2 << '\n';

    return 0;
}
#endif
// This produces the result: 
/*
a
b
*/
// We can also output char literals directly.
/*------------------------------------------*/
// INPUTTING CHARS
// Note that std::cin will let you enter multiple characters. However, variable ch can only hold 1 character. Consequently, only the first input character is extracted into variable ch. The rest of the user input is left in the input buffer that std::cin uses, and can be extracted with subsequent calls to std::cin.
// If you want to read in more than one char at a time (e.g. to read in a name, word, or sentence), you will want to use a string instead of a char. A string is a collection of sequential characters (and thus, a string can hold multiple symbols).
/*------------------------------------------*/
// EXTRACTING WHITESPACE CHARACTERS
// Because extracting input ignores leading whitespace, this can lead to unexpected results when trying to extract whitespace characters to a char variable.
// One simple way to address this is to use the std::cin.get() function to perform the extraction instead, as this function does not ignore leading whitespace.
/*------------------------------------------*/
// CHAR SIZE, RANGE, AND DEFAULT SIGN
// Char is defined by C++ to always be 1 byte in size. By default, a char may be signed or unsigned (though it's usually signed). If you're using chars to hold ASCII characters, you don't need to specify a sign (since both signed and unsigned chars can hold values between 0 and 127).
// If you are using a char to hold small integers (something you should not do unless you're explicitly optimizing for space), you should always specify whether it is signed or unsigned. A signed char can hold a number between -128 and 127. An unsigned char can hold a number between 0 and 255.
/*------------------------------------------*/
// ESCAPE SEQUENCES
// There are some sequences of characters in C++ that have special meaning. These characters are called escape sequences. An escape sequence starts with a '\' (backslash) character, and then a following letter or number.
// You have already seen the most common escape sequence '\n', which can be used to print a newline.
// Another commonly used escape sequence is '\t', which embeds a horizontal tab.
// Here's a table of all the escape sequences:
/*
    Alert
        \a
        Makes an alert, such as a beep
    Backspace
        \b
        Moves the cursor back one space
    Formfeed
        \f 
        Moves the cursor to next logical page
    Newline
        \n
        Moves the cursor to the next line
    Carriage return
        \r
        Moves the cursor to beginning of line
    Horizontal tab
        \t
        Prints a horizontal tab
    Vertical tab
        \v
        Prints a vertical tab
    Single quote
        \'
        Prints a single quote
    Double quote
        \"
        Prints a double quote
    Backslash
        \\
        Prints a backslash
    Question mark
        \?
        Prints a question mark
    Octal number
        \(number)
        Translates into char represented by octal
    Hex number
        \x(number)
        Translate into char represented by hex number
*/
// Escape sequences start with a backslash (\), not a forward slash (/). If you use a forward slash by accident, it may still compile, but will not yield the desired result.
/*------------------------------------------*/
// WHAT'S THE DIFFERENT BETWEEN PUTTING SYMBOLS IN SINGLE AND DOUBLE QUOTES?
// Text between single quotes is treated as a char literal, which represents a single character. For example, 'a' represents the character a, '+' represents the character for the plus symbol, '5' represents the character 5 (not the number 5), and '\n' represents the newline character.
// Text between double quotes (e.g. "Hello, world!") is treated as a C-style string literal, which can contain multiple characters.
// Best practice: Single characters should usually be single-quoted, not double-quoted. One possible exception occurs when doing output, where it can be preferential to double quote everything for consistency.
/*------------------------------------------*/
// AVOID MULTICHARACTER LITERALS
// For backwards compatibility reason, many C++ compilers support multicharacter literals, which are char literals that contain multiple characters. If supported, these have an implementation-defined value (meaning it varies depending on the compiler). Because they are not part of the C++ standard, and their value is not strictly defined, multicharacter literals should be avoided.
// Best practice: Avoid multicharacter literals
// Multicharacter literal support often causes problems for new programmers when the forget whether escape sequences use forward slashes or backslashes.
// Using double quotes when outputting character literals (instead of single quotes) either makes these kind of issues easier to discover or avoids them entirely.
/*------------------------------------------*/
// WHAT ABOUT THE OTHER CHAR TYPES, wchar_t, char8_t, char16_t, and char32_t?
// Much like ASCII maps the integers 0-127 to American English characters, other character encoding standards exist to map integers (of varying sizes) to characters in other languages. The most well-known mapping outside of ASCII is the Unicode standard, which maps over 144,000 integers to characters in many different languages. Because Unicode contains so many code points, a single Unicode code point need 32-bits to represent a character (called UTF-32). However, Unicode characters can also be encoded using multiple 16-bit or 8-bit characters (called UTF-16 and UTF8 respectively).
// char16_t and char32_t were added to C++11 to provide explicit support for 16-bit and 32-bit Unicode characters. These char types have the same size as std::uint_least16-t and std::uint_least32_t respectively (but are distinct types). char8_t was added in C++20 to provide support for 8-bit Unicode (UTF-8). It is a distinct type that uses the same representation as unsigned char.
// You won't need to use char8_t, char16_t, or char32_t unless you're planning on making your program Unicode compatible. wchar_t should be avoided in almost all cases (except when interfacing with the Windows API), as its size is implementation-defined.
// Unicode and localization are generally outside the scope of these tutorials, so we won't cover it further. In the meantime, you should only use ASCII characters when working with characters (and strings). Using characters from other character sets may cause your characters to display incorrectly.