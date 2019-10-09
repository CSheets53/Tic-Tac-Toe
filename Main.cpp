#include <iostream>
#include <string>
#include <time.h>

using namespace std;

string winningTurn = " "; // Will be assigned to whichever player wins

// Create the values for the grids on the board
string gridValues[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
bool playAgain = false;
string turn = "X";

void DrawBoard(const string values[])
{
	// Clear the Screen
	system("CLS");

	// Draw the board using the grid values

	/*
	Look like this:

	1 | 2 | 3
	---------
	4 | 5 | 6
	---------
	7 | 8 | 9

	*/

	cout << values[0] << " | " << values[1] << " | " << values[2] << endl;
	cout << "---------" << endl;
	cout << values[3] << " | " << values[4] << " | " << values[5] << endl;
	cout << "---------" << endl;
	cout << values[6] << " | " << values[7] << " | " << values[8] << endl << endl;
}

void UpdateValues(const int location, const string move, string values[])
{
	// Assign values index to the new move, but make sure that a move hasn't already been made there
	switch (location)
	{
	case 1:
		values[0] = move;
		break;
	case 2:
		values[1] = move;
		break;
	case 3:
		values[2] = move;
		break;
	case 4:
		values[3] = move;
		break;
	case 5:
		values[4] = move;
		break;
	case 6:
		values[5] = move;
		break;
	case 7:
		values[6] = move;
		break;
	case 8:
		values[7] = move;
		break;
	case 9:
		values[8] = move;
		break;
	default:
		cout << "Something went wrong..." << endl;
		break;
	}
}

int GetPlayerMoveLocation(string turn)
{
	string moveLocationString;

	cout << "Make a valid move " << turn << ": ";
	cin >> moveLocationString;
	cout << endl;

	int moveLocation = stoi(moveLocationString);

	return moveLocation;
}

int GetAIMoveLocation(string turn)
{
	// Generate the random location
	srand((unsigned int)time(NULL));
	int randomLocation = rand() % 9; // 9 possible values

	return randomLocation;
}

void MakeMove(const string turn, string values[])
{
	int moveLocation{};

	// Make sure that they actually entered one of the right numbers

	// TODO?: Make it so that player can choose which they play as
	if (turn == "X")
		moveLocation = GetPlayerMoveLocation(turn);
	else if (turn == "O")
		moveLocation = GetAIMoveLocation(turn);

	while (true)
	{
		if (((moveLocation != 1) && (moveLocation != 2) && (moveLocation != 3) && (moveLocation != 4) && (moveLocation != 5) &&
			(moveLocation != 6) && (moveLocation != 7) && (moveLocation != 8) && (moveLocation != 9)) || ((values[moveLocation - 1] == "X") || (values[moveLocation - 1] == "O")))
		{
			// TODO?: Make it so that player can choose which they play as
			if (turn == "X")
				moveLocation = GetPlayerMoveLocation(turn);
			else if (turn == "O")
				moveLocation = GetAIMoveLocation(turn);
		}	
		else
			break;
	}

	UpdateValues(moveLocation, turn, values);
}

bool CheckGameWin(const string turn, const string values[])
{
	/*
	Winning Combinations

	X | X | X
	----------
	4 | 5 | 6
	----------
	7 | 8 | 9

	X | 2 | 3
	----------
	X | 5 | 6
	----------
	X | 8 | 9

	X | 2 | 3
	----------
	4 | X | 6
	----------
	7 | 8 | X

	1 | 2 | X
	----------
	4 | X | 6
	----------
	X | 8 | 9

	1 | 2 | 3
	----------
	X | X | X
	----------
	7 | 8 | 9

	1 | 2 | 3
	----------
	4 | 5 | 6
	----------
	X | X | X

	1 | 2 | X
	----------
	4 | 5 | X
	----------
	7 | 8 | X

	1 | X | 3
	----------
	4 | X | 6
	----------
	7 | X | 9
	*/

	if ((values[0] == turn && values[1] == turn && values[2] == turn) ||
		(values[0] == turn && values[3] == turn && values[6] == turn) ||
		(values[0] == turn && values[4] == turn && values[8] == turn) ||
		(values[2] == turn && values[4] == turn && values[6] == turn) ||
		(values[3] == turn && values[4] == turn && values[5] == turn) ||
		(values[6] == turn && values[7] == turn && values[8] == turn) ||
		(values[1] == turn && values[4] == turn && values[7] == turn) ||
		(values[2] == turn && values[5] == turn && values[8] == turn))
	{
		winningTurn = turn;
		return true;
	}
	else if ((values[0] != "1") && (values[1] != "2") && (values[2] != "3") && (values[3] != "4") && (values[4] != "5") && (values[5] != "6") && (values[6] != "7") && (values[7] != "8") && (values[8] != "9"))
	{
		winningTurn = "No one";
		return true;
	}
	else
	{
		return false;
	}
}

bool PlayGame(string turn, string gridValues[])
{
	string playAgain;

	while (true)
	{
		DrawBoard(gridValues);

		MakeMove(turn, gridValues);

		if (CheckGameWin(turn, gridValues))
		{
			DrawBoard(gridValues);
			cout << winningTurn << " wins!" << endl;

			do
			{
				cout << "Would you like to play again? (Y/N): ";
				cin >> playAgain;
			} while (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n");

			if (playAgain == "N" || playAgain == "n")
			{
				cout << "Thanks for playing!" << endl;
				cout << "This game was made by the one and only Cooper Sheets!" << endl;
				cout << "Let him know if you liked it!" << endl;
				return false;
			}
			else if (playAgain == "Y" || playAgain == "y")
			{
				cout << "Let's go around again!" << endl;
				return true;
			}
		}

		if (turn == "X")
			turn = "O";
		else if (turn == "O")
			turn = "X";
		else
			turn = "?";
	}
}

void ResetGame()
{
	// Create the values for the grids on the board
	winningTurn = " ";
	gridValues[0] = "1";
	gridValues[1] = "2";
	gridValues[2] = "3";
	gridValues[3] = "4";
	gridValues[4] = "5";
	gridValues[5] = "6";
	gridValues[6] = "7";
	gridValues[7] = "8";
	gridValues[8] = "9";
	playAgain = false;
	turn = "X";
}

int main()
{
	while (PlayGame(turn, gridValues))
		ResetGame();

	return 0;
}