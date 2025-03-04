#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // Seed the random number generator
    int randomNumber = std::rand() % 100 + 1; // Generate a number between 1 and 100
    int userGuess = 0;

    std::cout << "I have generated a number between 1 and 100. Try to guess it!" << std::endl;
    
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        
        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            break;
        }
    }
    
    return 0;
}

