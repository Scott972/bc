#include "FBullCowGame.h"

using int32 = int; 

FBullCowGame::FBullCowGame()
{
	Reset(); 
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

FString FBullCowGame::CheckGuessValidity(FString)
{
	return FString();
}


void FBullCowGame::SetCurrentTry()
{
	MyCurrentTry = MyCurrentTry + 1;
}

/*
Recieves as valid guess and increments the attmept number
*/
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment the turn 
	MyCurrentTry++;

	// setup a return structure 
	BullCowCount BullCowCount; 

	//loop through all letters in the guess 
	  //compare letters against the hidden word 

	return BullCowCount; 
}