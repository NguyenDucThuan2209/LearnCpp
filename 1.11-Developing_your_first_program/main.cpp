/*
------------------------------------------
+ The preceding lessons have introduced a lot of terminology and concepts that we'll use in just about every program we create. In this lesson, we'll walk through the process of integrating this knowledge into our first simple program.
------------------------------------------
MULTIPLY BY 2
+ First, let's create a program that asks the user to enter an integer, waits for them to input an integer, then tells them what 2 times that number is.
+ Best practice: New programmers often try to write an entire program all at once, and then get overwhelmed when it produces a lot of errors. A better strategy is to add one piece at a time, make sure it compiles, and test it. Then when you're sure it's working, move on to the next piece.
------------------------------------------
AUTHOR'S NOTE
+ The first and primary goal of programming is to make your program work. A program that doesn't work isn't useful regardless how well it's written.
+ However, there's a saying I'm fond of: "You have to write a program once to know how you should have written it the first time.". This speaks to the fact that the best solution often isn't obvious, and that our first solutions to problems are usually not as good as they could be.
+ When we're focused on figuring out how to make our programs work, it doesn't make a lot of sense to invest a lot of time into code we don't even know if we'll keep. So we take shortcuts. We skip things like error handling and comments. We sprinkle debugging code throughout our solution to help us diagnose issues and find errors. We learn as we go -- things we thought might work don't work after all, and we have to backtrack and try another approach.
+ The end result is that our initial solutions often aren't well structured, robust (error-proof), readable, or concise. So once your program is working, your job really isn't done (unless the program is a one-off/throwaway). The next step is to cleanup your code. This involves things like: removing (or commenting out) temporary/debugging code, adding comments, handling error cases, formatting your code, and ensuring best practices are followed. And even then, your program may not be as simple as it could be -- perhaps there is redundant logic that can be consolidated, or multiple statements that can be combined, or variables that aren't needed, or a thousand other little things that could be simplified. Too often new programmers focus on optimizing for performance when they should be optimizing for maintainability.
+ Very few of the solutions presented in these tutorials came out great the first time. Rather, they're the result of continual refinement until nothing else could be found to improve. And in many cases, readers still find plenty of other things to suggest as improvements!
+ All of this really to say: don't be frustrated if/when your solutions don't come out wonderfully optimized right out of your brain. That's normal. Perfection ion programming is an iterative process (one requiring repeated passes).
+ You may be thinking, "C++ has so many rules and concepts. How do I remember all of this stuff?". Short answer: You don't. C++ is one part using what you know, and two parts looking up how to do the rest.
+ As you read through this site for the first time, focus less on memorizing specifics, and more on understanding what's possible. Then, when you have a need to implement something in a program you're writing, you can come back here (or to a reference site) and refresh yourself on how to do so.
*/
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    
    int number{};
    std::cin >> number;

    std::cout << "Double of " << number << " is " << number * 2 << '\n';
    std::cout << "Triple of " << number << " is " << number * 3 << '\n';

    return 0;
}