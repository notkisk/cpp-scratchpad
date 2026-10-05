#include <iostream>

class Dollars {
private:
  int m_dollars{};

public:
  Dollars() {}            // this should not be marked as explicit
  explicit Dollars(int d) // now explicit
      : m_dollars{d} {}

  Dollars(const Dollars &d)
      : m_dollars{d.m_dollars} {
  } // copy constructors must not be marked as explicit as they don't perform an
    // implicit conversion

  int getDollars() const { return m_dollars; }
};

void print(Dollars d) { std::cout << "$" << d.getDollars(); }

int main() {
  print(5);          // compilation error because Dollars(int) is explicit
  print(Dollars{5}); // this is okay
  return 0;
}
