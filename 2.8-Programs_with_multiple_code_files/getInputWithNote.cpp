#include <string>
#include <iostream>

int getInputWithNote(std::string content)
{
    int input{};

    std::cout << content;
    std::cin >> input;

    return input;
}