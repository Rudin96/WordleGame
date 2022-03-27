#include "game.h"
void Game::NewGame()
{
    initRandomWordFromFile();
    attempts = 0;
    handleUserInput();
}

bool Game::compareGuessWithSecret(string& guess)
{
    if (secretWord.find(guess) != string::npos)
    {
        return true;
    }
    for (size_t i = 0; i < guess.size(); i++)
    {
        if (guess[i] == secretWord[i])
        {
            std::cout << FOREGROUND(ForegroundColor::Green, guess[i]);
        }
        else {
            size_t existsForward = secretWord.find(guess[i], i);
            size_t existsBackwards = secretWord.find_last_of(guess[i], i);
            if (existsBackwards == string::npos && existsForward == string::npos)
            {
                std::cout << guess[i];
            }
            else
            {
                std::cout << FOREGROUND(ForegroundColor::Yellow, guess[i]);
            }
        }
    }
    std::cout << std::endl;
    attempts++;
    return false;
}

void Game::handleUserInput()
{
    string inputRaw;
    std::cin >> inputRaw;
    for (size_t i = 0; i < inputRaw.size(); i++)
    {
        inputRaw[i] = std::toupper(inputRaw[i]);
    }
    if (attempts > 6)
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