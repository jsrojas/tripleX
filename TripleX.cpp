#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
            // Welcome lines to the game in the CLI
    std::cout << "\n \nYou are jewelry robber and you are trying to break into a series of secured vaults to steal an amazing diamond.";
    std::cout << "\n";
    std::cout << "You need to enter the correct codes to open the level " << Difficulty << " vault and move to the next vault... "<< "\n";
    std::cout << " _____________________________";
    std::cout << "\n/        _____________        \\ ";
    std::cout << "\n| == . |             |        |";
    std::cout << "\n|   _  |             |        |";
    std::cout << "\n|  / \\ |             |        |";
    std::cout << "\n| | O ||             |        |";
    std::cout << "\n|  \\_/ |             |        |";
    std::cout << "\n|      |             | . . .  |";
    std::cout << "\n|  ::: |             | . . .  |";
    std::cout << "\n|  ::: |_____________| . . .  |";
    std::cout << "\n|        V A U L T " << Difficulty << "          |";
    std::cout << "\n\\_____________________________/";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Declaring the correct numbers to win the game
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;
    
    // To make it eaisier
    //int CodeC = rand() % Difficulty + 1;

    // Declaring and calculating the sum and product of the numbers to offer the hints
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;
    
    // Printing the variables resulting from the operations
    std::cout << "\n";
    std::cout << "+ There are three numbers in the code\n";
    std::cout << "+ The code adds up to: " << CodeSum << "\n";
    std::cout << "+ The code multiplication is: "<< CodeProduct << "\n";

    // Declaring the variables to store player guess numbers
    int GuessA, GuessB, GuessC;

    // Storing player guess
    std::cout << "\n" << "Please enter your guess code of three numbers that will open the vault: "<< "\n"; 
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "Your three numbers are: "<< "\n" << GuessA << "\n" << GuessB << "\n" << GuessC << "\n"; 
    
    // Creating and calculating the sum and product of the player guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Checking if player guess is right or not
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "That's the right code!...YOU CAN MOVE TO THE NEXT VAULT!" << "\n";
        return true; 
    }
    else 
    {
        std::cout << "Wrong code, CAREFUL!...PLEASE TRY AGAIN";
        return false;
    }
}

// This is the main function of the game
int main() 
{
    srand(time(NULL)); // Create new random sequence based on time of day
    int LevelDiffculty = 1;
    int const MaxDifficulty = 5;

    while (LevelDiffculty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDiffculty);
        // clear any errors
        std::cin.clear();
        // Discard the buffer   
        std::cin.ignore();

        if (bLevelComplete)
        {
            // increase level difficulty
            ++LevelDiffculty;
        }
    }
    std::cout << "YOU HAVE PASSED ALL THE VAULTS AND STOLE THE DIAMOND!!...TIME TO ESCAPE!!" << "\nYOU WIN!";
    return 0;
}