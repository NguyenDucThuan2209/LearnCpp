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

*/