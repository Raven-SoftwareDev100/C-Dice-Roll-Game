// Simulation of a craps game in C++.
#include <iostream>
#include <ctime> // Contains time() function prototype
using namespace std;

int diceRoll(); // Rolls dice, calculates amd displays sum of thrown dice

int main()
{
	cout << "*****CRAPS GAME*****\n\n"; // Decoration for output program

	enum Status { CONTINUE, WIN, LOSE }; // Enumeration with constants that represent the game status

	int myPoint; // Point if no win or loss on first roll
	Status gameStatus; // can contain CONTINUE, WIN or LOSE

	srand((unsigned)time(nullptr)); // Randomize random number generator using current time

	int sumOfDice = diceRoll(); // First dice roll

	switch (sumOfDice) // Determines the game status and point(s) (if needed) based on first roll
	{
	case 7: // Win with 7 on first roll
	case 11: // Win with 11 on first roll           
		gameStatus = WIN;
		break;

	case 2: // Lose with 2 on first roll
	case 3: // Lose with 3 on first roll
	case 12: // Lose with 12 on first roll             
		gameStatus = LOSE;
		break;

	default:
		gameStatus = CONTINUE;
		myPoint = sumOfDice;
		cout << "Total score is: " << myPoint << endl;
		break; // Optional because of switch end
	}

	// While game is not complete
	while (gameStatus == CONTINUE) // Neither a win or loss
	{
		sumOfDice = diceRoll(); // Rolls dice again

		//Determines game status
		if (sumOfDice == myPoint) // Player wins by making point
		{
			gameStatus = WIN;
		}
		else
		{
			if (sumOfDice == 7) // Player loses by rolling 7 before point
			{
				gameStatus = LOSE;
			}
		}
	}

	// Displays win or lose message
	if (gameStatus == WIN)
	{
		cout << "The player has won!\n" << endl;
		cout << "Press Enter to continue." << endl; // For program layout
	}

	else
	{
		if (gameStatus == LOSE)
		{
			cout << "The player has lost...\n" << endl;
			cout << "Press Enter to continue." << endl; // For program layout
		}
	}

	getchar();
}

int diceRoll()
{
	// Picks random dice values
	int dieOne = rand() % 6 + 1;// The first die roll
	int dieTwo = rand() % 6 + 1;// The second die roll

	int sum = dieOne + dieTwo; // Sum is calculated by adding the two dice values

	cout << "Player has rolled " << dieOne << " and " << dieTwo << " which is equal to: " << sum << endl; // Display results of the roll
	return sum;
}