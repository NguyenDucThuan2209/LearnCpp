/*
------------------------------------------
+ Take a look at this seemingly innocent sample program:
#include <iostream>
int main()
{
    std::cout << "The sum of 3 and 4 is: " << and(3, 4) << "\n";
    return 0;
}
int add(int x, int y)
{
    return x + y;
}
(eof)

+ You would expect this program to produce the result:
    The sum of 3 and 4 is: 7
+ But in fact, it doesn't compile at all! The compiler will produces the following compile error:
    add.cpp : error C3861: 'add': identifier not found
+ The reason this program doesn't compile is because the compiler compiles the contents of code files sequentially. When the compiler reaches the function call add() in main, it doesn't know what add is, because we haven't defined add until line 10. That produces the error, identifier not found.
+ This is somewhat misleading, given that add wasn't ever defined in the first place. Despite this, it's useful to generally note that it is fairly common for a single error to produce many redundant or related errors or warnings. It can sometimes be hard to tell whether any error or warning beyond the first is a consequence of the first issue, or whether it is an independent issue that needs to be resolve separately.
+ Best practice: When addressing compilation errors or warnings in your programs, resolve the first issue listed and then compile again.
+ To fix this problem we need to address the fact that the compiler doesn't know what add is. There are two common ways to address the issue.
------------------------------------------
OPTION 1: REORDER THE FUNCTION DEFINITIONS
+ One way to address the issue is to reorder the function definitions so add is defined before main.
+ That way, by the time main calls add, the compiler will already know what add is. Because this is such a simple program, this change is relatively easy to do. However, in a larger program, it can be tedious trying to figure out which functions call which other functions (and in what order) so they can be declared sequentially.
+ Furthermore, this option is not always possible. Let's say we're writting a program that has two functions A and B. If function A calls function B, and function B calls function A, then there's no way to order the function in a way that will make the compiler happy. If you define A first, the compiler will complain it doesn't know what B is. If you define B first, the compiler will complain that it doesn't know what A is.
------------------------------------------
OPTION 2: USE A FORWARD DECLARATION
+ We can also fix this by using a forward declaration.
+ A forward declaration allows us to tell the compiler about the existence of an identifier before actually defining the identifier.
+ In the case of functions, this allows us to tell the compiler about the existence of a function before we define the function's body. This way, when the compiler encounters a call to the function, it'll understand that we're making a function call, and can check to ensure we're calling the function correctly, even if it doesn't yet know how or where the function is defined.
+ To write a forward declaration for a function, we use a function declaration statement (also called a function prototype). The function declaration consists of the function's return type, name, and parameter types, terminated with a semicolon. The names of the parameters can be optionally included. The function body is not included in the declaration.
+ Here is a function declaration for the add function:
    int add(int x, int y);
+ It is worth nothing that function declarations do not need to specify the names of the parameters (as they are not considered to be part of the function declaration). In the above code, you can also forward declare your function like this:
    int add(int, int);
+ However, we prefer to name our parameters (using the same names as the actual function). This allows you to understand what the function parameters are just by looking at the declaration. 
+ Best practice: Keep the parameter names in your function declarations.
+ You can easily create function declarations by copy/pasting your function's header and adding a semicolon.
------------------------------------------
WHY FORWARD DECLARATIONS?
+ You may wondering why we would use a forward declaration if we could just reorder the functions to make our programs work.
+ Most often, forward declarations are used to tell the compiler about the existence of some function that has been defined in a different code file. Reordering isn't possible in this scenario because the caller and the callee are in completely different files. 
+ Forward declarations can also be used to define our functions in an order-agnostic manner. This allows us to define functions in whatever order maximizes organization (e.g. by clustering related functions together) pr reader understanding.
+ Less often, there are times when we have two functions that call each other. Reordering isn't possible in this case either, as there is no way to reorder the functions such that each is before the other. Forward declarations give us a way to resolve such circular dependencies.
------------------------------------------
FORGETTING THE FUNCTION BODY
+ New programmers often wonder what happens if they forward declare a function but do not define it.
+ The answer is: it depends. If a forward declaration is made, but the function is never called, the program will compile and run fine. However, if a forward is made and the function is called, but the program never defines the function, the program will compile okay, but the linker will compile okay, but the linker will complain that it can't resolve the function call.
------------------------------------------
OTHER TYPES OF FORWARD DECLARATIONS
+ Forward declarations are most often used with functions. However, forward declarations can also be used with other identifiers in C++, such as variables and types. Variables and types have a different syntax for forward declaration, so we'll cover these in future lessons.
------------------------------------------
DECLARATIONS VS DEFINITIONS
+ In C++, you'll frequently hear the words "declaration" and "definition" used, and often interchangeably. What do they mean? You now have enough fundamental knowledge to understand the difference between the two.
+ A definition is a declaration that actually implements (for functions and types) or instantiates (for variables) the identifier.
+ In C++, all definitions are declarations. Therefore int x; is both a definition and a declaration.
+ Conversely, not all declarations are definitions. Declarations that aren't  definitions are called pure declarations. Types of pure declarations include forward declarations for function, variables, and types.
+ In common language, the term "declaration" is typically used to mean "a pure declaration", and "definition" is used to mean "a definition that also serves as a declaration". Thus we'd typically call int x; a definition, even though it is both a definition and a declaration.
+ When the compiler encounters an identifier, it will check to ensure use of that identifier is valid (e.g. that the identifier is in scope, that it is used in a syntactically valid manner).
+ In most cases, a declaration is sufficient to allow the compiler to ensure an identifier is being used properly.
+ However, there are a few cases where the compiler must be able to see a full definition in order to use an identifier (such as for template definitions and type definitions, both of which we will discuss in future lessons).
+ Here is a summary scope:
    Declaration
        → Tells compiler about an identifier and its associated type information.
    Definition
        → Implements a function or instantiates a variable. Definitions are also declarations.
    Pure declaration
        → A declaration that isn't a definition.
    Initialization
        → Provides an initial value for a defined object
+ The term "declaration" is commonly used to mean "pure declaration", and the term "definition" used for anything that is both a definition and a declaration.
------------------------------------------
THE ONE DEFINITION RULE (ODR)
+ The one definition rule (or ODR for short) is a well-know rule in C++. The ODR has three parts:
    1. Within a file, each function, variable, type, or template in a given scope can only have one definition. Definitions occurring in different scopes (e.g. local variables defined inside different functions, or functions defined inside different namespaces) do not violate this rule.
    2. Within a program, each function or variable in a given scope can only have one definition. This rule exists because programs can have more than one file.
    3. Types, templates, inline functions, and inline variables are allowed to have duplicate definitions in different files, so long as each definition is identical. We haven't  covered what most of these things are yet, so don't worry about this for now -- we'll bring it back up when it's relevant
+ Violating part 1 of the ODR will cause the compiler to issue a redefinition error. Violating ODR part 2 will cause the linker to issue a redefinition error. Violating ODR part 3 will cause undefined behavior.
+ Functions that share an identifier but have different sets of parameters are also considered to be distinct functions, so such definitions do not violate the ODR.
*/