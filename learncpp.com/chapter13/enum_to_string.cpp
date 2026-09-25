#include <cstdint>
#include <ios>
#include <iostream>
#include <istream>
#include <limits>
#include <optional>
#include <ostream>
#include <string_view>

namespace Animals {
enum Pet : std::int16_t { cat, dog, pig, whale, sandfish };
}

constexpr std::string_view enum_to_str(Animals::Pet pet) {
  using namespace Animals;
  switch (pet) {
  case dog:
    return "dog";
  case cat:
    return "cat";
  case pig:
    return "pig";
  case whale:
    return "whale";
  case sandfish:
    return "sandfish";
  default:
    return "???";
  }
}

constexpr std::optional<Animals::Pet> str_to_enum(const std::string_view &sv) {
  using namespace Animals;
  if (sv == "cat")
    return cat;
  if (sv == "dog")
    return dog;
  if (sv == "pig")
    return pig;
  if (sv == "whale")
    return whale;
  if (sv == "sandfish")
    return sandfish;

  return {};
}

std::ostream &operator<<(std::ostream &out, std::optional<Animals::Pet> pet) {
  if (pet.has_value())
    return out << enum_to_str(pet.value());
  return out;
}

std::istream &operator>>(std::istream &in, Animals::Pet &pet) {
  std::string s{};
  in >> s;
  std::optional<Animals::Pet> match{str_to_enum(s)};
  if (match) { // we check if match has a value, if yes then return the input
               // stream with the matched pet
    pet = match.value(); // alternativly, since optional act like a pointer, we
                         // can dereference it to get its value like this *match
    return in;
  }
  in.setstate(std::ios::failbit); // if we did not find a matched pet, we set
                                  // the istream state to failbit
  return in;
}
int main() {
  using namespace Animals;
  constexpr std::optional<Animals::Pet> pet = str_to_enum("cat");
  Animals::Pet animaal_pet{Animals::Pet::sandfish};

  std::cout << "Pet is: " << animaal_pet << '\n';
  std::cerr << "Pet is: " << animaal_pet << '\n';
  std::cout << "Enter a pet: cat, dog, pig, whale, or sandfish: ";
  Pet in_pet{};
  std::cin >> in_pet;
  // this checks if last cin attempt was a success, if yes print the intput
  // result
  if (std::cin) {
    std::cout << "You choose: " << in_pet << '\n';
  } else {
    std::cin.clear(); // this resets the input state to default
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // this basically discard any leftover data in the
                           // input buffer untill it encounters \n
    // the first argument given is count, so discard n characters untill you
    // reach n(in this case n is the numleric max of the stream size) or untill
    // you encounter a new line character \n so any future extraction attempt
    // from the buffer works like intended and not get polluted by old data
    //
  }

  if (pet.has_value())
    std::cout << enum_to_str(pet.value()) << '\n';
  std::cin.get();
  return 0;
}
