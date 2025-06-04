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
+ std::cin is another predefined variable in the iostream library. Whereas std::cout prints data to the console (using the insertion operator << to provide the data), std::cin (which stands for "character input") reads input from keyboard. We typically use the extraction operator >> to put the input data in a variable (which can then be used in subsequent statements).
+ Just like it is possible to output more than one bit of text in a single line, it is also possible to input more than one value on a single line. Values entered should be separated by whitespace (spaces, tabs, or newlines).
+ The C++ I/O library does not provide a way to accept keyboard input without the user having to press enter. If that is something you desire, you'll have to use a third party library. For console applications, we'd recommend pdcurses, FXTUI, cpp-terminal, or notcurses. Many graphical user interface libraries have their own functions to do this kind of thing.
------------------------------------------
std::cin IS BUFFERED
+ In a prior section, we noted that outputting data is actually a two stage process:
    1. The data from each output request is added (to the end) of an output buffer.
    2. Later, the data from (the front of) the output buffer is flushed to the output device (the console).
+ Adding data to the end of a buffer and removing it from the front of a buffer ensures data is processed in the same order in which it was added. This is sometimes called FIFO (first in, first out).
+ Similarly, inputting data is also a two stage process:
    1. The individual characters you enter as input are added to the end of an input buffer (inside std::cin). The enter key (pressed to submit the data) is also stored as a '\n' character.
    2. The extraction operator >> removes character from the front of the input buffer and converts them into a value that is assigned (via copy-assignment) to the associated variable. This variable can then be used in subsequent statements.
+ Each line of input data in the input buffer is terminated by a '\n' character
+ We'll demonstrate this using the following program:

int main()
{
    std::cout << "Enter 2 numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered: " << x << " and " << y << '\n';
    
    return 0;
}
+ This program inputs to 2 variables (this time as separate statements). We'll run this program twice.
    Run #1: 
        When std::cin >> x; is encountered, the program will wait for input. Enter the value 4. The input 4\n goes into the input buffer, and the value 4 is extracted to variable x.
        When std::cin >> y; is encountered, the program will again wait for input. Enter the value 5. The input 5\n goes into the input buffer, and the value 5 is extracted to variable y. Finally, the program will print "You entered: 4 and 5".
    -> There should be nothing surprising about this run.

    Run #2:
        When std::cin >> x; is encountered, the program will wait for input. Enter "4 5". The input "4 5\n" goes into the input buffer, but only the 4 is extracted to variable x (extraction stops at the space).
        When std::cin >> y; is encountered, the program will NOT wait for input. Instead, the 5 that still in the input buffer is extracted to variable y. The program then prints "You entered: 4 and 5".
    → The program didn't wait for the user to enter additional input when extracting to variable y because there was already prior input in the input buffer that could be used.

+ std::cin is buffered because it allows us to separate the entering of input from the extract of input. We can enter input once and then perform multiple extraction requests on it.
------------------------------------------
THE BASIC EXTRACTION PROCESS
+ Here's a simplified view of how operator >> works for input:
    1. If std::cin is not in a good state (e.g. the prior extraction failed and std::cin has not yet been cleared), no extraction is attempted, and the extraction process aborts immediately.
    2. Leading whitespace characters (spaces, tabs, and newlines at the front of the buffer) are discarded from the input buffer. This will discard an unextracted newline character remaining from a prior line of input.
    3. If the input buffer is now empty, operator >> will wait for the user to enter more data. Any leading whitespace is discarded from the entered data.
    4. Operator >> then extracts as many consecutive characters as it can, until it encounters either a newline character (representing the end of the line of input) or a character that is not valid for the variable being extracted to. 
+ The result of the extraction process is as follows:
    If the extraction aborted in step 1, then no extraction attempt occurred. Nothing else happens.
    If any characters were extracted in step 4 above, extraction is a success. The extracted characters are converted into a value that is then copy-assigned to the variable.
    If no characters could be extracted in step above, extraction has failed. The object being extracted to is copy-assigned the value 0 (as of C++11), and any future extractions will immediately fail (until std::cin is cleared).
