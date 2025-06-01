/*
------------------------------------------
DATA AND VALUES
+ In computing, data is any information that can be moved, processed, or stored by a computer.
+ Programs are collections of instructions that manipulate data to produce a desired result.
+ Computer programs (both in source code format and compiled) are technically data too, since they can be moved, processed, and stored. However, in the context of a computer program, we typically use the term "code" to mean the program itself, and "data" to mean the information that the program works with to produce a result.
+ A program can acquire data to work with in many ways: from a file or database, over a network, from the user providing input on a keyboard, or from the programmer putting data directly into the source code of the program itself. In the "Hello world" program from the aforementioned lesson, the text "Hello world!" was inserted directly into the source code of the program, providing data for the program to use. The program then manipulates this data by sending it to the monitor to be displayed.
+ In programming, a single piece of data is called a value (sometimes called a data value). Common examples of values include: numbers; characters; text.
    Values placed in single-quotes are interpreted by the compiler as character values.
    Values placed in double-quotes are interpreted by the compiler as text values.
    Numeric values are not quoted.
+ Values that are placed directly into the source code are called literals.
+ If a character value or text value is not properly quoted, the compiler will try to interpret that value as if it were C++ code. That will almost always result in a compilation error.
+ Literals are the easiest way to provide values for your program, but they have some shortcomings. Literals are read-only values, so their values can't be modified. Thus, if we want to store data in memory, we need some toher way to do this.
------------------------------------------
RANDOM ACCESS MEMORY
+ The main memory in a computer is called Random Access Memory (often called RAM for short). When we run a program, the operating system loads the program into RAM. Any data that is hardcoded into the program itself (e.g "Hello, world!") is loaded at this point.
+ The operating system also reserves some additional RAM for the program to use while it is running. Common uses for this memory are to store values entered by the user, to store data read in from a file or network, or store values calculated while the program is running so they can be used again later.
+ You can think of RAM as a series of numbered boxes that can be used to store data while the program is running. In some older programming languages (like Applesoft BASIC), you could directly access these boxes (e.g you could write a statement to "go get the value stored in membox number 7532").
------------------------------------------
OBJECTS AND VARIABLES
+ In C++, direct memory access is discouraged. Instead, we access memory indirectly through an object. An object represents a region of storage (typically RAM or a CPU register) that can hold a value. Objects also have associated properties.
+ The key point here is that rather than say "go get the value stored in mailbox number 7532", ew can say, "go get the value stored by this object" and let the compiler figure out where and how to retrieve the value. This means we can focus on using objects to store and retrieve values, and not have to worry about there in memory those objects are actually being placed.
+ Although objects in C++ can be unnamed (anonymous), more often we name our objects using an identifier. An object with a name is called a variable.
+ An object is used to store a value in memory. A variable is an object that has a name (identifier).
+ Naming our objects let us refer to those objects again later in the program.
------------------------------------------
VARIABLE DEFINITION
+ In order to use a variable in our program, we need to tell the compiler that we want one. The most common way to do this is by use of a special kind of declaration statement called a definition.
+ A definition statement can be used to tell the compiler that we want to use a variable in our program.
+ At compile-time (when the program is being compiled), when encountering this statement, the compiler makes a note to itself that we want a variable with the name 'x', and that the variable has the data type 'int'. From that point forward, whenever we use the identifier 'x' in our code, the compiler will know that we are referring to this variable.
+ The compiler handles all of the other details about this variable for use, including determining how much memory the object will need, in what kind of storage the object will be placed (in RAM or a CPU register), where it will be placed relative to other objects, when it will be created and destroyed, etc...
+ A variable created via a definition statement is said to be defined at the point where the definition statement is placed. For now, your variables should be defined inside functions.
------------------------------------------
VARIABLE CREATION
+ At runtime (when the program is loaded into memory and run), each object is given an actual storage location (such as RAM, or a CPU register) that it can use to store values. The process of reserving storage for an object's use is called allocation. Once allocation has occurred, the object has been created and can be used.
+ An object is created once actual storage has been reserved for the object's use.
+ When the program is run, execution starts at the top of function.  Memory for 'x' is allocated. Then the program ends.
------------------------------------------
DATA TYPES
+ So far, we've covered that objects are regions of storage that can store a data value. A data type (more commonly just called a type) determines what kind of value (e.g. number, letter, text, etc) the object will store.
+ In C++, the type of an object must be known at compile-time, and that type can not be changed without recompiling the program. This means an integer variable can only hold integer values. If you want to store some other kind of value, you'll need to use a different type.
+ The data type of an object must be known at compile-time (so the compiler knows hơ much memory that object requires).
+ Integers are just one of many types that C++ supports out of the box.
+ C++ also allows you to create your ơn custom types.
------------------------------------------
DEFINING MULTIPLE VARIABLES
+ It is possible to define multiple variables of the same type in a single statement by separating the names with a comma.
+ When defining multiple variables this way, there are three common mistakes that new programmers tend to make (neither serious, since the compiler will catch these and ask you to fix them):
    The first mistake is giving each variable a type when defining variables in sequence.
    The second mistake is to try define variables of different types in the same statement, which is not allowed. Variables of different types must be defined in separate statements.
------------------------------------------
SUMMARY
+ In C++, we use objects to access memory. A named object is called a variable. Each variable has an identifier, a type, and a value (and some other attributes that aren't relevant here). A variables's type is used to determine who the value in memory should interpreted.
+ Variables are actually created at runtime, when memory is allocated for their use.
------------------------------------------
QUIZ TIME
+ Question 1: What is data?
    → Data is any information that can be moved, processed, or stored by a computer.
+ Question 2: What is a value?
    → A value is a letter, number, text, or instance of some other useful concept that can be represented as data.
+ Question 3: What is an object?
    → An object is a region of storage (usually memory) that can store a value.
+ Question 4: What is a variable?
    → A variable is an object that has a name.
+ Question 5: What is an identifier?
    → An identifier is the name that a variable is accessed by.
+ Question 6: What is a data type used for?
    → A data type determines what kind of value the object will store.
*/