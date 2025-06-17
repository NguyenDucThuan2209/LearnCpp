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
+ 
*/