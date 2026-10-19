#include <iostream>
#include <vector>

int main() {

  std::vector<int> empty{};
  std::vector<double> something{1.5, 5.5};
  std::vector ones(5, 1);
  std::vector<int> zeroes(10);

  std::vector<int>::size_type something_else{};
  auto a = something.size();      // this returns the size of the vector as an
                                  // unsigned size_type (C++98)
  auto b = std::size(something);  // this also returns the size of the vector as
                                  // an unsined size_type (C++17)
  auto c = std::ssize(something); // this returns the size of the vector but as
                                  // a signed integer type (C++20)
  // accesing elements with [] vs .at()
  // [] does not perform bound checking, so an invalid index will cause
  // undefined behaviour vec.at(index) checks bounds at runtime and throws an
  // std::out_of_range if the index is invalid, if the exception isn't handled
  // the program terminates.
  //
  std::vector prime{2, 3, 5, 7, 11};

  prime[3];    // Valid: 7
  prime[9];    // Undefined behavior
  prime.at(3); // Valid: 7
  prime.at(9); // Throws std::out_of_range
  int index{3};
  std::cout << prime.data()[index] << '\n';
  std::cin.get();
  return 0;
}
