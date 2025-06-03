/*
------------------------------------------
THE INPUT/OUTPUT LIBRARY
+ The input/output library (io library) is part of the C++ standard library that deals with basic input and output. We'll use the functionality in this library to get input from the keyboard and output data to the console. The io part of iostream stand for input/output.
+ To use the functionality defined within the iostream library, we need to include the iostream header at the top of any code file that uses the content defined in iostream, like so:
    #include <iostream>
------------------------------------------
sdt::cout
+ The iostream library contains a few predefined variables for use to use. One of the most useful is std::cout, which allows us to send data to the console to be printed as text. cout stands for "character output".
+ std::cout can print text, numbers, and value of variables.
+ To print more than one thing on the same line, the insertion operator '<<' can be used multiple times in a single statement to concatenate (link together) multiple pieces of output. For example:
    std::cout << "Hello" << " world!";
+ It might be helpfull to imagine the '<<' (and '>>') operator as a conveyor belt that moves data in the direction indicated. In this case, when the content is conveyed to 'std::cout', it gets output.
------------------------------------------
USING std::endl TO OUTPUT A NEWLINE
+ Separate output statements don't result in separate lines of output on the console.
+ If we want to print separate lines of output to the console, we need to tell the console to move the cursor to the next line. We can do that by outputting a newline. A newline is an OS-specific character or sequence of characters that moves the cursor to the start of the next line.
+ One way to output a newline is to output 'std::endl' (which stands for 'end line').
+ The last 'std::endl' in the program isn't technically necessary, since the program ends immediately afterward. However, it serves a few usefull purposes.
    First, it help indicate that the line of output is a 'complete thought' (as opposed to partial output that is completed somewhere later in the code). In this sense, it functions similarly to using a period in standard English.
    Second, it positions the cursor on the next line, so that if we later add additional lines of output (e.g. have the program say "Bye!"), those lines will appear where we expect (rather than appended to the prior line of output).
    Third, after running an executable from the command line, some operating system do not output a new line before showing the command prompt again. If our program does not end with the cursor on a new line, the command prompt may appear appended to the prior line of output, rather than at the start of a new line as the user would expect.
+ Best practice: Output a newline whenever a line of output is complete.
------------------------------------------
std::cout IS BUFFERED
+ Consider a rollercoaster ride at your favorite amusement park. Passengers show up (at some variable rate) and get in line. Periodically, a train arrives and boards passengers (up to the maximum capacity of the train). When the train is full, or when enough time has passed, the train departs with a batch of passengers, and the ride commences. Any passengers unable to board the current train wait for the next one.
+ This analogy is similar to how output sent to 'std::cout' is typically processed in C++. Statements in our program request that output be sent to the console. However, that output is typically not sent to the console immediately. Instead, the requested output "gets in line", and is stored in a region of memory set aside to collect such requests (called a buffer). Periodically, the buffer is flushed, meaning all of the data collected in the buffer is transferred to its destination (in this case, the console).
+ This also means that if your program crashes, aborts, or is paused before the buffer is flushed, any output still waiting in the buffer will not be displayed.
+ The opposite of buffered output is unbuffered output. With unbuffered output, each individual output request is sent directly to the output device.
+ Writing data to a buffer is typically fast, whereas transferring a batch of data to an output device is comparatively slow. Buffering can significantly increase performance by batching multiple output requests together to minimize the number of times output has to be sent to the output device.
------------------------------------------
std::endl VS \n
+ Using 'std::endl' is often inefficient, as it actually does two jobs: it outputs a newline (moving the cursor to the next line of the console), and it flushes the buffer (which is slow). If we output multiple lines of text ending with 'std::endl', we will get multiple flushes, which is slow and probably unnecessary.
+ When outputting text to the console, we typically don't need to explicitly flush the buffer ourselves. C++'s output psystem is designed to self-flush periodically, and it's both simpler and more efficient to let it flush itself.
+ To ouput a newline without flushing the output buffer, we use '\n' (inside either single or double quotes), which is a special symbol that the compiler interprets as a newline character. '\n' moves the cursor to the next line of the console without causing a flush, so it will typically perform better. '\n' is also more concise to type and can be embedded into existing double-quoted text.
+ When the '\n' is not being embedded into an existing line of double-quoted text, it is conventionally single quoted.
+ In C++, we use single quotes to represent single characters (such as 'a' or '$'), and double-quotes to represent text.
+ Even though '\n' is represented in source code as two symbols, it is treated by the compiler as a single linefeed (LF) character (with ASCII value 10), and thus is conventionally single quoted (unless embedded into existing double-quoted text).
+ When '\n' is output, the library doing the outputting is responsible for translating this single LF character into the appropriate newline sequence for the given OS.
+ Although unconventional, we believe it's fine to use (or even prefer) double quoted "\n" in standard output statements. This has 2 primary benefits:
    1. It's simpler to double-quote all outputted text rather than having to determine what should be single-quotefd and double-quoted.
    2. More importantly, it helps avoid inadvertent multicharacter literals.
+ Single quotes should be preferred in non-output cases.
+ Best practice: Prefer '\n' over 'std::endl' when outputting text to the console.
+ Warning:
    '\n' uses a backslash (as do all special characters in C++), not a forward slash.
    Using a forward slash or including other characters inside the single quotes will result in unexpected behavior. For example:
        std::cout << '/n'; // will often print as 12142, which probably isn't what you were expecting.
------------------------------------------
std::cin
+ 

*/