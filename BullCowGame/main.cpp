/*
Bull Cow Game main, launches an instance of the game
*/
#include <iostream>
#include <string>
#include <locale>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int; 

void PrintIntro();
FText GetValidGuess(); 
void RepeatGuess(FText Guess);
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary(bool IsWon);
void SetDifficulty(); 
FBullCowGame BCGame; //instantiated  a new game instance 

int main()
{
	bool bWantsToPlayAgain = false; 
	do {
		SetDifficulty(); 
		PrintIntro();
		PlayGame();
		bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain); 

	return 0; 
}

void PrintIntro()
{
	std::cout << "\n\n Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram I'm thinking of?\n\n";
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	while (! BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {

		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);	

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary(BCGame.IsGameWon());
}

void SetDifficulty()
{
	int Difficulty;

	std::cout << "Would you like to play with a 3 letter word or a 6 letter word? Choices are\n";
	std::cout << "3 or 6\n";

	std::cin >> Difficulty; 

	BCGame.SetGameDifficulty(Difficulty);
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Attempt Number " << CurrentTry << " of " << BCGame.GetMaxTries() << ": ";

		//get a guess from the user 
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status) {
		case EGuessStatus::OK:
			return Guess;
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Your input must be an isogram, please try again \n";
			break;

		case EGuessStatus::Not_Lower_Case:
			std::cout << "Your input must only conatined lowecase chars \n";
			break;

		case EGuessStatus::No_User_Input:
			std::cout << "You did not enter any input \n";
			break;

		case EGuessStatus::Wrong_Lenght:
			std::cout << "You must enter " << BCGame.GetHiddenWordLenght() << " Chars \n";
			break;

		default:
			break;
		}
		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);

	return Guess;

}


void RepeatGuess(FText Guess)
{
	std::cout << "You entered " << Guess << std::endl;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";

	FText Response = "";
	std::getline(std::cin, Response);

	return tolower(Response[0]) == 'y';
}

void PrintGameSummary(bool IsWon)
{
	if (IsWon) {
		std::cout << "Well Done! You won!\n";
	}
	else {
		std::cout << " Better Luck next time!\n";
	}
}

