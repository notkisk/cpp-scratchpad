#include <iostream>
#include <ranges>
#include <string_view>
#include <vector>

int main() {
  std::vector fib{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  for (int num : fib)
    std::cout << num << ' ';
  std::cout << '\n';

  // in cases where the container is empty, range based for loop body won't
  // excute!
  std::vector empty{};
  for (int num : empty)
    std::cout << "Hi mom what you think?\n";

  for (auto num : fib)
    std::cout << num << ' ';
  std::vector<std::string_view> words{"Alex", "Bobby", "Chad", "Dave"};

  for (const auto &word : std::views::reverse(words))
    std::cout << word << ' ';
  std::cout << '\n';
  std::cin.get();
  return 0;
}
