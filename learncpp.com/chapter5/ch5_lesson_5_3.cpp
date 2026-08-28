#include <format>
#include <bitset>
#include <iostream>
#include <print>

int main()
{
    int x { 12 };
    std::cout << x << '\n'; // decimal (by default)
    std::cout << std::hex << x << '\n'; // hexadecimal
    std::cout << x << '\n'; // now hexadecimal
    // when using one of these io manipulators like std::hex, the behaviour won't change unless you change it yourself, so the effect of std::hex stays
    // as long as you are still in the scope of the function
    std::cout << std::oct << x << '\n'; // octal
    std::cout << std::dec << x << '\n'; // return to decimal
    std::cout << x << '\n'; // decimal
    // we can also print out binary values, but its a bit diffirent, we have to use std::bitset
    // we can define a variable of type std::bitset and specify how many bits we want to store, we can initiliez bitset with any integral value including 
    // decimal, hex and octal or even binary)
    // std::bitset<8> bin1 {0b1100'0101} this define a variable of type bitset that  is capable of storing 8 bits
    // we can also do something like:
    // std::bitest<8> bin2 {055}; or even std::bitset<16> {0xC5FF}
    std::bitset<8> bin1{0b1100'1111};
    std::bitset<16>bin2{0xC5FA};

    std::cout << bin1<<'\n' << bin2 << '\n';
    std::cout << std::bitset<4>{0b1000} << '\n';
    //we can also utelize the format and print to output binary
    std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
    std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits

    std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, format/print two arguments (same as above) and a newline
    return 0;
}
