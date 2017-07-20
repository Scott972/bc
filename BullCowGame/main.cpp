/*
	This is the console executable that makes use of the BullCow class. 
	This acts as the view in the MVC pattern and is responsible for all 
	user interaction.  For game logic see the FB
*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
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
	constexpr int32 WORD_LENGHT = 9;
	//introduce game
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGHT << " letter isogram I'm thinking of?\n";
	return;
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Attempt Number: " << CurrentTry << " "; 

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
	
	int32 MaxTries = BCGame.GetMaxTries();
	//todo use while loop once we let the game validate
	for ( int32 count = 1; count <= MaxTries; count++) {
		RepeatGuess(GetGuess()); //todo validate input 

		//submit only valid quess
		//output number of bull and cows 

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
