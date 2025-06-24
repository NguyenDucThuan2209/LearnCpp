// In lesson 2.8 -- Programs with multiple code files, we discussed how programs can be split across multiple files. We also discussed how forward declarations are used to allow the code in one file to access something defined in another file.
// When programs contain only a few small files, manually adding a new forward declarations to the top of each file isn't too bad. However, as programs grow larger (and make use of more files and functions), having to manually add a large number of (possibly different) forward declarations to the top of each file becomes extremely tedious. For example, if you have a 5 file program, each of which requires 10 forward declarations, you're going to have to copy/past in 50 forward declarations. Now consider the case where you have 100 files and they each require 100 forward declarations. This simply doesn't scale!
// To address this issue, C++ programs typically take a different approach
/*------------------------------------------*/
// HEADER FILES
// C++ code files are not the only files commonly seen in C++ programs. The other type of file is called a header file. Header file usually have a .h extension, but you will occasionally see them with a .hpp extension or no extension at all.
// Conventionally, header files are used to propagate a bunch of related forward declarations into a code file.
// Header files allow us to put declarations in one place and then import them wherever we need them. This can save a lot of typing in multi-file programs.
/*------------------------------------------*/
// USING STANDARD LIBRARY HEADER FILES
// Consider the following program:
#if 0

#include <iostream>
int main()
{
    std::cout << "Hello, world!";
    return 0;
}

#endif
// This program prints "Hello, world!" to the console using std::cout. However, this program never provided a definition or declaration for std::cout, so how does the compiler know what std::cout is?
// The answer is that std::cout has been forward declared in the "iostream" header file. When we #include <iostream>, we're requesting that the preprocessor copy all of the content (including forward declarations for std::cout) from the file named "iostream" into the file doing the #include.
// When you #include a file, the contant of the included file is inserted at the point of inclusion.This provides a usefull way to pull in declarations from another file.
// Consider what would happen if the iostream header did not exist. Wherever you used std::cout, you would have to manually type or copy in all of the declarations related to std::cout into the top of each file that used std::cout. This would require a lot of knowledge about how std::cout was declared, and would be a ton of work. Even worse, if a function prototype was added or changed, we'd have to go manually update all of the forward declarations. 
// It's much easier to just #include <iostream>!
/*------------------------------------------*/
// USING HEADER FILES TO PROPAGATE FORWARD DECLARATIONS
// Now let's go back to the example we were discussing in a previous lesson. When we left off, we have 2 files, add.cpp and main.cpp, that look like this:
// add.cpp
#if 0
int add(int x, int y)
{
    return x + y;
}
#endif

// main.cpp
#if 0
#include <iostream>
int add(int x, int y);
int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << "\n";
    return 0;
}
#endif

// In this example, we used a forward declaration so that the compiler will know what identifier add is when compiling main.cpp. As previously mentioned, manually adding forward declarations for every function you want to use that lives in another file can get tedious quickly.
// Let's write a header file to relieve us of this burden. Writing a header file is surprisingly easy, as header files only consist of 2 parts:
//// 1. A header guard
//// 2. The actual content of the header file, which should be the forward declarations for all of the identifiers we want other files to be able to see.
// Adding a header file to a project works analogously to adding a source file
// Best practice: 
//// Prefer a .h suffix when naming your header files (unless your project already follows some other convention).
//// This is a longstanding convention for C++ header files, and most IDEs still default to .h over other options.
// Header files are often paired with code files, with the header file providing forward declarations for the corresponding code file. Since out header file will contain a forward declaration for functions defined in add.cpp, we'll call out new header file add.h.
// Best practice:
//// If a header file is paired with a code file (e.g. add.h with add.cpp), they should both have the same base name (add).
// Here is our completed header file:
// add.h:
#if 0
// We really should have a header guard here, but will omit it for simplicity

// This is the content of the .h file, which is where the declarations go
int add(int x, int y);
#endif

// In order to use this header file in main.cpp, we have to #include it (using quotes, not angle brackets).
#if 0
#include "add.h"
#endif

