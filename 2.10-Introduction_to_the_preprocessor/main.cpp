/*
------------------------------------------
+ When you compile your project, you might expect that the compiler compiles each code file exactly as you've written it. This actually isn't the case.
+ Instead, prior to compilation, each code file goes through a preprocessing phase. In this phase, a programcalled the preprocessor makes various changes to the text of the code file. The preprocessor does not actually modify the original code files in any way -- rather, all changes made by the preprocessor happen either temporarily in-memory or using temporary files.
+ Historically, the preprocessor was a separate program from the compiler, but in modern compilers, the preprocessor may be built right into the compiler itself.
+ Most of what the preprocessor does is fairly uninteresting. For example, it strips out comments, and ensures each code file ends in a newline. However, the preprocessor does have one very important role: it is what processes #include directives.
+ When the preprocessor has finished processing a code file, the result is called a translation unit. This translation unit is what is then compiled by the compiler.
*/