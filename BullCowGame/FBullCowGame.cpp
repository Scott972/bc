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
	bIsGameWon = false;

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
	return bIsGameWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	//Reverse the entered string to determine if input is isogram
	FString ReversedGuess = Guess; 
	std::reverse(ReversedGuess.begin(), ReversedGuess.end());

	//convert the entered string to determine if input is all lowercase
	FString LowerCaseGuess = Guess;
	std::transform(LowerCaseGuess.begin(), LowerCaseGuess.end(), LowerCaseGuess.begin(), ::tolower);

	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess != LowerCaseGuess) {
		return EGuessStatus::Not_Lower_Case;
	}
	else if (Guess.empty()) {
		return EGuessStatus::No_User_Input;
	}
	else if (Guess.length() != GetHiddenWordLenght()) {
		return EGuessStatus::Wrong_Lenght;
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount; 
	int32 HiddenWordLenght = MyHiddenWord.length();

	//loop through all letters in the hidden word 
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) {
		//compare letters against the guess word 
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
		
	if (BullCowCount.Bulls == MyHiddenWord.length()) {
		bIsGameWon = true;
	}

	return BullCowCount; 
}

int32 FBullCowGame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length(); 
}