// When the preprocessor processes the #include "add.h" line, it copies the contents of add.h into the current file at that point. Because our add.h contains a forward declaration for function add(), that forward declaration will be copied into main.cpp. The end result is a program that is functionally the same as the one where we manually added the forward declaration at the top of main.cpp.
/*------------------------------------------*/
// HOW INCLUDING DEFINITIONS IN A HEADER FILE RESULTS IN A VIOLATIONS OF THE ONE-DEFINITION RULE
// For now, you should avoid putting function or variable definitions in header files. Doing so will generally result in a violation of the one-definition rule (ODR) in cases where the header file is included into more than one source file.
// Let's illustrate how this happens:
// add.h:
#if 0
int add(int x, int y)
{
    return x + y;
}
#endif

// main.cpp
#if 0
#include "add.h"
#include <iostream>
int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << "\n";
    return 0;
}
#endif

// add.cpp:
#if 0
#include "add.h"
#endif

// When main.cpp is compiled, the #include "add.h" will be replaced with the contents of add.h and then compiled. Therefore, the compiler will compile something that look like this:
// main.cpp (after preprocessing):
#if 0
// from add.h
int add(int x, int y)
{
    return x + y;
}

// Contents of iostream header here

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << "\n";
    return 0;
}
#endif

// This will compile just fine.
// When the compiler compiles add.cpp, the #include "add.h" will be replaced wiht the contents of add.h and then compiled. Therefore, the compiler will compile something like this:
// add.cpp (after preprocessing):
#if 0
int add(int x, int y)
{
    return x + y;
}
#endif

// This will also compile just fine.
// Finally, the linker will run. And the linker will see that there are now 2 definitions for function add(): 1 in the main.cpp and 2 in add.cpp. This is a violation of ODR part 2, which states, "Within a given program, avariable or normal function can only have 1 definition."
// Best practice:
//// Do not put function and variable definitions in your header files (for now)
//// Defining either of these in a header file will likely result in a violation of the ODR if that header is then #include into more than one source file.
/*------------------------------------------*/
// SOURCE FILES SHOULD INCLUDE THEIR PAIRED HEADER
// In C++, it is a best practice for code files to #include their paired header file (if one exists). This allows the compiler to catch certain kinds of errors at compile time instead of link time.
// Unfortunately, this doesn't work if it is a parameter with a different type of instead of a return type. This is because C++ supports overloaded functions (functions with the same name but different parameter types), so the compiler will assume a function with a mismatched parameter type is a different overload.
// If the #include "add.h" is not present, the compiler won't catch the issue because it doesn't see the mismatch. We have to wait until link time for the issue to surface.
// We will also see many examples in future lessons where content required by the source file is defined in the paired header. In such cases, including the header is a necessity.
// Best practice:
//// Source files should #include their paired header file (if one exists).
/*------------------------------------------*/
// DO NOT #include .cpp FILE
// Although the preprocessor will happily do so, you should generally not #include .cpp files. These should be added to your project and compiled.
// These are number of reasons for this:
//// Doing so can cause naming collisions between source files.
//// In a large project it can be hard to avoid ODR issue.
//// Any change to such a .cpp file will cause both the .cpp file and any other .cpp file that includes it to recompile, which can take a long time. Headers tend to change less often than source files.
//// It is non-conventional to do so.
// Best practice:
//// Avoid #include .cpp files
// If your project doesn't compile unless you #include .cpp files, that means those .cpp files are not being compiled as part of your project. Add them to your project or command line so they get compiled.
/*------------------------------------------*/
// TROUBLESHOOTING
// If you get a compiler error indicating that add.h isn't found, make sure the file is really named add.h. Depending on how you created and named it, it's possible the file could have been named something like add (no extension) or add.h.txt, etc. Also make sure it's sitting in the same directory as the rest of your code files.
// If you get a linker error about function add not being defined, make sure you've included add.cpp in your project so the definition for function add can be linked into the program.
/*------------------------------------------*/
// ANGLED BRACKETS VS DOUBLE QUOTES
