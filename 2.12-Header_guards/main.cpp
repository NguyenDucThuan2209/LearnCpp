/*------------------------------------------*/
// THE DUPLICATE DEFINITION PROBLEM
// In lesson 2.7, we noted that a variable or function identifier can only have one definition (the ODR). Thus, a program that defines a variable identifier more than once will cause a compile error.
// While these programs are easy to fix, with header files, it's quite easy to end up in a situation where a definition in a header file gets included more than once. This can happen when a header file #include another header file (which is common).
/*------------------------------------------*/
// HEADER GUARDS
// The good news is that we can avoid the above problem via a mechanism called a heder guard (also called an include guard). Header guards are conditional compilation directives that take the following form:
#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE
#endif
// When this header is #included, the preprocessor will check whether SOME_UNIQUE_NAME_HERE has been previously defined in this translation unit. If this is the first time we're including the heder, SOME_UNIQUE_NAME_HERE will not have been defined. Consequently, it #define SOME_UNIQUE_NAME_HERE and includes the contents of the file. If theheader is included again into the same file, SOME_UNIQUE_NAME_HERE will already have been defined from the first time the contents of the header were included, and the contents of the header will be ignored (thanks to the #ifndef).
// All of your header files should have header guards on them. SOME_UNIQUE_NAME_HERE can be any name you want, but by convention si set to the full filename of the header file, typed in all caps, using underscores for spaces or punctuation. 
// Even the standard library headers use header guards. If you were to take a look at the iostream header file, you would see:
#ifndef _IOSTREAM_
#define _IOSTREAM_
// Library content here
#endif
// In large programs, it's possible to have 2 separate header files (included from different directories) that end up having the same filename (e.g. directoryA/config.h and directoryB/config.h). If only the filename is used for the include guard (e.g. CONFIG_H), these two files may end up using the same guard name. If that happens, any file that includes (directly or indirectly) both config.h files will not receive the contents of the include file to be included second. This will probably cause a compilation error.
// Because of this possibility for guard name conflict, many developers recommend using a more complex/unique name in your header guards. Some good suggestions are a naming convention of PROJECT_PATH_FILE_H, FILE_LARGE_RANDOM_NUMBER_H, or FILE_CREATION_DATE_H.
/*------------------------------------------*/
// HEADER GUARDS DO NOT PREVENT A HEADER FROM BEING INCLUDED ONCE INTO DIFFERENT CODE FILES
// Note that the goal of header guards is to prevent a code file from receiving more than one copy of a guarded header. By design, header guards do not prevent a given header file from being included into separate code files. This can also cause unexpected problems. 
/*------------------------------------------*/
// CAN'T WE JUST AVOID DEFINITIONS IN HEADER FILES?
// We've generally told you not to include function definitions in your headers. So you may be wondering why you should include header guards if they protect you from something you shouldn't do.
// There are quire a few cases we'll show you in the future where it's necessary to put non-function definitions in a header file. For example, C++ will let you create your own types. These custom types are typically defined in header files, so the type definitions can be propagated out to the code files that need to use them. Without a header guard, a code file could end up with multiple (identical) copies of a given type definition, which the compiler will flag as an error.
// So even though it's not strictly necessary to have header guards at this point in the tutorial series, we're establishing good habits now, so you don't have to unlearn bad habits later.
/*------------------------------------------*/
// #pragma once
// Modern compilers support a simpler, alternate form of header guards using the #pragma preprocessor directive.

#pragma once
// code here

// #pragma once serves the same purpose as header guards: to avoid a header file from being included multiple times. With traditional header guards, the developer is responsible for guarding the header (by using preprocessor directives #ifndef, #define, and #endif). With #pragma once, we're requesting that the compiler guard the header. How exactly it does this is an implementation-specific detail.
// There is one know case where #pragma once will typically fail. If a header file is copied so that it exists in multiple places on the file system, if somehow both copies of the header get included, header guards will successfully de-dupe the identical headers, but #pragma once won't (because the compiler won't realize they are actually identical content).
// For most projects, #pragma once works fine, and many developers now prefer it because it is easier and less error-prone. Many IDEs will also auto-include #pragma once at the top of a new header file generated through the IDE.
// The #pragma directive was designed for compiler implementers to use for whatever purposes they desire. As such, which pragmas are supported and what meaning those pragmas have is completely implementation-specific. With the exception of #pragma once, do not expect a pragma that works on one compiler to be supported by another.
// Because #pragma once is not defined by the C++ standard, it is possible that some compilers may not implement it. For this reason, some development houses (such as Google) recommend using traditional header guards. In this tutorial series, we will favor header guards, as they are the most conventional way to guard headers. However, support for #pragma once is fairly ubiquitous at this point, and if you wish to use #pragma once instead, that is generally accepted in modern C++.
/*------------------------------------------*/
// SUMMARY
// Header guards are designed to ensure that the contents of a given header file are not copied more than once into any single file, in order to prevent duplicate definitions. 
// Duplicate declarations are fine -- but even if your header file is composed of all declarations (no definitions) it's still a best practice to include header guards.
// Note that header guards do not prevent the contents of a header file from being copied (once) into separate project files. This is a good thing, because we often need to reference the contents of a given header from different project files.