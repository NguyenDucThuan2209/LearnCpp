/*
------------------------------------------
LOCAL VARIABLES 
+ Variables defined inside the body of a function are called local variables (as opposed to global variables, which we'll discuss in a future chapter).
+ Function parameters are also generally considered to be local variables, and we will include them too.
------------------------------------------
LOCAL VARIABLE LIFETIME
+ Function parameters are created and initialized when the function is entered, and variables within the function body are created and initialized at the point of definition.
+ Local variables are destroyed in the opposite order of creation at the end of the set of curly braces in which it is defined (or for a function parameter, at the end of the function).
+ Much like a person's lifetime is defined to be the time between birth and death, an object's lifetime is defined to be the time between its creation and destruction. Note that variable creation and destruction happen when the program is running (called runtime), not at compile time. Therefore, lifetime is a runtime property.
+ The above rules around creation, initialization, and destruction are guarantees. That is, objects must be created and initialized no later than the point of definition, and destroyed no earlier than the end of the set of the curly braces in which they are defined (or, for function parameters, and the end of the function).
+ In actuality, the C++ specification gives compilers a lot of flexibility to determine when local variables are created and destroyed. Objects may be created earlier, or destroyed later for optimization purposes. Most often, local variables are created when the function is entered, and destroyed in the opposite order of creation when the function is exited. We'll discuss this in more detail in a future lesson, when we talk about the call stack.
------------------------------------------
WHAT HAPPENS WHEN AN OBJECT IS DESTROYED?
+ In most cases, nothing. The destroyed object simply becomes invalid.
+ If the object is a class type object, prior to destruction, a special function called a destructor is invoked. In many cases, the destructor does nothing, in which case no cost is incurred.
+ Any use of an object after it has been destroyed will result in undefined behavior.
+ At some point after destruction, the memory used by the object will be deallocated (freed up for reuse).
------------------------------------------
LOCAL SCOPE (BLOCK SCOPE)
+ An identifier's scope determines where the identifier can be seen and used within the source code. When an identifier can be seen and used, we say it is in scope. When an identifier can not be seen, we can not use it, and we say it is out of scope. Scope is a compile-time property, and trying to use an identifier when it is not in scope will result in a compile error.
+ The identifier of a local variable has local scope. An identifier with local scope (technically called block scope) is usable from the point of definition to the end of the innermost pair of curly braces containing the identifier (or for function parameters, at the end of the function). This ensures local variables cannot be used before the point of definition (even if the compiler opts to create them before then) or after they are destroyed. Local variables defined in one function are also not in scope in other functions that are called.
------------------------------------------
"OUT OF SCOPE" VS "GOING OUT OF SCOPE"
+ The terms "out of scope" and "going out of scope" can be confusing to new programmers.
+ An identifier is out of scope anywhere it cannot be accessed within the code. 
+ The term "going out of scope" is typically applied to objects rather than identifiers. We say an object goes out of scope at the end of the scope (the end curly brace) in which the object was instantiated.
+ A local variable's lifetime ends at the point where it goes out of scope, so local variables are destroyed art this point.
+ Note that not all types of variables are destroyed when they go out of scope.
------------------------------------------
FUNCTIONAL SEPARATION
+ Names used for function parameters or variables declared in a function body are only visible within the function that declares them. This means local variables within a function can be named without regard for the names of variables in other functions. This helps keep functions independent.
------------------------------------------
WHERE TO DEFINE LOCAL VARIABLES
+ In modern C++, the best practice is that local variables inside the function body should be fined as close to their first use as reasonable.
+ Best practice: Define your local variables as close to their first use as reasonable.
+ Due to the limitations of older, more primitive compilers, the C language used to require all local variables be defined at the top of the function.
+ This style is suboptimal for several reasons:
    The intended use of these variables isn't apparent at the point of definition. You have to scan through the entire function to determine where and how each variable is used.
    The intended initialization value may not be available at the top of the function.
    There may be many lines between a variable's initializer and its first use. If we don't remember what value it was initialized with, we will have to scroll back to the top of the function, which is distracting.
------------------------------------------
WHEN TO USE FUNCTION PARAMETERS VS LOCAL VARIABLES
+ Because function parameters and local variable can both be used within the body of a function, new programmers sometimes struggle to understand when each should be used. A function parameter should be used when the caller will pass in the initialization value as an argument. A local variable should be used otherwise.
+ Best practice: When a variable is needed within a function:
    Use a function parameter when the caller will pass in the initialization value for the variable as an argument.
    Use a local variable otherwise.
------------------------------------------
INTRODUCTION TO TEMPORARY OBJECTS
+ A temporary object (also sometimes called an anonymous object) is an unnamed object that is used to hol a value that is only needed for a short period of time. Temporary objects are generated by the compiler when they are needed.
+ Return by value returns a temporary object (that holds a copy of the return value) to the caller.
+ Temporary objects have no scope at all (this make sense, since scope is a property of an identifier, and temporary objects have no identifier).
+ Temporary objects are destroyed at the end of the full expression in which they are created. This means temporary objects are always destroyed before the next statement executes.
+ In the case where a temporary object is used to initialize a variable, the initialization happens before the destruction of the temporary.
+ In modern C++, the compiler has many tricks to avoid generating temporaries where previously it would have needed to. For example, when we use a return value to initialize a variable, this would normally result in the creation of a temporary holding the return value, and then using the temporary to initialize the variable. However, in modern C++, the compiler will often skip creating the temporary and just initialize the variable directly with the return value.
------------------------------------------
*/