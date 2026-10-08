#include <iostream>

class Simple {
private:
  int m_id{};

public:
  explicit Simple(int id) : m_id{id} {}

  int getID() const { return m_id; };
  void setID(int id) { m_id = id; };

  void print() const {
    std::cout << m_id;         // implicit use of this const pointer
    std::cout << this->m_id;   // explicit use of this const pointer
    std::cout << (*this).m_id; // same thing as the latter
  }
};
// so basically this is a const pointer to the current object, we can use it
// both implicitly or explicitly
//
//
class Calc {
private:
  int m_value{};

public:
  Calc &add(int value) {
    m_value += value;
    return *this;
  }
  Calc &sub(int value) {
    m_value -= value;
    return *this;
  }
  Calc &mult(int value) {
    m_value *= value;
    return *this;
  }

  int getValue() const { return m_value; }

  void reset() {
    *this = {};
  } // this will basically value initilize the implicit object to a new object
    // constructed using the default object,
};

int main() {
  Simple simple{1};
  simple.setID(2);

  Calc calc{};
  calc.add(5).sub(3).mult(4); // method chaining!

  calc.reset();
  std::cout << calc.getValue() << '\n';
  std::cout << calc.getValue() << '\n';
  simple.print();
  std::cin.get();
  return 0;
}
