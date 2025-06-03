/*
------------------------------------------
VARIABLE ASSIGNMENT
+ After a variable has bene defined, you can give it a value (in a separate statement) using the '=' operator. This process is called assignment, and the '=' operator is called the assignment operator.
+ By default, assignment copies the value on the right-hand side of the '=' operator to the variable on the left-hand side of the operator. This is called copy-assignment.
+ Once a variable has been given a value, the value of that variable can be printed via 'std::cout' and the '<<' operator.
+ Assignment can be used whenever we want to change the value held by a variable.
+ One of the most common mistakes that new programmers make is to confuse the assignment operator '=' with the equality operator '=='. Assignment '=' is used to assign a value to a variable. Equality '==' is used to test whether two operands are equal in value.
------------------------------------------
VARIABLE INITIALIZATION
+ One downside of assignment is that assigning a value to a just-defined object requires two statements: one to define the variable, and another to assign the value.
+ These two steps can be combined. When an object is defined, you can optionally provide an initial value for the object. The process of specifying an initial value for an object is called initialization, and the syntax used to initialize an object is called an initializer. Informally, the initial value is often called an "initialize" as well.
------------------------------------------
DIFFERENT FORMS OF INITIALIZATION
+ Unlike assignment (which is generally straightforward), initialization in C++ is surprisingly complex. So we'll present a simplified view here to get started.
+ There are 5 common forms of initialization in C++:
    int a; // default-initialization (no initializer)

    // Traditional initialization forms:
    int b = 5; // copy-initialization (initial value after equals sign)
    int c(6); // direct-initialization (initial value in parenthesis)

    // Modern initialization forms (preferred):
    int d{7}; // direct-list-initialization (initial value in braces)
    int e{}; // value-initialization (empty braces)
+ As of C++17, copy-initialization, direct-initialization, and direct-list-initialization behave identically in most cases. We'll cover the most relevant case where they differ below.
------------------------------------------
DEFAULT-INITIALIZATION
+ When no initializer is provided, this is called default-initialization. In many cases, default-initialization performs no initialization, and leaves the variable with aan indeterminate value (a value that is not predictable, sometimes called a "garbage" value).
------------------------------------------
COPY-INITIALIZATION
+ When an initial value is provided after an equals sign, this is called copy-initialization. This form of initialization was inherited from the C language.
+ Much like copy-assignment, this copies the value on the right-hand side of the equals into the variable being created on the left-hand side.
+ Copy-initialization had fallen out of favor in modern C++ due to being less efficient than other forms of initialization for some complex types. However, C++17 remedied the bulk of these issues, and copy=initialization is now finding new advocates. You will also find it used in older code (especially code ported from C), or by developers who simply think it looks more natural and is easier to read.
+ Copy-initialization is also used whenever values are implicitly copied, such as when passing arguments to a function by value, returning from a function by value, or catching exceptions by value.
------------------------------------------
DIRECT-INITIALIZATION
+ When an initial value is provided inside parenthesis, this is called direct-initialization.
+ Direct-initialization was initially introduced to allow for more efficient initialization of complex objects (those with class types, which we'll cover in a futures chapter). Just like copy-initialization, direct-initialization had fallen out of favor in modern C++, largely due to being superseded by direct-list-initialization. However, direct-list-initialization has a few quirks of its own, and so direct-initialization is once again finding use in certain cases.
+ Direct-initialization is also used when values are explicitly cast to another type.
------------------------------------------
LIST-INITIALIZATION
+ The modern way to initialize objects in C++ is to use a form of initialization that makes use of curly braces. This is calledlist-initialization (or uniform initialization or brace initialization).
+ List-initialization comes in two forms:
    int width { 5 }; // Preferred: direct-list-initialization of initial value 5 into variable width
    int height = { 6 }; // Rarely used: copy-list-initialization of initial value 6 into variable height
+ Prior to C++11, some types of initialization required using copy-initialization, and other types of initialization required using direct-initialization. Copy-initialization can be hard to differentiate from copy-assignment (because both use an '='). And direct-initialization can be difficult to differentiate from function-related operations (because both use parentheses).
+ List-initialization was introduced to provide a initialization syntax that works in almost all cases, behaves consistently, and has an unambiguous syntax that makes it easy to tell where we're initializing an object.
+ When we see curly braces, we know we're list-initializing an object.
+ Additionally, list-initialization also provides a way to initialize objects with a list of values rather than a single value (which is why it is called "list-initialization").
------------------------------------------
LIST-INITIALIZATION DISALLOWS NARROWING CONVERSIONS
+ One of the primary benefits of list-initialization for new C++ programmers is that "narrowing conversions" are disallowed. This means that if you try to list-initialize a variable using a value that the variable can not safely hold, the compiler is required to produce a diagnostic (compilation error or warning) to notify you. For example:
int main()
{
    // An integer can only hold non-fractional values.
    // Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
    // Such a conversion is a narrowing conversion, since the fractional part of the value will be lost.
    
    int w1 { 4.5 }; // compiler error: list-init does not allow narrowing conversion

    int w2 = 4.5; // compiles: w2 copy-initialized to value 4
    int w3 (4.5); // compiles: w3 direct-initialized to value 4

    return 0;
}
+ On line 60 of the above program, we're using a value (4.5) with a fractional component (.5) to list-initialize an integer variable (which can only hold non-fractional values). Because this is a narrowing conversion, the compiler is required to generate a diagnostic in such cases.
+ Copy-initialization (line 62) and direct-initialization (line 63) both silently drop the .5 and initialize the variable with the value 4 (which probably isn't what we want). Your compiler may warn you about this (since losing data is rarely desired), but it also may not.
+ Not that this restriction on narrowing conversions only applies to the list-initialization, not to any subsequent assignments to the variable:
int main()
{
    int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion of 4.5 to 4

    w1 = 4.5 // compiles: copy-assignment allows narrowing conversion of 4.5 to 4

    return 0;
}
------------------------------------------
VALUE-INITIALIZATION AND ZERO-INITIALIZATION
+ When a variable is initialized using an empty set of braces, a special form of list-initialization called value-initialization takes place. In most cases, value-initialization will implicitly initialize the variable to zero (or whatever value is closest to zero for a given type). In cases where zeroing occurs, this is called zero-initialization.
+ For class types, value-initialization (and default-initialization) may instead initialize the object to predefined default values, which may be non-zero.
------------------------------------------
LIST-INITIALIZATION IS THE PREFERRED FORM OF INITIALIZATION IN MODERN C++
+ List-initialization (including value-initialization) is generally preferred over the other initialization forms because it works in most cases (and is therefore most consistent), it disallows narrowing conversions (which we normally don't want), and it supports initialization with a list of values (something we'll cover in a future lesson).
+ Prefer direct-list-initialization or value-initialization to initialize your variables.
+ Use direct-list-initialization when you're actually using thi initial value:
    int x {0}; // direct-list-initialization with initial value 0
    std::cout << x; // we're using that 0 value here
+ use value-initialization when the object's value is temporary and will be replaced:
    int x {}; // value initialization
    std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless
------------------------------------------
INITIALIZE YOUR VARIABLES
+ Initialize your variables upon creation. You may eventually find cases where you want to ignore this advice for a specific reason (e.g. a performance critical section of code that uses a lot of variables), and that's okay, as long as the choice is made deliberately.
+ Best practice: Initialize your variables upon creation.
------------------------------------------
INSTANTIATION
+ The term instantiation is a fancy word that means a variable has been created (allocated) and initialized (this includes default initialization). An instantiated object is sometimes called an instance. Most often, this term is applied to class type objects, but it is occasionally applied to objects of other types as well.
------------------------------------------
INITIALIZING MULTIPLE VARIABLES
+ You can initialize multiple variables defined on the same line:
    int a = 5, b = 6;  // copy-initialization         
    int c(7), d(8);    // direct-initialization 
    int e{9}, f{10};   // direct-list-initialization     
    int i{}, j{};      // value-initialization 
------------------------------------------
UNUSED INITIALIZED VARIABLES WARNINGS
+ Modern compilers will typically generate warnings if a variable is initialized but not used (since this is rarely desirable). And if "treat warnings as errors" is enabled, these warnings will be promoted to errors and cause the compilation to fail.
------------------------------------------
QUIZ TIME
+ Question 1: What is the difference between initialization and assignment?
    → Initialization gives a variable an initial value at the point when it's created. ASsignment gives avariable a value at some point after the variable is created.
+ Question 2: What form of initialization should you prefer when you want to initialize a variable with a specific value?
    → Direct-list-initialization (aka. direct brace initialization).
+ Question 3: What are default-initialization and value-initialization? What is the behavior of each? Which should you prefer?
    → Default-initialization is when a variable initialization has no initializer ('int x;'). In most cases, the variable is left with an indeterminate value.
    → Value-initialization is when a variable initialization has an empty brace initializer ('int x{};'). In most cases, this will perform zero-initialization.
    → You should prefer value-initialization, as it initializes the variable to a consistent value.
*/