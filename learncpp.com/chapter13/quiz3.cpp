#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>

namespace DS {
struct Fraction {
  std::int32_t numerator{};
  std::int32_t denominator{};
};
} // namespace DS

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool checkCin() {
  if (!std::cin) {
    if (std::cin.eof()) {
      std::exit(0);
    }

    std::cin.clear();
    ignoreLine();
    return false;
  }

  return true;
}

DS::Fraction getFraction() {
  using namespace DS;
  Fraction fraction{};

  while (true) {
    std::cout << "Enter a value for the numerator: ";
    std::cin >> fraction.numerator;

    if (checkCin())
      break;

    std::cout << "Invalid input. Try again.\n";
  }

  while (true) {
    std::cout << "Enter a value for the denominator: ";
    std::cin >> fraction.denominator;

    if (!checkCin()) {
      std::cout << "Invalid input. Try again.\n";
      continue;
    }

    if (fraction.denominator == 0) {
      std::cout << "Denominator cannot be 0. Try again.\n";
      continue;
    }

    break;
  }

  return fraction;
}

constexpr DS::Fraction multiply(const DS::Fraction &f1,
                                const DS::Fraction &f2) {
  assert(f1.denominator != 0 && f2.denominator != 0 &&
         "Denominator can't be 0");

  return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

std::ostream &operator<<(std::ostream &out, const DS::Fraction &f) {
  return out << f.numerator << '/' << f.denominator;
}
int main() {
  using namespace DS;

  Fraction f1{getFraction()};
  Fraction f2{getFraction()};

  std::cout << "Your fraction multiplied together: " << multiply(f1, f2);

  return 0;
}
