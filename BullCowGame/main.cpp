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
	constexpr int WORLD_LENGHT = 9;
	//introduce game
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORLD_LENGHT << " letter isogram I'm thinking of?\n";
	return;
}

std::string GetGuess()
{
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
	FBullCowGame BCGame; //instantiated the class! 

	constexpr int MAXIMUM_GUESSES = 5;

	for (int count = 1; count <= MAXIMUM_GUESSES; count++) {
		RepeatGuess(GetGuess());
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
