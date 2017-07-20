/*
	This is the console executable that makes use of the BullCow class. 
	This acts as the view in the MVC pattern and is responsible for all 
	user interaction.  For game logic see the FB
*/
#include <iostream>
#include <string>
#include <locale>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int; 

void PrintIntro();
FText GetGuess(); 
void RepeatGuess(FText Guess);
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiated  a new game instance 

int main()
{
	bool bWantsToPlayAgain = false; 
	do {
		PrintIntro();
		PlayGame();
		bWantsToPlayAgain = AskToPlayAgain();
	} while (bWantsToPlayAgain); 

	return 0; 
}

void PrintIntro()
{
	
	//introduce game
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram I'm thinking of?\n";
	return;
}

FText GetGuess()//todo get a valid guess
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Attempt Number " << CurrentTry << ": "; 

	//get a guess from the user 
	FText Guess = "";
	std::getline(std::cin, Guess);
	 
	return Guess; 
}


void RepeatGuess(FText Guess)
{
	std::cout << "You entered " << Guess << std::endl;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	for ( int32 count = 1; count <= MaxTries; count++) {	//todo use while loop once we let the game validate

		FText Guess = GetGuess(); //todo validate input
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);	//submit only valid quess

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n"; 
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";

	FText Response = "";
	std::getline(std::cin, Response);

	return tolower(Response[0]) == 'y';
}
