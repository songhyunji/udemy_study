// complile : g++ tripleX.cpp -o tripleX
// execute : ./tripleX

// Preprocessor Directive
#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Expression Statements : An expression followed by a semicolon
    // Print welcome messages to the terminal
    std::cout << "\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // variable : "A value that is subject to change"
    // Declaration Statements
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Expression Statements
    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to : " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give : " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
        
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You win! Keep going! ***\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You lose! Try again! ***\n";
        return false;
    }
}

// Main Function
int main() 
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        // Code block executes repeatedly until the condition is not met

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   // Clears any errors
        std::cin.ignore();  // Discards the buffers

        if (bLevelComplete)
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** Congratulations! ***\n";

    // Return Statement
    return 0;
}