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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{

	if (false) {

		return EGuessStatus::Not_Isogram;
	}
	else if (std::transform(Guess.begin(), Guess.end(), Guess.begin(), ::tolower) != Guess) {
		return EGuessStatus::Not_Lower_Case;
	}
	else if (false) {
		return EGuessStatus::No_User_Input;
	}
	else if (Guess.length() < GetHiddenWordLenght()) {
		return EGuessStatus::Too_Few_Chars;
	}
	else if (Guess.length() > GetHiddenWordLenght()) {
		return EGuessStatus::Too_Many_Chars;
	}
	else {
		return EGuessStatus::OK;

	}
	     
}


void FBullCowGame::SetCurrentTry()
{
	MyCurrentTry = MyCurrentTry + 1;
}

/*
Recieves as valid guess and increments the attmept number
*/
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn 
	MyCurrentTry++;

	// setup a return structure 
	FBullCowCount BullCowCount; 

	int32 HiddenWordLenght = MyHiddenWord.length();

	//loop through all letters in the guess 
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) {
		//compare letters against the hidden word 
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) {
			//if they match
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {	
				//increment bulls if they are in the same place
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					//increment cows if they are not 
					BullCowCount.Cows++;
				}
			}
		}
	}
		
	return BullCowCount; 
}

int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length(); 
}