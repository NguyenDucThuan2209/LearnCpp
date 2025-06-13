/*
------------------------------------------
+ The preceding lessons have introduced a lot of terminology and concepts that we'll use in just about every program we create. In this lesson, we'll walk through the process of integrating this knowledge into our first simple program.
------------------------------------------
MULTIPLY BY 2
+ First, let's create a program that asks the user to enter an integer, waits for them to input an integer, then tells them what 2 times that number is.
+ Best practice: New programmers often try to write an entire program all at once, and then get overwhelmed when it produces a lot of errors. A better strategy is to add one piece at a time, make sure it compiles, and test it. Then when you're sure it's working, move on to the next piece.
*/
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    
    int number{};
    std::cin >> number;

    std::cout << "Double of " << number << " is " << number * 2;

    return 0;
}