/*
Name: Anne Marie Heidebreicht
NetID: alh1310
Program Description: Write a program that allows the user to play a game of "Rock, Paper, Scissors" with the computer.
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;


/* Create int main() funtion:
   Use the function run_game() to play "Rock, Paper, "Scissors",
   ask the user if they want to play again, continue or end the program
   according to the user input
*/
int run_game();

int main()
{
	int x = true;
	while(x == true)
	{
		srand(time(nullptr));
		int winNum = run_game();
		if (winNum == 2)
		{
			cout << "----------------------" << endl;
			cout << "   Winner: Player!    " << endl;
			cout << "----------------------" << endl;
		}
		else if (winNum == 3)
		{
			cout << "-------------------------" << endl;
			cout << "    Winner: Computer!    " << endl;
			cout << "-------------------------" << endl;
		}

		cout << "Play again? y/n" << endl;
		cout << "----> ";
		string answer = answer;
		cin >> answer;

		if (answer == "y")
		{
			x = true;
		}
		else if (answer == "n")
		{
			x = false;
		}
	}
}


/* Creat run_game() function:
   Takes each funtion below it, determine who wins based on user input
   and computer input, output what each chose in a string, return the winner
*/
int get_com_choice();
int get_player_choice();
int determine_winner(int get_player_choice, int get_com_choice);
string str_choice(int choice);

int run_game()
{
	int com_choice = get_com_choice();
	int player_choice = get_player_choice();

	string player = str_choice(player_choice);
	string com = str_choice(com_choice);

	cout << "You picked: " << player << endl;
	cout << "The computer picked: " << com << endl;

	int winner = determine_winner(player_choice, com_choice);

	while (winner == 1)
	{
		cout << "------------" << endl;
		cout << "    Tie!    " << endl;
		cout << "------------" << endl;
		winner = run_game();
		return winner;
	}
	return winner;
}


/* Create get_player_choice() function:
   Ask user for their choice, get user input, return user input 
*/
int get_player_choice()
{
	int player_choice;
	cout << "What do you choose" << endl;
	cout << "1. Rock" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Scissors" << endl;
	cout << "----> ";
	cin >> player_choice;
	while (player_choice != 1 && player_choice != 2 && player_choice != 3)
	{
		cout << "Error! Please choose a value between 1 and 3." << endl;
		cout << "----> ";
		cin >> player_choice;
	}
	return player_choice;
}


/* Create get_com_choice:
   Get a random integer between 1 and 3, return computer input
*/
int get_com_choice()
{
	int com_choice = rand() % 3 + 1;
	return com_choice;
}


/* Create determine_winner:
   Determine a integers that will tell you who won, return those integers
   depending on who wins. (i.e., if computer choose rock and player chooses paper,
   player wins and the program returns 2)
*/
int determine_winner(int player_choice, int com_choice)
{
	if (com_choice == 1)
	{
		if (player_choice == 1)
		{
			int tie = 1;
			return tie;
		}
		else if (player_choice == 2)
		{
			int win = 2;
			return win;
		}
		else if (player_choice == 3)
		{
			int lose = 3;
			return lose;
		}
	}
	else if (com_choice == 2)
	{
		if (player_choice == 1)
		{
			int lose = 3;
			return lose;
		}
		else if (player_choice == 2)
		{
			int tie = 1;
			return tie;
		}
		else if (player_choice == 3)
		{
			int win = 2;
			return win;
		}
	}
	else if (com_choice == 3)
	{
		if (player_choice == 1)
		{
			int win = 2;
			return win;
		}
		else if (player_choice == 2)
		{
			int lose = 3;
			return lose;
		}
		else if (player_choice == 3)
		{
			int tie = 1;
			return tie;
		}
	}
}


/* Create str_choice() function:
   Takes in integer input, assigns variable to corresponding string,
   return string
*/
string str_choice(int choice)
{
	if (choice == 1)
	{
		string choice = "Rock";
		return choice;
	}
	else if (choice == 2)
	{
		string choice = "Paper";
		return choice;
	}
	else if (choice == 3)
	{
		string choice = "Scissors";
		return choice;
	}
	else
	{
		string choice = "<Could not determine.>";
		return choice;
	}
}