/*
------------------------------------------
+ Whitespace is a term that refers to characters that are used for formatting purposes. In C++, this refers primarily to spaces, tabs, and newlines. Whitespace in C++ is generally used for 3 things: separating certain language elements, inside text, and for formatting code.
------------------------------------------
SOME LANGUAGE ELEMENTS MUST BE WHITESPACE-SEPARATED
+ The syntax of the language requires that some elements are separated by whitespace. This mostly occurs when 2 keywords or identifiers must be placed consecutively, so the compiler can tell them apart.
+ For example, a variable declaration must be whitespace separated:
    int x;
+ If we typed intx instead, the compiler would interpret this as an identifier, and then complain it doesn't know what identifier intx is.
+ As another example, a function's return type and name must be whitespace separated:
    int main();
+ When whitespace is required as a separator, the compiler doesn't care how much whitespace is used, as long as some exist.
+ The following variable definitions are all valid:
    int x;
    int     y;
        int 
    z;
+ In certain cases, newlines are used as a separator. Single-line comments are terminated by a newline.
+ Preprocessor directives (e.g. #include <iostream>) must be placed on separate lines:
    #include <iostream>
    #include <string>
------------------------------------------
QUOTED TEXT TAKES THE AMOUNT OF WHITESPACE LITERALLY
+ Inside quoted text, the amount of whitespace is taken literally.
+ Newlines are not allowed in quoted text.
+ Quoted text separated by nothing but whitespace (spaces, tabs or newlines) will be concatenated
    // This will print "Hello world!"
    std::cout << "He" "llo "
                "world!";
------------------------------------------
USING WHITESPACE TO FORMAT CODE
+ Whitespace is otherwise generally ignored. This means we can use whitespace wherever we like to format our code in order to make it easier to read.
+ Statements may be split over multiple lines if desired. This can be useful for particularly long statements.
------------------------------------------
BASIC FORMATTING
+ Unlike some other languages, C++ does not enforce any kind of formatting restrictions on the programmer. For this reason, we say that C++ is a whitespace-independent language.
+ This is a mixed blessing. On one hand, it's nice to have the freedom to do whatever you like. On the other hand, many different methods of formatting C++ programs have been developed throughout the years, and you will find (sometimes significant and distracting) disagreement on which ones are best. Our basic rule of thumb is that the best styles are the ones that produce the most readble code, and provide the most consistency.
+ Here are the recommendations for basic formatting:
    1. It's fine to use either tabs or spaces for indentation (most IDEs have a setting where you can convert a tab press into the appropriate number of spaces). Developers who prefer spaces tend to do so because it ensures that code is precisely aligned as intended regardless of which editor or settings are used. Proponents of using tabs wonder why you wouldn't use the character designed to do indentation, especially as you can set the width to whatever your personal preference is. There's no right answer here -- and debating it is like arguing whether cake or pie is better. It ultimately comes dơn to personal preference.
    
*/