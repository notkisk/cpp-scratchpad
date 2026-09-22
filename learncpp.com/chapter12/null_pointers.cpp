#include <iostream>
#include <optional>
template <typename T> constexpr std::optional<T> safe_dereference(T *ptr) {
  if (ptr == nullptr)
    return {};
  return *ptr;
}
int main() {
  int *ptr{}; // Create a null pointer
  std::cout << ptr << '\n';
  // std::cout << *ptr << '\n'; // Dereference the null pointer
  const int *const id =
      nullptr; // const pointer to a const int, so it points to a const int and
               // the pointer is also constant so both value and the pointer
               // won't change their value
  std::string string{
      "hello, world! this is haithem calling you from the 3rd world!"};
  std::cout << string.size() << '\n';
  int x{5};
  int &y = x;
  int z{};
  y = z; // this does not bind the reference to z instead it just assigns the
         // value of z to x, so now x = 0;
  const int &w = z;
  return 0;
}
