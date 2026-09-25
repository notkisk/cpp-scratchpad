#include <iostream>
#include <string_view>

enum class Animal {
  pig,
  chicken,
  goat,
  cat,
  dog,
  duck,
};

constexpr std::string_view getAnimalName(Animal animal) {
  using enum Animal;
  switch (animal) {
  case chicken:
    return "chicken";
  case duck:
    return "duck";
  case pig:
    return "pig";
  case cat:
    return "cat";
  case dog:
    return "dog";
  case goat:
    return "goat";

  default:
    return "???";
  }
}

void printNumberOfLegs(Animal animal) {
  using enum Animal;
  std::cout << "A " << getAnimalName(animal) << " has ";
  switch (animal) {
  case chicken:
  case duck:
    std::cout << 2;
    break;
  case pig:
  case dog:
  case cat:
  case goat:
    std::cout << 4;
    break;
  default:
    std::cout << "???";
    break;
  }
  std::cout << " legs.\n";
}

int main() {
  using enum Animal;
  printNumberOfLegs(cat);
  printNumberOfLegs(chicken);

  std::cin.get();
  return 0;
}
