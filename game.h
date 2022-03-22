#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "filemanager.h"

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int {
    Red = 31,
    Green = 32,
    Yellow = 33,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93
};

enum class BackgroundColor : int {
    Red = 41,
    Green = 42,
    Yellow = 43,
    BrightRed = 101,
    BrightGreen = 102,
    BrightYellow = 103
};

using std::string;


class Game
{
private:
    string secretWord;
    int attempts = 0;

public:
    void NewGame();

private:
	void initRandomWordFromFile();
    bool compareGuessWithSecret(string& secret);
    void handleUserInput();
    void handleEndOfGame();
};

