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
// You've probably curious why we angled brackets for iostream, and double quotes for add.h. It's possible that a header file with the same filename might exist in multiple directories. Our use of angled brackets vs double quotes helps give the preprocessor a clue as to where it should look for header files.
// When we use angled brackets, we're telling the preprocessor that this is a header file we didn't write ourselves. The preprocessor will search for the header only in the directories. Our use of angled brackets vs double quotes helps give the preprocessor a clue as to where it should look for header files.
// When we use angled brackets, we're telling the preprocessor that this is a header file we didn't write ourselves. The preprocessor will search for the header only in the directories specified by the include directories. The include directories are configured as part of your project/IDE settings/compiler settings, and typically default to the directories containing the header files that come with your compiler and/or OS. The preprocessor will not search for the header file in your project's source code directory.
// When we use double-quotes, we're telling the preprocessor that this is a header file that we wrote. The preprocessor will first search for the header file in the current directory. If it can't find a matching header there, it will then search the include directories.
// Use double quotes to include header files that you've written or are expected to be found in the current directory. Use angled brackets to include headers that come with your compiler, OS, or third-party libraries you've installed elsewhere on your system.
/*------------------------------------------*/
// WHY DOESN'T iostream HAVE A .h EXTENSION
// Another commonly asked question is "why doesn't iostream (or any of other standard library header files) have a .h extension?". The answer is that iostream.h is a different header file than iostream! To explain requires a short history lesson.
// When C++ was first created, all of the headers in standard library ended in a .h suffix. These headers included:
/*
    + Header type | Naming convention | Example | Namespace belonged
    + C++ specific: <xxx.h> | iostream.h | Global namespace
    + C compatibility: <xxx.h> | stddef.h | Global namespace
*/
// The original versions of cout and cin were declared in iostream.h in global namespace. Life was consistent, and it was good.
// When the language was standardized by the ANSI committee, they decided to move all of the names used in the standard library into the std namespace to help avoid naming conflicts with user-declared identifiers. However, this presented a problem: if they moved all the names into the std namespace, non of the old programs (that included iostream.h) would work anymore!
// To work around this issue, C++ introduced new header files that lack the .h extension. These new header files declare all names inside the std namespace. This way, older programs that include <iostream.h> do not need to be rewritten, and newer programs can #include <iostream>.
// Modern C++ now contains 4 sets of header files:
/*
    + Header type | Naming convention | Example | Namespace belonged
    + C++ specific (new): <xxx> | iostream | std namespace
    + C compatibility (new): <cxxx> | stddef | std namespace
    + C++ specific (old): <xxx.h> | iostream.h | Global namespace
    + C compatibility (old): <xxx.h> | stddef.h | Global namespace
*/
// The new C compatibility headers <cxxx> may optionally declare names in the global namespace, and the old C compatibility headers <xx.h> may optionally delcare names in the std namespace. Names in these locations should be avoided, as those names may not be declared in those locations on other implementations.
// Best practice: Use the standard library header files without the .h extension. User-defined headers should still use a .h extension.
/*------------------------------------------*/
// INCLUDING HEADER FILES FROM OTHER DIRECTORIES
// Another common question involves how to include header files from other directories.
// One (bad) way to do this is to include a relative path to the header file you want to include as part of the #include line.
// While this will compile (assuming the files exist in those relative directories), the downside of this approach is that it requires you to reflect your directory structure in your code. If you ever update your directory structure, your code won't work anymore.
// A better method is to tell your compiler or IDE that you have a bunch of header files in some other location, so that it will look there when it can't find them in the current directory. This can generally be done by setting an include path or search directory in your IDE project settings.
// The nice thing about this approach is that if you ever change your directory structure, you only have to change a single compiler or IDE setting instead of every code file.
/*------------------------------------------*/
// HEADERS MAY INCLUDE OTHER HEADERS
// It's common that the content of a header file will make use of something that is declared (or defined) in another header file. When this happens, the header file should #include the other header file containing the declaration (or definition) that it needs.
/*------------------------------------------*/
// TRANSITIVE INCLUDES 
// When your source file #include a header file, you will also get any other header files that are #include by that header (and any header files those include, and so on). These additional header files are sometimes called transitive includes, as they're included implicity rather than explicitly rather than explicitly.
// The content of these transitive includes are available for use in your code file. However, you generally should not rely on the content of headers that are included transitively (unless reference documentation indicates that those transitive includes are required). The implementation of header files may change over time, or be different across different systems. If that happens, your code may only compile on certain systems, or may compile now but not in the future. This is easily avoided by explicitly including all of the header files the content of your code file requires. 
// Best practice: Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.
// Unfortunately, there is no easy way to detect when your code file is accidentally relying on content of a header file that has been included by another header file.
/*------------------------------------------*/ 
// THE ORDER OF INCLUSION FOR HEADER FILES
// If your header files are written properly and #include everything they need, the order of inclusion shouldn't matter.
// Now consider the following scenario: let's say header A needs declarations from header B, but forgets to include it. In our code file, if we include header B before header A, our code will still compile! This is because the compiler will compile all the declarations from B before it compiles the code from A that depends on those declarations.
// However, if we include header A first, then the compiler will complain because the code from A will be compiled before the compiler has been declarations from B. This is actually preferable, because the error has bene surfaced, and we can then fix it.
// Best practice:
//// To maximize the chance that missing includes will be flagged by compiler, order your #include as follows (skipping any that are not relevant)
////// The paired header for this code
////// Other headers from the same project
////// 3rd party library headers
////// Standard library headers
//// The headers for each grouping should be sorted alphabetically (unless the documentation for a 3rd party library instructs you to do otherwise).
// That way, if one of your user-defined headers is missing an #include for a 3rd party library or standard lirbary header, it's more likely to cause a compile error so you can fix it.
/*------------------------------------------*/
// HEADER FILE BEST PRACTICES
// Here are a few more recommendations for creating and using header files:
//// Always include header guards.
//// Do not define variables and function in header files (for now).
//// Give a header file the same name as the source file it's associated with.
//// Each header file should have a specific job, and be as independent as possible.
//// Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files, to avoid inadvertent transitive includes.
//// A header file should #include any other headers containing functionality it needs. Such a header should compile successfully when #include into a .cpp file by itself.
//// Only #include what you need (don't include everything just because you can).
//// Do not #include .cpp files.
//// Prefer putting documentation on what something does or how to use it in the header. It's more likely to be seen there. Documentation describing how something works should remain in the source files.
