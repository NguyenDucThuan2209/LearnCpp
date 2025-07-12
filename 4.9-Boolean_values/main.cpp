// In real-life, it's common to ask or be asked questions that can be answered with "yes" or "no". 
// Now consider a similar statement that can be answered with a "true" or "false".
// These kinds of sentences that have only 2 possible outcomes: yes/true or no/false are so common, that many programming languages include a special type for dealing with them. That type is called a Boolean type.
/*------------------------------------------*/
// BOOLEAN VARIABLES
// Boolean variables are variables that can have only 2 possible values: true and false.
// To declare a Boolean variable, we use the keyword bool.
// To initialize or assign a true or false value to a Boolean variable, we use the keywords true and false.
// Just as the unary minus operator (-) can be used to make n integer negative, the logical NOT operator (!) can be used to flip a Boolean value from true to false or false to true.
// Boolean values are not actually stored in Boolean variables as the words "true" or "false". Instead, they are stored as integral values: true is stored as integer 1, and false is stored as integer 0. Similarly, when Boolean values are evaluated, they don't actually evaluate to "true" or "false". They evaluate to the integers 0 and 1. Because Booleans store integral values, they are considered to be an integral type.
/*------------------------------------------*/
// PRINTING BOOLEAN VALUES
// When we print Boolean values, std::cout print 0 for false, and 1 for true.
/*------------------------------------------*/
// USE std::boolalpha to print true or false
// If you want std::cout to print true or false instead of 0 or 1, you can output std::boolalpha. This doesn't output anything but manipulates the way std::cout outputs bool values.
// You can use std::noboolalpha to turn it back off.
/*------------------------------------------*/
// INTEGER TO BOOLEAN CONVERSION
// When using uniform initialization, you can initialize a variable using integer literals 0 (for false) and 1 (for true). Other integer literals cause compilation errors.
// However, in any context where an integer can be converted to a Boolean, the integer 0 is converted to false, and any other integer is converted to true.
/*------------------------------------------*/
// INPUTTING BOOLEAN VALUES
// Inputting Boolean values using std::cin sometimes trips new programmers up.
// By default. std::cin only accepts numeric input for Boolean variables: 0 is false, and 1 is true. Any other numeric value will be interpreted as true, and will cause std::cin to enter failure mode. Any non-numeric value will be interpreted as false and will cause std::cin to enter failure mode.
// To allow std::cin to accept the words true and false as inputs, you must first input to std::boolalpha.
// However, when std::boolalpha is enabled for input, numeric values will no longer be accepted (they evaluate to false and cause std::cin to enter failure mode).
// Enabling std::boolalpha for input will only allow lower-cased true or false to be accepted. Variations with capital letters will no be accepted. 0 and 1 will also no long accepted.
// Note that we use std::cin >> boolalpha; to input bool values as true or false, and std::cout << boolalpha; to output bool values as true or false. These are independent controls that can be turned on (using std::boolalpha) or off (using std::noboolalpha) separately.
// Boolean values take a little bit of getting used to, but once you get your mind wrapped around them, they're quite refreshing in their simplicity! Boolean values are also a huge part of the language -- you will end up using them more than all the other fundamental types put together.