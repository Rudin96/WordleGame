#include "game.h"
void Game::NewGame()
{
    initRandomWordFromFile();
    attempts = 0;
    handleUserInput();
}

bool Game::compareGuessWithSecret(string& guess)
{
    size_t wordFindPos = secretWord.find(guess);
    if (wordFindPos != std::string::npos)
    {
        std::cout << FOREGROUND(ForegroundColor::Green, guess) << std::endl;
        return true;
    }
    else {
        for (size_t i = 0; i < secretWord.length(); i++)
        {
            size_t charFindPos = secretWord.find(secretWord[i]);
            if (charFindPos != std::string::npos && secretWord[i] != guess[i])
            {
                std::cout << FOREGROUND(ForegroundColor::Yellow, guess[i]);
            }
            else if (guess[i] == secretWord[i]) {
                std::cout << FOREGROUND(ForegroundColor::Green, guess[i]);
            }
            else if (charFindPos == std::string::npos) {
                std::cout << guess[i];
            }
        }
        std::cout << std::endl;
        attempts++;
        return false;
    }
}

void Game::handleUserInput()
{
    string inputRaw;
    std::cout << secretWord << std::endl;
    std::cin >> inputRaw;
    for (size_t i = 0; i < inputRaw.size(); i++)
    {
        inputRaw[i] = std::toupper(inputRaw[i]);
    }
    if (attempts > 5)
        handleEndOfGame();
    if (inputRaw.size() != 5)
    {
        std::cout << "You can only guess on words with 5 characters!, try again!" << std::endl;
        handleUserInput();
        return;
    }
    if (compareGuessWithSecret(inputRaw))
    {
        std::cout << "Congrats, u guessed correctly!" << std::endl;
        handleEndOfGame();
    }
    else {
        std::cout << "Wrong guess, please try again; " << "Attempt: " << attempts << " of " << 6 << std::endl;
        handleUserInput();
    }
}

void Game::initRandomWordFromFile()
{
    std::vector<string> words = FileManager::ReadAllLines("words.txt");
    srand(time(NULL));
    int random = rand() % words.size() + 1;
    secretWord = words.at(random);
    std::cout << "Guess the word" << std::endl;
};

void Game::handleEndOfGame()
{
    std::cout << "Correct word was " << secretWord << std::endl;
    char input;
    std::cout << "Would you like to try again? [y/n]" << std::endl;
    std::cin >> input;
	if (std::tolower(input) == 'y')
		NewGame();
	if (std::tolower(input) == 'n')
		exit(0);
	if (std::cin.fail())
		handleEndOfGame();
}