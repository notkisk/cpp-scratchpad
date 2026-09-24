#include <iostream>

namespace Color {
enum Color : unsigned int { red, green, blue };
}
namespace Days_Space {
enum Days : long {
  saturday = 1,
  sunday = 2,
  monday = 3,
  tuesday = 4,
  wednesday = 5,
  thursday = 6,
  friday = 7,
  doomsday = 99,
  divorceday

};
}
namespace Feeling {
enum Feeling { happy, tired, blue };
}

namespace Monster {
enum MonesterType : unsigned short {
  orc = 0,
  goblin,
  troll,
  ogre,
  skeleton,
};
}

int main() {
  using namespace Days_Space;
  using namespace Monster;
  [[maybe_unused]] MonesterType monster{MonesterType::troll};
  Days days{divorceday};

  // what will divorceday print?
  std::cout << days << '\n';
  std::cin.get();
  return 0;
}
