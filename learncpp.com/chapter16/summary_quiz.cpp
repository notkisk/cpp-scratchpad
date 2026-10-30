#include <cassert>
#include <iostream>
#include <string_view>
#include <type_traits>
#include <vector>

namespace Items {
enum Type : int { health_potion, torch, arrow, max_items };
}

std::string_view getItemNamePlural(Items::Type type) {
  switch (type) {
  case Items::health_potion:
    return "health potions";
  case Items::torch:
    return "torches";
  case Items::arrow:
    return "arrows";

  default:
    return "???";
  }
}

std::string_view getItemNameSingular(Items::Type type) {
  switch (type) {
  case Items::health_potion:
    return "health potion";
  case Items::torch:
    return "torch";
  case Items::arrow:
    return "arrow";

  default:
    return "???";
  }
}

template <typename T> constexpr std::size_t toUZ(T value) {
  static_assert(std::is_integral<T>() || std::is_enum<T>());

  return static_cast<std::size_t>(value);
}

void printInventoryItem(const std::vector<int> &inventory, Items::Type type) {
  bool plural{inventory[toUZ(type)] != 1};
  std::cout << "You have " << inventory[toUZ(type)] << ' ';
  std::cout << (plural ? getItemNamePlural(type) : getItemNameSingular(type))
            << '\n';
}

int countTotalItems(const std::vector<int> &inventory) {
  int sum{0};
  for (auto e : inventory)
    sum += e;
  return sum;
}

int main() {
  std::vector inventory{1, 5, 10};
  assert(std::size(inventory) == Items::max_items);

  for (int i = 0; i < Items::max_items; ++i) {
    auto item{static_cast<Items::Type>(i)};
    printInventoryItem(inventory, item);
  }

  std::cout << "You have " << countTotalItems(inventory) << " total items\n";

  return 0;
}
