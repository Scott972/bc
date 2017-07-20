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
	Too_Many_Chars,
	No_User_Input,
	Too_Few_Chars,
	Not_Lower_Case

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
	FBullCowCount SubmitGuess(FString); 

private:
	//initialized via constructor 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord; 
};