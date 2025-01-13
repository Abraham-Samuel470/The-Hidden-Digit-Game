#include <iostream>
#include <cstdlib>
#include <ctime>

void printIntroduction() {
    std::cout << "=====================================\n";
    std::cout << " Welcome to the Guess the Number Game \n";
    std::cout << "=====================================\n";
}

void printDifficultyLevels() {
    std::cout << "Select Difficulty Level:\n";
    std::cout << "1. Easy (1 to 50, 10 attempts)\n";
    std::cout << "2. Medium (1 to 100, 7 attempts)\n";
    std::cout << "3. Hard (1 to 200, 5 attempts)\n";
    std::cout << "Enter your choice (1-3): ";
}

void setDifficulty(int choice, int &maxNumber, int &maxAttempts) {
    switch (choice) {
        case 1:
            maxNumber = 50;
            maxAttempts = 10;
            break;
        case 2:
            maxNumber = 100;
            maxAttempts = 7;
            break;
        case 3:
            maxNumber = 200;
            maxAttempts = 5;
            break;
        default:
            std::cout << "Invalid choice. Defaulting to Easy level.\n";
            maxNumber = 50;
            maxAttempts = 10;
            break;
    }
}

int generateRandomNumber(int maxNumber) {
    return rand() % maxNumber + 1;
}

void playGame(int maxNumber, int maxAttempts) {
    int targetNumber = generateRandomNumber(maxNumber);
    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;

    std::cout << "I have selected a number between 1 and " << maxNumber << ".\n";
    std::cout << "You have " << maxAttempts << " attempts to guess it.\n";

    while (attempts < maxAttempts && !guessedCorrectly) {
        std::cout << "Attempt " << (attempts + 1) << ": Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < targetNumber) {
            std::cout << "Too low!\n";
        } else if (guess > targetNumber) {
            std::cout << "Too high!\n";
        } else {
            guessedCorrectly = true;
            std::cout << "Congratulations! You've guessed the number in " << attempts << " attempts.\n";
            std::cout << "Your score: " << (maxAttempts - attempts + 1) * 10 << "\n";
        }
    }

    if (!guessedCorrectly) {
        std::cout << "Sorry, you've used all your attempts. The number was " << targetNumber << ".\n";
    }
}

bool askToPlayAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    bool playAgain = true;

    while (playAgain) {
        printIntroduction();
        printDifficultyLevels();

        int choice;
        std::cin >> choice;

        int maxNumber, maxAttempts;
        setDifficulty(choice, maxNumber, maxAttempts);

        playGame(maxNumber, maxAttempts);
        playAgain = askToPlayAgain();
    }

    std::cout << "Thank you for playing! Goodbye.\n";
    return 0;
}
