#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3);   // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);  // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits<< '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    [[maybe_unused]] constexpr int isHungry { 0 };
    [[maybe_unused]] constexpr int isSad { 1 };
    [[maybe_unused]] constexpr int isMad { 2 };
    [[maybe_unused]] constexpr int isHappy { 3 };
    [[maybe_unused]] constexpr int isLaughing { 4 };
    [[maybe_unused]] constexpr int isAslpeep { 5 };
    [[maybe_unused]] constexpr int isDead { 6 };
    [[maybe_unused]] constexpr int isCrying { 7 };
    
  std::bitset<8> me {0b0000'0101}; // bitset optmize for speed not memory saving, this won't only occupy 8 bits, it will store basically number of bytes equal to rounding up to nearst sizeof(size_t) which is 4 bytes on a 32 bit machine 
  // and 8 bytes on a 64 bit machine, so we don't use it for memory saving but for speed! 
  me.set(isHappy);
  me.reset(isSad);
  me.flip(isLaughing);
  me.reset(isDead);
  me.flip(isAslpeep);
  me.set(isMad);

  std::cout << "All the bits: " << me << '\n';
  std::cout << "I am happy: " << me.test(isHappy) << '\n';
  std::cout << "I am isLaughing: " << me.test(isLaughing) << '\n';

  std::cout << "I am dead: " << me.test(isDead) << '\n';
  std::cout << "I am aspleep: " << me.test(isAslpeep) << '\n';

  std::cout << "size() returns the size of the bitset: " << me.size() << '\n';
  std::cout << "count () returns number of bits that are set to true: " << me.count() << '\n';
  std::cout << "all() returns a boolean indicating weither all bits are set to 1: " << me.all() << '\n';
  std::cout << "any() returns a boolean indicating weither any bits are set to 1: " << me.any() << '\n';
  std::cout << "none() returns a boolean indicating weither all bits are set to 0 or no: " <<me.none() << '\n';

  std::cout << "tms bil5yer 3mt" << '\n';

    return 0;
}
