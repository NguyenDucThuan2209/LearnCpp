/*
------------------------------------------ 
+ A comment is a programmer-readable note that is inserted directly into the source code of the program. Comments are ignored by the compiler and are for the programmer's use only.
+ In C++ there are two different styles of comments, both of which serve the same purpose: to help programmers document the code in some way.
------------------------------------------ 
SINGLE-LINE COMMENTS
+ The '//' symbol begins a C++ single-line comment, which tells the compiler to ignore everything from the '//' symbol to the end of the line.
+ Typically, the single-line comment is used to make a quick comment about a single line code.
+ Having comments to the right of a line can make both the code and the comment hard to read, particularly if the line is long. If the lines are fairly short, the comments can simply be aligned (usually to a tab stop).
+ However, if the lines are long, placing comments to the right can make your lines really long. In that case, single-line comments are often placed above the line it is commenting.
------------------------------------------ 
MULTI-LINE COMMENTS
+ The '/ *' and '* /' pair of symbols denotes a C-style multi-line comment. Everything in between the symbols is ignored.
+ Multi-line style comments can not be nested.
+ This is one place where using a syntax highlighter can be really usefull, as the different coloring for the comment should make clear what's considered part of the comment vs not.
------------------------------------------ 
PROPER USE OF COMMENTS
+ Typically, comments should be used for three things. First, for a given library, program, or function, comments are best used to describe what the library, program, or function, does. These are typically placed at the top of the file or library, or immediately preceding the function.
+ All of these comments give the reader a good idea of what the library, program, or function is trying to accomplish without having to look at the actual code. The user (possibly someone else, or you if you're trying to reuse code you've previously written) can tell at a glance whether the code is relevant to what he or she is trying to accomplish. This is particularly important when working as part of a team, where not everybody will be familiar with all of the code.
+ Second, within a library, program, or function described above, comments can be used to describe how the code is going to accomplish its goal.
+ These comments give the user an idea of how the code is going to accomplish its goal without having to understand what each individual line of code does.
+ Third, at the statement level, comments should be used to describe why the code is doing something. A bad statement comment explains what the code is doing. If you ever write code that is so complex that needs a comment to explain what a statement is doing, you probably need to rewrite your statement, not comment it.
+ Programmers often have to make a tough decision between solving a problem one way, or solving it another way. Comments are a great way to remind yourself (or tell somebody else) the reason you made one decision instead of another.
Finally, comments should be written in a way that makes sense to someone who has no idea what the code does. It's often the case that a programmer will say "It's obvious what this does! There's no way I'll forget about this". Guess what? It's not obvious, and you will be amazed how quickly you forget. You (or someone else) will thank you later for writing down what, how, and why of your code in human language. Reading individual lines of code is easy. Understanding what goal they are meant to accomplish is not.
------------------------------------------
COMMENTING OUT CODE
+ Converting one or more lines of code into a comment is called commenting out your code. This provides a convenient way to (temporarily) exclude parts of your code from being included in your compiled program.
+ There are quite a few reasons you might want to do this:
    You're working on a new piece of code that won't compile yet, and you need to run the program. The compiler won't let you compile the code if there are compiler errors. Commenting out the code that won't compile will allow the program to compile so you can run it. When you're ready, you can uncomment the code, and continue working on it.
    You've written new code that compiles but doesn't work correctly, and you don't have time to fix it until later. Commenting out the broken code will ensure the broken code doesn't execute and cause problems until you can fix it.
    To find the source of an error. If a program isn't producing the desired results (or it crashing), it can sometimes be useful to disable parts of your code to see if you can isolate what's causing it to not work correctly. If you comment out one or more lines of code, and your program starts working as expected (or stop crashing), the odds are whatever you last commented out was part of the problem. You can then investigate why those lines of code are causing the problem.
    You want to replace one piece of code with another piece of code. Instead of just deleting the original code, you can comment it out and leave it there for reference until you're sure your new code works properly. Once you are sure your new code  is working, you can remove the old commented out code. If you can't get your new code to work, you can always delete the new code and uncomment the old code to revert what you had before.
+ Commenting out code is a common thing to do while developing, so many IDEs provide support for commenting out a highlighted section of code. How you access this functionality varies by IDE.
------------------------------------------
SUMMARY
+ At the library, program, or function level, use comments to describe what.
+ Inside the library, program, or function, use comments to describe how.
+ At the statement level, use comments to describe why.
*/