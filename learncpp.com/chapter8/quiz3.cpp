#include <cstdint>
#include <format>
#include <iostream>
#include "Random.h"

int computer_guess(auto min, auto max)
{
    return Random::get(min, max);
}

bool check_guess(std::int32_t guess, std::int32_t computer_guess, int min, int max)
{
    if (guess < min || guess > max)
    {
        std::cout << std::format(
            "Please enter a valid guess that is in the range ({}, {}).\n",
            min, max
        );
        return false;
    }
    if (guess == computer_guess)
    {
        std::cout << "Correct! You win!\n";
        return true;
    }
    if (guess > computer_guess)
        std::cout << "Your guess is too high.\n";
    else
        std::cout << "Your guess is too low.\n";
    return false;
}

int main()
{
    constexpr std::int16_t min{1};
    constexpr std::int16_t max{100};
    constexpr std::int16_t n_tries{7};
    char play_again{'y'};
    while (play_again == 'y')
    {
        const int computer_guessed_number{computer_guess(min, max)};
        std::cout << std::format(
            "Let's play a game. I'm thinking of a number between {} and {}. "
            "You have {} tries to guess what it is.\n",
            min, max, n_tries
        );
        bool won{false};
        std::int32_t guess{};
        for (int tries{1}; tries <= n_tries; ++tries)
        {
            std::cout << std::format("Guess #{}: ", tries);
            std::cin >> guess;
            if (check_guess(guess, computer_guessed_number, min, max))
            {
                won = true;
                break;
            }
        }
        if (!won)
        {
            std::cout << std::format(
                "Sorry, you lose. The correct number was {}.\n",
                computer_guessed_number
            );
        }
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> play_again;

        while (play_again != 'y' && play_again != 'n')
        {
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> play_again;
        }
    }
    std::cout << "Thank you for playing.\n";
    return 0;
}
