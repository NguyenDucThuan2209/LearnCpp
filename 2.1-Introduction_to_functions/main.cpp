/*
------------------------------------------
+ In the last chapter, we defined a function as a collection of statements that execute sequentially. While that is certainly true, that definition doesn't provide much insight into why functions are useful. Let's update our definition: A function is a reusable sequence of statements designed to do a particular job.
+ You already know that every executable program must have a function named main() (which is where the program starts execution when it is run). However, as programs start to get longer and longer, putting all the code inside the main() function becomes increasingly hard to manage. Functions provide a way for us to split our programs into small, modular chunks that are easier to organize, test, and use. Most programs use many functions. The C++ standard library comes with plenty of already-written functions for you to use -- however, it's just as common to write your own. Functions that you write yourself are called user-defined functions.
+ Consider a case that might occur in real life: you're reading a book, when you remember you need to make a phone call. You put a book mark in your book, make the phone call, and when you are done with the phone call, you return to the place you bookmarked and continue your book precisely where you left off.
+ C++ programs can work the same way (and borrow some of the same nomenclature). A program will be executing statements sequentially inside one function when it encounters a function call. A function call tells the CPU to interrupt the current function and execute another function. The CPU essentially "puts a bookmark" at the current point of execution, executes the function named in the function call, and then returns to the point it bookmarked and resumes execution.
+ The function initiating the function call is the called, and the function being called (executed) is the callee. A function call is also sometimes called an invocation, with the caller invoking the callee.
------------------------------------------
AN EXAMPLE OF A USER-DEFINED FUNCTION
+ First, let's start with the most basic syntax to define a user-defined function. For the next lessons, all user-defined functions will take the following form:
    returnType functionName()
    {
        // This is the function body (tells the compiler what the function does)
    }
    → The first line is informally called the function header, and it tells the compiler about the existence of a function, the function's name, and some other information that we'll cover in future lessons (like the return type).
    → In this lesson, we'll use a returnType of int (for the function main()) or void (otherwise).
    → Just like variables have names, so do user-defined functions. The functionName is the identifier of your user-defined function.
    → The parentheses after the identifier tell the compiler that we're defining a function.
+ The curly braces and statements in-between are called the function body. This is where the statements that determine what your function does will go.
+ To call a function, we use the function's name followed by a set of parentheses (e.g. functionName() calls the function whose name is functionName). Conventionally, the       parenthesis are placed adjacent to the function name (with no whitespace between them).
+ When calling a function, don't forget the parentheses () after the function's name. If you forget the parentheses, your program may not compile (and if it does, the function will not be called).
------------------------------------------
CALLING FUNCTIONS MORE THAN ONCE
+ One useful thing about functions is that they can be called more than once.
------------------------------------------
FUNCTIONS CAN CALL FUNCTIONS THAT CALL OTHER FUNCTIONS
------------------------------------------
NESTED FUNCTIONS ARE NOT SUPPORTED
+ A function whose definition is placed inside another function is a nested function. Unlike some other programming languages, in C++, functions cannot be nested.
------------------------------------------
QUIZ TIME
+ Question 1: In a function definition, what are the curly braces and statements in-between called?
    → The function body
+ Question 2: What does the following program print?
    void doB()
    {
        std::cout << "In doB()\n";
    }
    void doA()
    {
        std::cout << "In doA()\n";
        doB();
    }
    int main()
    {
        std::cout << "Starting main()\n";

        doA();
        doB();

        std::cout << "Ending main()\n";

        return 0;
    }

    → Starting main()\nIn doA()\nIn doB()\nIn doB()\nEnding main()\n
*/