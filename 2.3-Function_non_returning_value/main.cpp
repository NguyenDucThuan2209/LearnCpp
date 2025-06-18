/*
------------------------------------------
VOID RETURN VALUES
+ Functions are not required to return a value back to the caller. To tell the compiler that a function does not return a value, a return type of void is used.
+ A function that does not return a value is called a non-value returning function (or a void function).
------------------------------------------
VOID FUNCTIONS DON"T NEED A RETURN STATEMENT
+ A void function will automatically return to the caller at the end of the function. No return statement is required.
+ A return statement (with no return value) can be used in a void function -- such a statement will cause the function to return to the caller at the point where the return statement is executed. This is the same thing that happens at the end of the function anyway. Consequently, putting an empty return statement at the end of a void function is redundant.
+ Best practice: Do not put a return statement at the end of a non-value returning function.
------------------------------------------
VOID FUNCTIONS CAN't BE USED IN EXPRESSION THAT REQUIRE A VALUE
+ Some statements require values to be provided, and others don't.
+ When we have a statement that consists of just a function call, we're calling a function for its behavior, not its return value. In this case, we can call either anon-value returning function, or we can call a value-returning function and just ignore the return value.
+ When we call a function in a context that requires a value, a value must be provided. In such a context, we can only call value-returning functions.
------------------------------------------
RETURNING A VALUE FROM A VOID FUNCTION IS A COMPILE ERROR
+ Try to return a value from a non-value returning function will result in a compilation error.
*/