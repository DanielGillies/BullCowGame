//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Danny Gillies on 6/14/16.
//  Copyright © 2016 Danny Gillies. All rights reserved.
//

#pragma once
#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame
{
public:
    FBullCowGame(); // Constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    bool IsGuessValid(FString) const; // TODO make a more rich return value
    
    void Reset(); // TODO make a more rich return value.
    // Counts bulls and cows and increases try # assuming valid guess
    FBullCowCount SubmitGuess(FString);
    
    
private:
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};

#endif /* FBullCowGame_hpp */
