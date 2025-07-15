// Consider a case where you are going to go to the market, and your roommate tells you, "if they have straw berries on sale, buy some". This is a conditional statement, meaning that you will execute some action only if the condition is true.
// Such conditions are common in programming, as they allow us to implement conditional behavior into our programs. The simplest kind of conditional statement in C++ is called an if statement. An if statement allows us to execute one or more lines of code only if some condition is true.
// A condition (also called a conditional expression) is an expression that evaluates to a Boolean value.
// If the condition of an if statement evaluates to Boolean value true, then true_statement is executed. If the condition instead evaluates to Boolean value false, the true_statement is skipped.
/*------------------------------------------*/
// If-else
// We can use an alternative form of the if statement called if-else. 
// If the condition evaluates to Boolean true, true_statement executes. Otherwise false_statement executes.
/*------------------------------------------*/
// CHAINING IF STATEMENTS
// Sometimes we want to check if several things are true or false in sequence. We can do so by chaining an if-statement (or if-else) to a prior if-else.
// Note that you can chain if statements as many times as you ahve conditions you want to evaluate. 
/*------------------------------------------*/
// BOOLEAN RETURN VALUES AND IF STATEMENTS
/*------------------------------------------*/
// NON-BOOLEAN CONDITIONALS
// What happens if your conditional is an expression that does not evaluate to a Boolean value? In such case, the result of the conditional expression is converted to a Boolean value: non-zero values get converted to Boolean true, and zero-values get converted to Boolean false.
// if (x) means "if x is non-zero/non-empty"
/*------------------------------------------*/
// if-STATEMENTS AND EARLY RETURNS
// A return-statement ithat is not the last statement in a function is called an early return. Such a statement will cause the function to return to the caller when the return statement is executed (before the function would otherwise return to the caller, hence, "early").
// Historically, early returns were frowned upon. However, in modern programming they are more accepted, particularly when they can be used to make a function simpler, or are used to abort a function early due to some error condition.