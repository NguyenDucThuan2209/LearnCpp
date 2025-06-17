/*
------------------------------------------
RETURN VALUES
+ When you write a user-defined function, you get to determine whether your function will return a value back to the caller or not. To return a value back to the caller, two things are needed.
+ First, your function has to indicate what type of value will be returned. This is done by setting the function's return type, which is the type that is defined before the function's name. In the example above, function getValueFromUser has a return type of void (meaning no value will be returned to the caller), and function main determines what type of value will be returned.
+ Second, inside the function that will return a value, we use a return statement to indicate the specific value being returned to the caller. The return statement consists of the return keyword, followed by an expression (sometimes called the return expression), ending with a semicolon.
+ When the return statement is executed:
    The return expression is evaluated to produce a value.
    The value produced by the return expression is copied back to the caller. This copy is called the return value of the function.
    The function exits, and control returns to the caller.
+ The process of returning a copied value back to the caller is named return by value.
+ The return expression produces the value to be returned. The return value is a copy of that value.
+ A value-returning function will return a value each time it is called.
+ When a called function returns a value, the caller may decide to use that value in an expression or statement (e.g. by using it to initialize a variable, or sending it to std::cout) or ignore it (by doing nothing else). If the caller ignores the return values, it is discarded (nothing is done with it).
------------------------------------------
FIXING OUR CHALLENGE PROGRAM
+ If you need to use the return value of a function call more than once, initialize a variable with the return value, and then use that variable as many times as needed.
------------------------------------------
REVISITING main()
+ You now have the conceptual tools to understand how the main() function actually works. When the program is executed, the operating system makes a function call to main(). Execution then jumps to the top of main(). The statements in main() are executed sequentially. Finally, main() returns an integer value (usually 0), and your program terminates.
+ In C++, there are two special requirements for main():
    main() is required to return an int.
    Explicit function calls to main() are disallowed.
+ C does allow main() to be called explicitly, so some C++ compilers will allow this for compatibility reasons.
+ For now, you should also define your main() function at the bottom of your code file, below other functions, and avoid calling it explicitly.
+ It is a common misconception that main is always the first function that executes.
+ Global variables are initialized prior to the execution of main. If the initializer for such a variable invokes a function, then that function will execute prior to main
------------------------------------------
STATUS CODES
+ You may be wondering why we return 0 from main(), and when we might return something else.
+ The return value from main() is sometimes called a status code (or less commonly, an exit code, or rarely a return code). The status code is used to signal whether your program was successful or not.
+ By convention, a status code of 0 means the program ran normally (meaning the program executed and behaved as expected).
+ Your main function should return the value 0 if the program ran normally
+ A non-zero status code is often used to indicate some kind of failure (and while this works fine on most operating systems, strictly speaking, it's not guaranteed to be portable).
+ The C++ standard only defines the meaning of 3 status codes: 0, EXIT_SUCCESS, EXIT_FAILURE. 0 and EXIT_SUCCESS both mean the program executed successfully. EXIT_FAILURE means the program did not execute successfully.
+ EXIT_SUCCESS and EXIT_FAILURE are preprocessor macros defined in the <cstdlib> header.
+ If you want to maximize portability, you should only use 0 or EXIT_SUCCESS to indicate a successful termination, or EXIT_FAILURE to indicate an unsuccessful termination.
+ As an aside, the status code is passed back to the operating system. The OS will typically make the status code available to whichever program launched the program returning the status code. This provides a crude mechanism for any program launching another program to determine whether the launched program ran successfully or not.
------------------------------------------
A VALUE-RETURNING FUNCTION THAT DOES NOT RETURN A VALUE WILL PRODUCE UNDEFINED BEHAVIOR
+ A function that returns a value is called a value-returning function. A function is value-returning if the return type is anything other than void.
+ A value-returning function must return a value of that type (using a return statement), otherwise undefined behavior will result.
+ In most cases, compilers will detect if you've forgotten to return a value. However, in some complicated cases, the compiler may not be able to properly determine whether your function returns a value or not in all cases, so you should not rely on this.
+ Best practice: Make sure your functions with non-void return types return a value in all cases.
+ Best practice: Failure to return a value from a value-returning function will cause undefined behavior.
------------------------------------------
FUNCTION MAIN WILL IMPLICITLY RETURN 0 IF NO RETURN STATEMENT IS PROVIDED
+ The only exception to rule that a value-returning function must return a value via a return statement is for function main(). The function main() will implicitly return the value 0 if no return statement is provided. That said, it is best practice to explicitly return a value from main, both to show your intent, and for consistency with other functions (which will exhibit undefined behavior if return value is not specified).
------------------------------------------
FUNCTIONS CAN ONLY RETURN A SINGLE VALUE
+ A value-returning function can only return a single value back to the caller each time it is called. 
+ Note that the value provided in a return statement doesn't need to be literal -- it can be the result of any valid expression, including a variable or even a call to another function that returns a value.
+ There are various ways to work around the limitation of functions only being able to return a single value, which we'll cover in future lesson.
------------------------------------------
THE FUNCTION AUTHOR CAN DECIDE WHAT THE RETURN VALUE MEANS
+ The meaning of the value returned by a function is determined by the function's author. Some functions use return values as status codes, to indicate whether they succeeded or failed. Other functions return a calculated or selected value. Other functions return nothing.
------------------------------------------
REUSING FUNCTIONS
+ In program, there is one central tenets of good programming: Don't Repeat Yourself (often abbreviated DRY).
+ Why is repeated code bad? If we wanted to change the text "Enter an integer: " to something else, we'd have to update it in two locations. And what if we wanted to initialize 10 variables instead of 2? That would be a lot of redundant code (making our programs longer and harder to understand), and a lot of room for typos to creep in.
+ This is the essence of modular programming: the ability to write a function, test it, ensure that it works, and then know that we can reuse it as many times as we want and it will continue to work (so long as we don't modify the function -- at which point we'll have to retest it).
+ Best practice: Follow DRY. If you need to do something more than once, consider how to modify your code to remove as much redundancy as possible. Variables can be used to store the results of calculations that need to be used more than once (so we don't have to repeat the calculation). Functions can be used to define a sequence of statements we want to execute more than once. And loops can be used to execute a statement more than once.
+ Best practice: Like all best practices, DRY is meant to be a guideline, not an absolute.
+ The (snarky) opposite of DRY is WET ("Write everything twice").
------------------------------------------
CONCLUSION
+ Return values provide a way for functions to return a single value back to the function's caller.
+ Functions provide a way to minimize redundancy in our programs.
*/