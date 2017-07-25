#pragma once
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
	
using FString = std::string;
using int32 = int;



struct FBullCowCount{
	int32 Bulls = 0; 
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	No_User_Input,
	Not_Lower_Case,
	Wrong_Lenght,
	Invalid_Status

};

class FBullCowGame {

public:
	FBullCowGame(); //constructor 

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const; 

	EGuessStatus CheckGuessValidity(FString);

	void SetCurrentTry(); 
	void Reset();
	//provide a method for counting bull and cows and increasing attempt number
	FBullCowCount SubmitValidGuess(FString); 

private:
	//initialized via constructor 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord; 
	bool bIsGameWon; 
};