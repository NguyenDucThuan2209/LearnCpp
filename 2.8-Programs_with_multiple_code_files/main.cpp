/*
------------------------------------------
ADDING FILES TO YOUR PROJECT
+ As programs get larger, it is common to split them into multiple files for organizational or reusability purposes. One advantage of working with an IDE is that they make working with multiple files much easier. You already know how to create and compile single-file project. Adding new files to existing projects is very easy.
+ Best practice: When you add new code files to your project, give them a .cpp extension.
+ For gcc users: From the command line, you can create the additional file yourself, using your favorite editor, and give it a name. When you compile your program, you'll need to include all of the relevant code files on the compile line. For example: g++ main.cpp add.cpp - main.out, where main.cpp and add.cpp are the names fo your code files, and main.out is the name of the output file.
+ For VS code users: 
    To create a new file, choose View > Explorer from the top nav to open the Explorer pane, and then click the New File icon to the right of the project name. Alternately, choose File > New File from the top nav. Then give your new file a name (don't forget the .cpp extension). If the file appears inside the .vscode folder, drag it up one level to the project folder.
    Next open the tasks.json file, and file the line "${file}". You have 2 options here:
        If you wish to be explicit about what files get compiled, replace "${file}" with the name of each file you wish to compile, one per line, like this:
            "main.cpp"
            "add.cpp"
        You can have VS code automatically compile all .cpp files in the directory by replacing "${file}" with "${fileDirname}\\**.cpp" (on Windows and Unix).
------------------------------------------
A MULTI-FILE EXAMPLE
+ We took a look at a sing-file program that wouldn't compile:
    #include <iostream>

    int main()
    {
        std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
        return 0;
    }
    int add(int x, int y)
    {
        return x + y;
    }
+ When the compiler reaches the function call to add in main, it doesn't know what add is, because we haven't defined add yet. Our solution to this was to either reorder the functions (placing add first) or use forward declaration for add.
+ Now let's take a look at a similar multi-file program:
add.cpp:
    int main(int x, int y)
    {
        return x + y;
    }
main.cpp:
    #include <iostream>
    int main()
    {
        std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
        return 0;
    }
+ Your compiler may compile either add.cpp or main.cpp first. Either way, main.cpp will fail to compile, giving the same compiler error as the previous example: 
    'add' identifier not found
+ The reason is exactly the same as well: When the compiler reach the function call to add in main, it doesn't know what identifier add is.
+ Remember, the compiler compiles each file individually. It does not know about the contents of other code files, or remember anything it has seen from previously compiled code files. So even though the compiler may have seen the definition of function add previously (if it compiled add.cpp first), it doesn't remember.
+ This limited visibility and short memory is intentional, for a few reasons:
    1. It allows the source files of a project to be compiled in any order.
    2. When we change a source file, only that source file needs to be recompiled.
    3. It reduces the possibility of naming conflicts between identifiers in different files.
+ Out options for a solution here are the same as before: place the definition of function add before function main, or satisfy the compiler with a forward declaration. In this case, because function add is in another file, reordering option is not possible.
+ The solution here is to use a forward declaration: int add(int x, int y);
+ Now, when the compiler is compiling main.cpp, it will know what identifier add is and be satisfied. The linker will connect the function call to add in main.cpp to the definition of function add in add.cpp.
+ Using this method, we can give files access to functions that live in another file.
+ Try compiling add.cpp and the main.cpp with the forward declaration for yourself. If you get a linker error, make sure you've added add.cpp to your project or compilation line properly.
+ Because the compiler compiles each code file individually (and then forgets what it has seen), each code file that uses std::cout or std::cin needs to #include <iostream>
+ When an identifier is used in an expression, the identifier must be connected to its definition.
    If the compiler has seen neither a forward declaration nor a definition for the identifier in the file being compiled, it will error at the point where the identifier is used.
    Otherwise, if a definition exists in the same file, the compiler will connect the use of the identifier to its definition.
    Otherwise, if a definition exists in a different file (and is visible to the linker), the linker will connect the use of the identifier to its definition.
    Otherwise, the linker will issue an error indicating that it could not find a definition for the identifier.
------------------------------------------
SUMMARY
+ C++ is designed so that each source file can be compiled independently, with no knowledge of what is in other files. Therefore, the order in which files are actually compiled should not be relevant.
+ We will begin working with multiple files a lot once we get into object-oriented programming, so now's as good a time as any to make sure you understand how to add and compile multiple file projects.
+ Reminder: Whenever you create a new code file (.cpp), you will need to add it to your project so that it gets compiled.
*/

#include <string>
#include <iostream>

int add(int x, int y);
int getInputWithNote(std::string content);

int main()
{
    int first{getInputWithNote("Enter first number: ")};
    int second{getInputWithNote("Enter second number: ")};

    std::cout << "The sum of " << first << " and " << second << " is: " << add(first, second);
    return 0;
}