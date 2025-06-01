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
*/