+ Any non-extracted characters (including newlines) remain available for the next extraction attempt. 
+ Here is an example for the following snippet:
    int x{};
    std::cin >> x;
→ This is what happens in a three different input cases:
    If the user types 5a and enter, 5a\n will be added to the buffer. 5 will be extracted, converted to an integer, and assigned to variable x. a\n will be left in the input buffer for the next extraction.
    If the user type 'b' and enter, b\n would be added to the buffer. Because b is not a valid integer, no characters can be extracted, so this is an extraction failure. Variable x would be set to 0, and future extractions will fail until the input stream is cleared.
    If std::cin is not in a good state due to a prior failed extraction, nothing happens here. The value of variable x is not altered.
------------------------------------------
OPERATOR << vs OPERATOR >>
+ New programmers often mix up std::cin, std::cout, the insertion operator << and the extraction operator >>. Here's an easy way to remember:
    std::cin and std::cout always go on the left-hand side of the operator
    std::cout is used to output a value (cout == character output)
    std::cin is used to get an input value (cin == character input)
    << is used with std::cout, and shows the direction that data is moving. Ex: std::cout << 4 moves the value 4 to the console.
    >> is used with std::cin, and shows the direction that data is moving. Ex: std::cin >> x moves the value the user entered from the keyboard into variable x.
------------------------------------------
QUIZ TIME
+ Question 1: Consider the following program that we used above:

#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    std::cout << "You entered " << x << '\n';

    return 0;
}
→ The program expects you to enter an integer value, as the variable x that the user input will be put into is an integer variable.
→ Run this program multiple times and describe the output that results when you enter the following types of input:
    a. A letter such as h.
    → Result: 0 is always printed. An integer can't hold a letter, so extraction completely fails. x is assigned the value 0
    
    b. A number with a factional part (e.g. 3.2). Try numbers with factional parts less than 0.5 and greater than 0.5
    → Result: The fractional part is dropped (not rounded). Given the number 3.2, the 3 gets extracted, but . is an invalid character, so extraction stops here. The .2 remains for a future extraction attempt.

    c. A small negative integer, such as -3.
    → Result: The entered number is output. A minus sign at the beginning of a number is acceptable, so it is extracted. The remaining numbers are extracted as well.

    d. A really big number (at lease 3 billion)
    → Result: You are most likely to get the number 2,147,483,647 (without the comma ,). x can only hold numbers up to a certain size. If you enter a value larger than the largest number x can hold, it will be set to the largest number that x can hold (which probably 2,147,483,647 but might be different on your system).

    e. A small number followed by some letters, such as 123abc.
    → Result: The numeric values are printed (e.g. 123). 123 is extracted, the remaining characters (e.g. abc) are left for a later extraction.

    f. A few letters followed by a small number, such as abc123
    → Result: 0 is always printed. An integer can't hold a letter, so extraction completely fails. x is assigned the value 

    g. +5 (three spaces, followed by a plus symbol, and a 5)
    → Result: 5 is printed. The leading whitespace is skipped. Plus is a valid symbol at the start of a number (just as a minus sign would be), so it is extracted. The 5 is also extracted.

    h. 5b6
    → Result: 5 is printed. 5 is extracted. b is invalid, so extraction stops here. The b6 remains for a future extraction attempt.
+ Question 2: Ask the user to enter three values. The program should then print these value. Add an appropriate comment above function main(). The program should match the following output (when run with input values 4, 5, and 6):
Enter three numbers: 4 5 6
You entered 4, 5, and 6.
    → Answer:
#include <iostream>

// Ask the user to enter three values and then print those values as a sentence.
int main()
{
    std::cout << "Enter three numbers: ";

    int first{}, second{}, third{};
    std::cin >> first >> second >> third;

    std::cout << "You entered " << first << ", " << second << ", and " << third << ".\n";

    return 0;
}
*/