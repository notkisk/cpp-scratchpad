#include <iostream>

class Accumulator {
private:
  int m_value{0};

public:
  void add(int value) { m_value += value; }
  //
  friend void print(const Accumulator &accumulator);
};

void print(const Accumulator &accumulator) { std::cout << accumulator.m_value; }

class Value {
private:
  int m_value{};

public:
  explicit Value(int v) : m_value{v} {}

  bool isEqualToMember(const Value &v) const;
  friend bool isEqualToNonmember(const Value &v1, const Value &v2);
};

bool Value::isEqualToMember(const Value &v) const {
  return m_value == v.m_value;
}

bool isEqualToNonmember(const Value &v1, const Value &v2) {
  return v1.m_value == v2.m_value;
}

int main() {

  Value v1{5};
  Value v2{6};

  std::cout << v1.isEqualToMember(v2) << '\n';
  std::cout << isEqualToNonmember(v1, v2) << '\n';
  Accumulator acc{};
  // because print is a friend function, it can access accumulator private and
  // protected members usually if we did not mark print as a friend, passing
  // that const reference won't give you access to private and protected
  // members!
  acc.add(5);

  print(acc);

  std::cin.get();
  return 0;
}
