/*
------------------------------------------
+ When you compile your project, you might expect that the compiler compiles each code file exactly as you've written it. This actually isn't the case.
+ Instead, prior to compilation, each code file goes through a preprocessing phase. In this phase, a programcalled the preprocessor makes various changes to the text of the code file. The preprocessor does not actually modify the original code files in any way -- rather, all changes made by the preprocessor happen either temporarily in-memory or using temporary files.
+ Historically, the preprocessor was a separate program from the compiler, but in modern compilers, the preprocessor may be built right into the compiler itself.
+ Most of what the preprocessor does is fairly uninteresting. For example, it strips out comments, and ensures each code file ends in a newline. However, the preprocessor does have one very important role: it is what processes #include directives.
+ When the preprocessor has finished processing a code file, the result is called a translation unit. This translation unit is what is then compiled by the compile.
+ The entire process of preprocessing, compiling, and linking is called translation.
------------------------------------------
PREPROCESSOR DIRECTIVES
+ When the preprocessor runs, it scans through the code file (from top to bottom), looking for preprocessor directives. Preprocessor directives (often just called directives) are instructions that start with a #symbol and end with a newline (NOT a semicolon). These directives tell the preprocessor to perform certain text manipulation tasks. Note that the preprocessor does not understand C++ syntax -- instead, the directives have their own syntax (which in some cases resembles C++ syntax, and in other cases, not so much).
+ The final output of the preprocessor contains no directives -- only the output of the processed directive is passed to the compiler.
+ Using directives are not preprocessor directives (and thus are not processed by the preprocessor). So while the term directive usually means a preprocessor directive, this is not always the case.
------------------------------------------
#include
+ You've already seen the #include directive in action (generally to #include <iostream>). When you #include a file, the preprocessor replaces the #include directive with the contants of the included file. The included contents are then preprocessed (which may result in additional #includes being preprocessed recursively), then the rest of the file is preprocessed.
+ Consider the following program:
#include <iostream> 
int main()
{
    std::cout << "Hello, world!\n";
    return 0;
}

+ When the preprocessor runs on this program, the preprocessor will replace #include <iostream> with the contants of the file named "iostream" and then preprocess the included contant and the rest of the file.
+ Each translation unit typically consists of a single code file and all header files it #includes (applied recursively, since header files can #include other header files).
------------------------------------------
MACRO DEFINES
+ The #define directive can be used to create a macro. In C++, a macro is a rule that defines how input text is converted into replacement output text.
+ There are 2 basic types of macros: object-like macros, and function-like macros.
+ Function-like macros act like functions, and serve a similar purpose. Their use is generally considered unsafe, and almost anything they can do can be done by a normal function.
+ Object-like macros can be defined in one of two ways:
    #define IDENTIFIER
    #define IDENTIFIER substitution_text
+ The top definition has no substitution text, whereas the bottom one does. Because these are preprocessor directives (not statements), note that neither form ends with a semicolon.
+ The identifier for a macro uses the same naming rules as normal identifiers: they can be letters, numbers, and underscores, cannot start with a number, and should not start with an underscore. By convention, macro names are typically all uppercase, separated by underscores.
+ Best practice: Macro names should be written in all uppercase letters, with words separated by underscores.
------------------------------------------
OBJECT-LIKE MACROS WITH SUBSTITUTION TEXT
+ When preprocessor encounters this directive, an association is made between the macro identifier and substitution_text. All further occurrences of the macro identifier (outside of use in other preprocessor commands) are replaced by the substitution_text.
+ Consider the following program:
#include <iostream>
#define MY_NAME "Timmy"
int main()
{
    std::cout << "My name is: " << MY_NAME << "\n";
    return 0;
}

+ The preprocessor converts the above into the following:
// The contents of iostream will be inserted here
// Next is the code file 
int main()
{
    std::cout << "My name is: " << "Timmy" << "\n";
    return 0;
}

+ Which, when run, prints the output: My name is: Timmy.
+ Object-like macros with substitution text were used as a way to assign names to literals. This is no longer necessary, as better methods are available in C++. Object-like macros with substitution text are now mostly seen in legacy code, and we recommend avoiding them whenever possible.
+ Best practice: Avoid macros with substitution text unless no viable alternatives exist.
------------------------------------------
OBJECT-LIKE MACROS WITHOUT SUBSTITUTION TEXT
+ Object-like macros can also be defined without substitution text.
+ Macros of this form work like you might expect: most further occurrences of the identifier is removed and replaced by nothing.
+ This might seem pretty useless, and it is useless for doing text substitution. However, that's not what this form of the directive is generally used for.
+ Unlike object-like macros with substitution text, macros of this form are generally considered acceptable to use.
------------------------------------------
CONDITIONAL COMPILATION
+ The conditional compilation preprocessor directives allow you to specify under what conditions something will or won't compile. There are quire a few different conditional compilation directives, but we'll only cover a few that are used the most often: #fdef, #ifndef, and #endif.
+ The #ifdef preprocessor directive allows the preprocessor to check whether an identifier has been previously defined via #define. If so, the code between the #ifdef and matching #endif is compiled. If not the code is ignored.
+ Consider the following program:
#include <iostream>

#define PRINT_TIMMY

int main()
{
#ifdef PRINT_TIMMY
    // Will be compiled since PRINT_TIMMY is defined
    std::cout << "Timmy\n";
#endif

#ifdef PRINT_TONY
    // Will be excluded since PRINT_TONY is not defined
    std::cout << "Tony\n"; 
#endif

    return 0;
}
+ #ifndef is the opposite of #ifdef, in that it allows you to check whether an identifier has NOT been #define yet.
------------------------------------------
#if 0
+ One more common use of conditional compilation involves using #if 0 to exclude a block of code from being compiled (as if it were inside a comment block)
+ This provides a convenient way to "comment out" code that contains multi-line comments (which can't be commented out using another multi-line comment due to multi-line comments being non-nestable).
------------------------------------------
MACRO SUBSTITUTION WITHIN OTHER PREPROCESSOR COMMANDS
+ Since we defined PRINT_TIMMY to be nothing, how come the preprocessor didn't replace PRINT_TIMMY in #ifdef PRINT_TIMMY with nothing and exclude the output statement from compilation?
+ In most cases, macro substitution does not occur when a macro identifier is used within another preprocessor command.
+ There is at least one exception to this rule: most forms of #if and #elif do macro substitution within the preprocessor command.
#define FOO 9 // Here is the macro substitution

// This FOO does not get replaced with 9 because it's part of another preprocessor directive
ifdef FOO 
    // This FOO gets replaced with 9 because it's part of the normal code
    std::cout << FOO << "\n";
#endif
------------------------------------------
THE SCOPE OF #DEFINE
+ Directives are resolved before compilation, from top to bottom on a file-by-file basis.
+ Even if #define PRINT_TIMMY is defined inside a function, the preprocessor still not care/understand C++ concepts like functions. Therefore, this program behaves identically to one where #define PRINT_TIMMY was defined on the top on the file. To avoid confusion, you'll generally want to #define identifiers outside of functions.
+ Because an #include directive replaces the #include directive with the content of the included file, an #include can copy directives from the included file into the current file. These directives will the be processed in order.
+ One the preprocessor has finished, all defined identifiers from that file are discarded. This means that directives are only valid from the point of definition to the end of the file in which they are defined. Directives defined in one file do not have any impact on other files (unless they are #included into another file).
*/