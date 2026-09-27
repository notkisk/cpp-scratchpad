#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>

namespace Enemies {
enum class MonsterType : std::int16_t {
  ogre,
  dragon,
  orc,
  giant_spider,
  slime
};

struct Monster {
  const MonsterType type;
  const std::string name;
  double health{};
};

} // namespace Enemies
constexpr std::string_view
enum_to_string(const Enemies::MonsterType monster_type) {
  using namespace Enemies;
  switch (monster_type) {
  case MonsterType::ogre:
    return "Ogre";
  case MonsterType::dragon:
    return "Dragon";
  case MonsterType::orc:
    return "Orc";
  case MonsterType::giant_spider:
    return "Giant Spider";
  case MonsterType::slime:
    return "Slime";
  default:
    return "???";
  }
}
std::ostream &operator<<(std::ostream &out, const Enemies::Monster &monster) {
  return out << "The " << enum_to_string(monster.type) << " is named "
             << monster.name << " and has " << monster.health << " health.\n";
}
int main() {
  using namespace Enemies;
  Monster torg{.type = MonsterType::ogre, .name = "Torg", .health = 145};
  Monster blurp{.type = MonsterType::slime, .name = "Blurp", .health = 23};

  std::cout << torg;
  std::cout << blurp;
  std::cin.get();
  return 0;
}
