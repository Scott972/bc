#pragma once
#include <string>

class FBullCowGame {

public:
	FBullCowGame(); //constructor 

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const; 
	void SetCurrentTry(); 

	void Reset();
	std::string CheckGuessValidity(std::string);
	//provide a method for counting bull and cows and increasing attempt number

private:
	//initialized via constructor 
	int MyCurrentTry;
	int MyMaxTries;
};