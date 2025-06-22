For a cmake setup to compile, build and run a C++ project, we need to follow these steps:
    1. Create a CMakeLists.txt file
        + cmake_minimum_required(VERSION 3.10): This tell CMake plugin that run this project that it need to be at least version 3.10 to continue process this program.
        + project(<project_name>): This will name the project as <project_name>. Please replace "<project_name>" with the specific name you want for your project.
        + set(CMAKE_CXX_STANDARD 17): This will make the CMake compiler to use C++17 standard for the compilation.
        + add_executable(<executable_file_name> <source_1> <source_2> ...): 
            - <executable_file_name>: Please replace this with name of the output file for your project's build process.
            - <source_1>, <source_2>: Please replace this with names of the source code files in your project.
            - NOTE: In CMake, function's parameters will separate with each other by whitespace (space, tab, newline). So after finish each file name, please take a whitespace before enter the new one.
    2. Configure CMake
        After running CMake: Configure (Ctrl + Shift + P), CMake creates the build/ folder to store everything needed to compile and link your code. So let's take a look at what it actually contain:
            - .cmake: This folder contain metadata about the project, build targets, and dependencies.
            - CMakeFiles: This folder contain internal data that CMake uses for build logic.
            - cmake_install.cmake: This file will define how to install build files (such as main.out) to a target location. It will copy the built executable and any other specified files (like libraries and headers) to an install directory. 
                → We don't need to care much about this one UNLESS we want to install this program to a system-wide location.
            - CMakeCache.txt: This file help CMake remembers your settings and compiler choices.
            - compile_commands.json: This json file will list out every compilation command CMake will run, file-by-file.
                → It comes with multiple elements as many as your code files.
                → Each element will contain 4 parts: directory, command, file, and output.
                    * directory: this will tell the compiler where to put the output file after the compilation complete.
                    * command: this will tell the compiler which command to use when compile this code file.
                    * file: this will tell the compiler where is the file need to be compiled.
                    * output: this will tell the compiler what is path (also name) of the output file after the compilation complete.
                → The compilation process will generate .o files base on the code files that has been selected. These are intermediate machine code files, which later will be linked together into 1 executable file (e.g. main.out) by the linker.
            - Makefile: This file is used by Cmake to actually build the code in the project.
    3. Build the project
        If you want to make sure everything is good for the build, adding warning flags could be useful:
            - add_compile_options(-Wall -Wextra -Wpedantic)
        There is an optional but good for practice, that is always take a clean build by running CMake: Clean Rebuild.
    4. Run the program
