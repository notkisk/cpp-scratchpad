#include <iostream>

// so name shadowing is when you declare multiple variables with same identifier but in diffrent scopes
// what happens is the ones in their local scope will shadow or hide the ones in other scopes
int g_value { 5 }; // global variable, it is externaly linked by default


int main()
{
    int g_value { 7 }; // hides the global variable value
    ++g_value; // increments local value, not global value

    --(::g_value); // decrements global value, not local value (parenthesis added for readability)

    std::cout << "local variable g_value: " << g_value << '\n';
    std::cout << "global variable g_value: " << g_value << '\n';

    return 0;
}
