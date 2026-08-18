#include <iostream> // for std::cout and std::cin

// basic.cpp - your first program!
int main()
{
    // print some text to the console
    std::cout << "Hello, world!\n";

    // ask the user for their name
    std::cout << "What's your name? ";
    std::string name{};
    std::cin >> name;

    // greet them back
    std::cout << "Nice to meet you, " << name << "!\n";

    return 0; // 0 means the program ran successfully
}
