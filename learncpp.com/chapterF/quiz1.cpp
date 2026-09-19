#include <iostream>
#include <type_traits>

const double getTowerHeight() {
  std::cout << "Enter the height of the tower in meters: ";
  double towerheight{};
  std::cin >> towerheight;
  return towerheight;
}

constexpr double calculateBallHeight(double towerHeight, int seconds) {
  if (std::is_constant_evaluated())
    std::cout << "calculateBallHeight is constexpr\n";
  constexpr double gravity{9.8};

  const double distanceFallen{(gravity * (seconds * seconds)) / 2.0};
  const double currentHeight{towerHeight - distanceFallen};

  return currentHeight;
}

void printBallHeight(double ballHeight, int seconds) {
  if (std::is_constant_evaluated())
    std::cout << "printBallHeight is constexpr \n";

  if (ballHeight > 0.0)
    std::cout << "At " << seconds
              << " seconds, the ball is at height: " << ballHeight
              << " meters\n";
  else
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void printCalculatedBallHeight(double towerHeight, int seconds) {
  if (std::is_constant_evaluated())
    std::cout << "printCalculatedBallHeight is constexpr \n";
  const double ballHeight{calculateBallHeight(towerHeight, seconds)};
  printBallHeight(ballHeight, seconds);
}

int main() {
  const double towerHeight{getTowerHeight()};

  printCalculatedBallHeight(towerHeight, 0);
  printCalculatedBallHeight(towerHeight, 1);
  printCalculatedBallHeight(towerHeight, 2);
  printCalculatedBallHeight(towerHeight, 3);
  printCalculatedBallHeight(towerHeight, 4);
  printCalculatedBallHeight(towerHeight, 5);

  return 0;
}
