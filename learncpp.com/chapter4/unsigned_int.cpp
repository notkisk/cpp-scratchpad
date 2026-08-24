#include <iostream>
#include <cstdint>
#include <iomanip>


int main(){
  int8_t something {-10};
  uint8_t somethingelse{65};
  std::cout <<std::setw(30) <<"the size of uint8_t: "<< sizeof(somethingelse)<<(std::uint16_t) somethingelse << "\n";
  signed int s { -1};
  unsigned int u {1};
  unsigned int w {2};
  signed int z{3};

  std::cout << w - s << "\n"; // you might expect w - s (2-3) to be -1, but thats not the case bukaroo, first of all, that signed will be implicitly casted to unsigned which is  okay(wont change the value of s) but since 2-3 is -1,
  // negtive values are represented in 2's compliment,'
  if (s < u) // you migh expect so to be less than u, but thats wrong! 
    std::cout << "-1 is less than 1\n"; //s will be implicitly converted to an unsigned integre, since -1 in 2's compliment is 32 bit of 1's, this will become basically 2^32 which is u-max(unsigned max) which is 4294967295
    //and 4294967295 < 1 is false! 
  else
   std::cout << "1 is less than -1\n"; // thos statement excutes
  std::cin.get();
  return 0;
}
