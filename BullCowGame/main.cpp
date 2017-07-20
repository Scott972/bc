#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include "FBullCowGame.h"

void PrintIntro();
std::string GetGuess(); 
void RepeatGuess(std::string Guess);
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
	constexpr int WORD_LENGHT = 9;
	//introduce game
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGHT << " letter isogram I'm thinking of?\n";
	return;
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Attempt Number: " << CurrentTry << " "; 

	//get a guess from the user 
	std::string Guess = "";
	std::getline(std::cin, Guess);
	 
	return Guess; 
}


void RepeatGuess(std::string Guess)
{
	std::cout << "You entered " << Guess << std::endl;
}

void PlayGame()
{
	
	int MaxTries = BCGame.GetMaxTries();
	//todo use while loop once we let the game validate
	for (int count = 1; count <= MaxTries; count++) {
		RepeatGuess(GetGuess()); //todo validate input 

		//submit only valid quess
		//output number of bull and cows 

		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";

	std::string Response = "";
	std::getline(std::cin, Response);

	return tolower(Response[0]) == 'y';
}
