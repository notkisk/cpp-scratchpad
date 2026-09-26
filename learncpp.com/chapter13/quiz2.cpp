#include <cstdlib>
#include <iostream>
#include <limits>

struct Ad {
  int adsShown{};
  double clickThroughRatePercentage{};
  double averageEarningsPerClick{};
};

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkCin() {
  if (!std::cin) {
    if (std::cin.eof())
      std::exit(0);

    std::cin.clear();
    ignoreLine();
    return true;
  }
  return false;
}

Ad getAd() {
  Ad ad{};

  std::cout << "How many ads were shown today? ";
  std::cin >> ad.adsShown;
  checkCin();

  std::cout << "What percentage of ads were clicked on by users? ";
  std::cin >> ad.clickThroughRatePercentage;
  checkCin();

  std::cout << "What was the average earnings per click? ";
  std::cin >> ad.averageEarningsPerClick;
  checkCin();

  return ad;
}

void printAd(const Ad &ad) {
  std::cout << "Number of ads shown: " << ad.adsShown << '\n';
  std::cout << "Click through rate: " << ad.clickThroughRatePercentage << "%\n";
  std::cout << "Average earnings per click: $" << ad.averageEarningsPerClick
            << '\n';

  const double totalEarnings{ad.adsShown *
                             (ad.clickThroughRatePercentage / 100.0) *
                             ad.averageEarningsPerClick};

  std::cout << "Total earnings: $" << totalEarnings << '\n';
}

int main() {
  const Ad ad{getAd()};
  printAd(ad);
}
