/*
------------------------------------------
FUNCTION PARAMETERS AND ARGUMENTS
+ In many cases, it is useful to be able to pass information to a function being called, so that function has data to work with. For example, if we wanted to write a function to add two numbers, we need some way to tell the function which two numbers to add when we call it. Otherwise, how would the function know what to add? We do that via function parameters and arguments.
+ A function parameter is a variable used in the header of a function. Function parameters work almost identically to variables defined inside the function, but with one different: they are initialized with a value provided by the caller of the function.
+ Function parameters are defined in the function header by placing them in between the parenthesis after the function name, with multiple parameters being separated by commas.
------------------------------------------
HOW PARAMETERS AND ARGUMENTS WORK TOGETHER
+ When a function is called, all of the parameters of the function are created as variables, and the value of each of the arguments is copied into the matching parameter (using copy initialization). This process is called pass by value. Function parameters that utilize pass by value are called value parameters.
+ Note that the number of arguments must generally match the number of function parameters, or the compiler will throw an error. The argument passed to a function can be any valid expression (as the argument is essentially just an initializer for the parameter, and initializers can be any valid expression).
------------------------------------------
USING RETURN VALUES AS ARGUMENTS
------------------------------------------
HOW PARAMETERS AND RETURN ALUES WORK TOGETHER
+ By using both parameters and a return value, we can create functions that take data as input, do some calculation with it, and return the value to the caller.
------------------------------------------
UNREFERENCED PARAMETERS AND UNAMED PARAMETERS
+ In certain cases, you will encounter functions that have parameters that are not used in the body of the function. These are called unreferenced parameters.
+ In a function definition, the name of a function parameter is optional. Therefore, in cases where a function parameter needs to exist but is not used in the body of the function, you can simply omit the name. A parameter without a name is called an unamed parameter.
+ Let's say we have a function with a single parameter. Later, the function is updated in some way, and the value of the parameter is no longer needed. If the now-unused function parameter were simply removed, then every existing call to the function would break (because the function call would be supplying more arguments than the function could accept). This would require us to find every call to the function and remove the unneeded argument. This might be a lot of work (and require a lot of retesting). It also might not even be possible (in cases where we did not control all of the code calling the function). So instead, we might leave the parameter as it is, and just have it do nothing.
+ Operator++ and operator-- have prefix and postfix variants. An unreferenced function parameter is used to differentiate whether an overload of such an operator is for the prefix or postfix case.
+ When we need to determine something from the type (rather than the value)
of a type template parameter.
+ Best practice: When a function parameter exists but is not used in the body of the function, do not give it a name. You can optionally put a name inside a comment.
------------------------------------------
CONCLUSION
+ Function parameters and return values are the key mechanisms by which functions can be written in a reusable way, as it allows us to write functions that can perform tasks and return retrieved or calculated results back to the caller without knowing what the specific inputs or outputs are ahead of time.
------------------------------------------
QUIZ TIME
+ Question 1: Write a function called doubleNumber() that takes one integer parameter. The function should return double the value of the parameter.
    int doubleNumber(int value)
    {
        return value * 2;
    }
+ Question 2: Write a complete program that reads an integer from the user, doubles it using the doubleNumber function you wrote in the previous question, and then prints the doubled value out to the console.
*/

#include <iostream>

int doubleNumber(int value)
{
    return value * 2;
}

int main()
{
    std::cout << "Enter your number: ";

    int num{};
    std::cin >> num;
    std::cout << '\n';

    std::cout << "Doubled value of your number: " << doubleNumber(num) << '\n';

    return 0;
}