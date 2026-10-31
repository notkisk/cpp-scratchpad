#include <iostream>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(std::vector<T> &v) {
  // static_assert(v.size() > 0);
  std::size_t min_index{0};
  std::size_t max_index{0};

  for (std::size_t index{0}; index < v.size(); ++index) {
    if (v[index] < v[min_index])
      min_index = index;
    if (v[index] > v[max_index])
      max_index = index;
  }
  return {min_index, max_index};
}

template <typename T> void printArray(const std::vector<T> &v) {
  // static_assert(v.size() != 0);
  bool comma{false};
  std::cout << "With array ( ";
  for (const auto &e : v) {
    if (comma)
      std::cout << ", ";
    std::cout << e;
    comma = true;
  }
  std::cout << " ):\n";
}

int main() {
  std::vector v1{3, 8, 2, 5, 7, 8, 3};
  printArray(v1);

  auto m1{findMinMaxIndices(v1)};
  std::cout << "The min element has index " << m1.first << " and value "
            << v1[m1.first] << '\n';
  std::cout << "The max element has index " << m1.second << " and value "
            << v1[m1.second] << '\n';

  std::cout << '\n';

  std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};
  printArray(v2);

  auto m2{findMinMaxIndices(v2)};
  std::cout << "The min element has index " << m2.first << " and value "
            << v2[m2.first] << '\n';
  std::cout << "The max element has index " << m2.second << " and value "
            << v2[m2.second] << '\n';

  return 0;
  std::cin.get();
  return 0;
}
