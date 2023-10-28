#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // It will Generate a random number between 1 and 100 (you can adjust the range as needed)
    int random_number = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100. Try to guess it!" << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < random_number) {
            std::cout << "Too low! Try a higher number." << std::endl;
        } else if (guess > random_number) {
            std::cout << "Too high! Try a lower number." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number " << random_number << " in " << attempts << " attempts." << std::endl;
            break;
        }
    }

    return 0;
}