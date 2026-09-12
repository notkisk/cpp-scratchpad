#include "/home/nnul/Projects/cpp-scratchpad/learncpp.com/chapter8/Random.h"
#include <cstdint>
#include <cstdlib>
#include <format>
#include <iostream>
#include <limits>
#include <tuple>

void ignoreExtraneousCharacters() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::tuple<std::int32_t, std::int32_t, std::int32_t>
switchOnDifficulty(std::int32_t difficulty) {
  switch (difficulty) {
  case 1:
    // Easy
    return {1, 50, 10};

  case 2:
    // Normal
    return {1, 100, 7};

  case 3:
    // Hard
    return {1, 200, 5};

  default:
    return {1, 100, 7};
  }
}

std::tuple<std::int32_t, std::int32_t, std::int32_t> setupGame() {
  // Keep the previous difficulty between games.
  static std::int32_t difficulty{2};

  std::cout << "Welcome to our Number Guessing Game!\n";
  std::cout << "Would you like to setup the game? (y/n): ";

  while (true) {
    char answer{};
    std::cin >> answer;

    if (!std::cin) {
      if (std::cin.eof())
        std::exit(0);

      std::cin.clear();
      ignoreExtraneousCharacters();

      std::cout << "Please enter 'y' or 'n': ";
      continue;
    }

    // Reject things like "yes", "y123", etc.
    if (std::cin.peek() != '\n') {
      ignoreExtraneousCharacters();

      std::cout << "Please enter only 'y' or 'n': ";
      continue;
    }

    ignoreExtraneousCharacters();

    switch (answer) {
    case 'y': {
      while (true) {
        std::cout << "Please Choose Difficulty (1 for Easy, 2 for Normal, 3 "
                     "for Hard): ";

        std::cin >> difficulty;

        if (!std::cin) {
          if (std::cin.eof())
            std::exit(0);

          std::cin.clear();
          ignoreExtraneousCharacters();

          std::cout << "Please enter only 1, 2, or 3.\n";
          continue;
        }

        // Reject things like "1x" or "2abc".
        if (std::cin.peek() != '\n') {
          ignoreExtraneousCharacters();

          std::cout << "Please choose 1, 2, or 3.\n";
          continue;
        }

        ignoreExtraneousCharacters();
        if (difficulty < 1 || difficulty > 3) {
          std::cout << "Please choose 1, 2, or 3.\n";
          continue;
        }

        return switchOnDifficulty(difficulty);
      }
    }

    case 'n':
      // Keep the previous difficulty.
      return switchOnDifficulty(difficulty);

    default:
      std::cout << "Please enter 'y' or 'n': ";
      break;
    }
  }
}

int computerGuess(auto min, auto max) { return Random::get(min, max); }

bool checkGuess(std::int32_t guess, std::int32_t computerGuess,
                std::int32_t min, std::int32_t max) {
  if (guess == computerGuess) {
    std::cout << "Correct! You win!\n";
    return true;
  }

  if (guess > computerGuess)
    std::cout << "Your guess is too high.\n";
  else
    std::cout << "Your guess is too low.\n";

  return false;
}

std::int32_t makeAGuess(std::int32_t min, std::int32_t max) {
  while (true) {
    std::int32_t guess{};

    std::cin >> guess;

    if (!std::cin) {
      if (std::cin.eof())
        std::exit(0);

      std::cin.clear();
      ignoreExtraneousCharacters();

      std::cout << "Please enter a valid number: ";
      continue;
    }

    // Reject things like 43x.
    if (std::cin.peek() != '\n') {
      ignoreExtraneousCharacters();

      std::cout << "Please enter only a number: ";
      continue;
    }

    ignoreExtraneousCharacters();

    // Check bounds.
    if (guess < min || guess > max) {
      std::cout << std::format("Please enter a number between {} and {}: ", min,
                               max);
      continue;
    }

    return guess;
  }
}

char getPlayAgain() {
  while (true) {
    char answer{};
    std::cin >> answer;

    if (!std::cin) {
      if (std::cin.eof())
        std::exit(0);

      std::cin.clear();
      ignoreExtraneousCharacters();

      std::cout << "Please enter 'y' or 'n': ";
      continue;
    }

    // Reject things like "yes" or "yx".
    if (std::cin.peek() != '\n') {
      ignoreExtraneousCharacters();

      std::cout << "Please enter only 'y' or 'n': ";
      continue;
    }

    ignoreExtraneousCharacters();

    if (answer == 'y' || answer == 'n')
      return answer;

    std::cout << "Please enter 'y' or 'n': ";
  }
}

int main() {
  char playAgain{'y'};

  while (playAgain == 'y') {
    // Setup the game.
    const auto [min, max, nTries] = setupGame();

    const int computerGuessedNumber{computerGuess(min, max)};

    std::cout << std::format("\nI'm thinking of a number between {} and {}.\n"
                             "You have {} tries to guess what it is.\n\n",
                             min, max, nTries);

    bool won{false};

    for (std::int32_t tries{1}; tries <= nTries; ++tries) {
      std::cout << std::format("Guess #{}: ", tries);

      const std::int32_t guess{makeAGuess(min, max)};

      if (checkGuess(guess, computerGuessedNumber, min, max)) {
        won = true;
        break;
      }
    }

    if (!won) {
      std::cout << std::format("Sorry, you lose. The correct number was {}.\n",
                               computerGuessedNumber);
    }

    std::cout << "\nWould you like to play again (y/n)? ";

    playAgain = getPlayAgain();

    std::cout << '\n';
  }

  std::cout << "Thank you for playing.\n";

  return 0;
}
