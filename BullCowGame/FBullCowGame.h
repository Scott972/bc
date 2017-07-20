#pragma once
#include <string>

using FString = std::string;
using int32 = int;



struct BullCowCount{
	int32 Bulls = 0; 
	int32 Cows = 0;
};

class FBullCowGame {

public:
	FBullCowGame(); //constructor 

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const; 
	void SetCurrentTry(); 

	void Reset();
	FString CheckGuessValidity(FString);
	//provide a method for counting bull and cows and increasing attempt number
	BullCowCount SubmitGuess(FString); 

private:
	//initialized via constructor 
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord; 
};