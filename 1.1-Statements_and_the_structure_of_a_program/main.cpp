/*
---------------------------------------------------
STATEMENTS
+ A computer program is a sequence of instructions that tell the computer what to do. A statement is a type of instruction that causes the program to perform some action.
+ Statements are by far the most common type of instruction in a C++ program. This is because they are the smallest independent unit of computation in the C++ language. In that regard, they act much like sentences do in natural language. When we want to convey an idea to another person, we typically write or speak in sentences (not in random words or syllables). In C++, when we want to have our program do something, we typically write statements.
+ Most (but not all) statements in C++ end in a semicolon. If you see a line that ends in a semicolon, it's probably a statement.
+ In a high-level language such as C++, a single statement may compile into many machine language instructions. 
+ There are many different kinds of statements in C++:
    Declaration 
    Jump
    Expression
    Compound 
    Selection
    Iteration
    Try blocks
---------------------------------------------------
FUNCTIONs AND THE'main' FUNCTION
+ In C++, statements are typically grouped into units called functions. A function is a collection of statements that get executed sequentially (in order, from top to bottom).
+ Every C++ program must have a special function named 'main' (all lower case letters).
+ When the program is run the statements inside of 'main' are executed in sequential order.
+ Programs typically terminate (finish running) after the last statement inside function 'main' has been executed (though programs may  abort early in some circumstances, or do some cleanup afterwards).
+ Functions are typically written to do a specific job or perform some useful action. For example, a function named 'max' might contain statements that figures out which of two numbers is larger. A function named 'calculateGrade' might calculate a student's grade from a set of test scores. A function named 'printEmployee' might print an employee's information to the console.
+ In programming, the name of a function (or object, type, template, etc...) is called its identifier.

CHARACTERS AND TEXT
+ The earliest computers were designed primarily for mathematical calculations and data processing. As hardware improved, networking became accessible, and consumer software evolved, computers also became valuable tools for written commination.
+ In written language, the most basic unit of communication is the character. To simplify slightly, a character is a written symbol or mark, such as a letter, digit, punctuation mark, or mathematical symbol. When we tap an alphabetic or numeric key on our keyboard, a character is produced as a result, which can then be displayed on the screen.
+ In many cases, such as when writing words or sentences, we want to make use of more than one character. A sequence of characters is called text (also called a string in programming contexts).
---------------------------------------------------
DISSECTING HELLO WORLD!
+ Now that you have a brief understanding of what statements and functions are, let's return to our "Hello world" program and take a high-level look at what each line does in more detail.

#include <iostream>

int main()
{
    std::cout << "Hello world!";
    return 0;
}

+ Line 33 is a special type of line called a preprocessor directive. This '#include' preprocessor directive indicates that we would like to use the contents of the 'iostream' library, which is the part of the C++ standard library that allows us to read and write text from/to the console. We need this line in order to use 'std::cout' on line 37. Excluding this line would result in a compile error on line 37, as the compiler wouldn't otherwise know what 'std::cout' is.
+ Line 34 is blank, and ignored by the compiler. This line exists only to help make the program more readable to humans (by separating the '#include' preprocessor directive and the subsequent parts of the program).
+ Line 35 tells the compiler that we're going to write (define) a function whose name (identifier) is 'main'. As you learned above, every C++ program must have a 'main' function or it will fail to link. This function will produce a value whose type is 'int' (an integer).
+ Line 36 and 39 tell the compiler which lines are part of the 'main' function. Everything between the opening curly brace on line 36 and the closing curly brace on line 39 is considered part of the 'main' function. This is called the function body.
+ Line 37 is the first statement within function 'main', and is the first statement that will execute when we run our program. 'std::cout' (which stands for "character output") and the '<<' operator allow us to display information on the console. In this case, we're displaying the text 'Hello world!'. This statement creates the visible output of the program.
+ Line 38 is a return statement. When an executable program finishes running, the program sends a value back to the operating system in order to indicate whether it ran successfully or not. This particular return statement returns the integer value '0' to the operating system, which means 'everything went okay!'. This is the last statement in the program that executes.
+ All of the programs we write will follow this general template, or a variation on it.
---------------------------------------------------
SYNTAX AND SYNTAX ERRORs
+ In the English language, sentences are constructed according to specific grammatical rules that you probably learned in English class in school. For example, in writing, normal sentences end in a period. This set of rules that describe how specific words (and punctuation) can be arranged to form valid sentences in a language is called syntax.
+ The C++ programming language also has a syntax, which describes how the elements of your program must be written and arranged in order for the program to be considered valid. When you compile your program, the compiler is responsible for making sure your program follows these syntactical rules. If your program does something that deviates from the syntax of the language, the compiler will halt compilation and issue a 'syntax error'.
+ Unlike the English language, which allows for a lot of ambiguity, the syntax rules of C++ are strictly defined and upheld. Syntax errors are common. Fortunately, such errors are typically straightforward to find and fix, as the compiler will generally point you right at them. Compilation of a program will only complete once all syntax errors are resolved.
+ Compilers will sometimes report that an error has occurred on the line after the one where we'd conventionally fix the issue. If you can't find the error on the line indicated, check the prior line.
*/

#include <iostream>

int main()
{
    std::cout << "Hello, World!";
    return 0;
}

/*
QUIZ TIME
+ Question 1: What is a statement?
    → A statement is an instruction in a computer program that tells the computer to perform an action.
+ Question 2: What is a function?
    → A function is a collection of statements that executes sequentially.
+ Question 3: What is the name of the function that all programs must have?
    → main
+ Question 4: What happens when the program is run?
    → The statements inside main() function are executed in sequential order.
+ Question 5: What symbol are statements in C++ often ended with?
    → A semicolon (;)
+ Question 6: What is a syntax error?
    → A syntax error occurs when your program violates the grammar rules of the C++ language.
+ Question 7: What is the C++ Standard Library?
    → A library file is a collection of precompiled code that has been "packaged up" for reuse in other programs. The C++ Standard Library is a library that ships with C++. It contains additional functionality to use in your programs.
*/