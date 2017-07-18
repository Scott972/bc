#pragma once
#include <string>

class FBullCowGame {

public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon(); 
	std::string CheckGuessValidity(std::string);


private:
	int MyCurrentTry;
	int MyMaxTries;
};