//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Danny Gillies on 6/14/16.
//  Copyright © 2016 Danny Gillies. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame()
{
    Reset();
}

void FBullCowGame::Reset()
{
    MyCurrentTry = 1;
    MyMaxTries = 3;
    const FString HIDDEN_WORD = "dick";
    MyHiddenWord = HIDDEN_WORD;
    return;
}

int FBullCowGame::GetMaxTries() const
{
    return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}

bool FBullCowGame::IsGuessValid(FString Guess) const
{
    return false;
}

// receives a valid guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment the turn number
    MyCurrentTry++;
    
    // set up return variable
    FBullCowCount BullCowCount;
    
    // loop through all letters in the guess
    for (int32 i = 0; i < MyHiddenWord.length(); i++)
    {
        // compare letters against the hidden word
        for (int32 j = 0; j < MyHiddenWord.length(); j++)
        {
            // if they match then
            if (Guess[i] == MyHiddenWord[j])
            {
                // increment bulls if they're in the same place
                if (i == j)
                {
                    BullCowCount.Bulls++;
                }
                // increment cows if not
                else
                {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
    return (int32) MyHiddenWord.length();
    
}