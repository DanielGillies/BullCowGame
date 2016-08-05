//
//  main.cpp
//  BullCowGame
//
//  Created by Danny Gillies on 5/31/16.
//  Copyright © 2016 Danny Gillies. All rights reserved.
//

#include <iostream>
#include <string>
#include "main.h"
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetGuess();
void PrintGuess(FText Guess);
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; // Instantiate a new game

// ENTRY POINT FOR APPLICATION
int main()
{
    bool bWantsToPlayAgain;
    do {
        PrintIntro();
        PlayGame();
        bWantsToPlayAgain = AskToPlayAgain();
    }
    while (bWantsToPlayAgain);
    
    return 0;
}

// ASK FOR A GUESS AND TAKE INPUT
void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    std::cout << MaxTries << std::endl;
    
    for (int32 i = 0; i < MaxTries; i++) {
        FText Guess = GetGuess();
        
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ", Cows = " << BullCowCount.Cows << std::endl;

    }
}

// INTRODUCE THE GAME
void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
    return;
}

// GET A GUESS FROM THE PLAYER
FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    FText Guess = "";
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    getline(std::cin, Guess);
    return Guess;
}

// PRINT THE PLAYER'S GUESS
void PrintGuess(FText Guess) {
    std::cout << Guess << std::endl << std::endl;
    return;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? ";
    FText Response = "";
    getline(std::cin, Response);
    if (Response[0] == 'y' || Response[0] == 'Y')
    {
        return true;
    }
    return false;
}