// Void is the easiest of the data types to explain. Basically, void means "no type"!
// Void is our first example of an incomplete type. An incomplete type is a type that has been declared but not yet defined. The compiler knows about the existence of such types, but does not have enough information to determine how much memory to allocate for objects of that type. void is intentionally incomplete since it represents the lack of a type, and thus cannot be defined.
// Void is typically used in several different contexts.
/*------------------------------------------*/
// FUNCTIONS THAT DO NOT RETURN A VALUE
// Most commonly, void is used to indicate that a afunction does not return a value.
// If you use a return statement to try to return a value in such a function, a compile error will result.
/*------------------------------------------*/
// DEPRECATED: FUNCTIONS THAT DO NOT TAKE PARAMETERS
/*------------------------------------------*/
// OTHER USES OF VOID
// The void keyword has a third (more advanced) use in C++. Since we haven't covered what a pointer yet, you don't need to worry about this case for now.