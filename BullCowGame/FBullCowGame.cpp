#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int; 

FBullCowGame::FBullCowGame()
{
	Reset(); 
}

void FBullCowGame::Reset()
{
	
	MyCurrentTry = 1;
	bIsGameWon = false;

	return;
}

void FBullCowGame::SetHiddenWord(FString HiddenWord) 
{
	MyHiddenWord = HiddenWord;
}

void FBullCowGame::SetGameDifficulty(int32 SelectedDifficulty)
{
	TMap<int32, FString> PossibleWords{
		{3, "box"},
		{6, "planes"}
	};

	for (auto word : PossibleWords) {
		if (word.first == SelectedDifficulty) {
			SetHiddenWord(word.second); 
		}
	}
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLenghtToMaxtries{
		{3,5},
		{4,6},
		{5,7},
		{6,8},
		{10, 15}
	};

	return WordLenghtToMaxtries[MyHiddenWord.length()];
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

	

	if (! IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (! IsLowerCase(Guess)) {
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

 bool  FBullCowGame::IsIsogram(FString Guess) const
{
	 if (Guess.length() <= 1 ) {
		 return true; //let's count single chars as an isogram for now
	 }

	 TMap<char, bool> LetterExists;

	 for (char Letter : Guess) { //for each char as letter for the guess
		 Letter = tolower(Letter);
		 if (LetterExists[Letter]) {
			 return false;
		 }
		 else {
			 LetterExists[Letter] = true;
		 }
	 }

	 return true; 
}

 bool FBullCowGame::IsLowerCase(FString Guess) 
{
	 FString LowerCaseGuess = Guess;
	 std::transform(LowerCaseGuess.begin(), LowerCaseGuess.end(), LowerCaseGuess.begin(), ::tolower);

	 if (Guess == LowerCaseGuess) {
		 return true;
	 }

	 return false; 
}