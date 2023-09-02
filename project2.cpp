#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    // Seed the random number generator with the current time
    
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int userGuess;
    int guessCount = 0;

    std::cout << "Welcome to the Guess the Number game!" << std::endl;
    std::cout << "I've selected a random number between 1 and 100. Try to guess it!" << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        guessCount++;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You've guessed the correct number " << secretNumber << " in " << guessCount << " tries!" << std::endl;
            break;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    return 0;
}
