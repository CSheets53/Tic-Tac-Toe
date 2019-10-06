#include <iostream>
#include <string>

using namespace std;

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
		if (values[0] != "X" || values[0] != "O")
			values[0] = move;
		break;
	case 2:
		if (values[1] != "X" || values[1] != "O")
			values[1] = move;
		break;
	case 3:
		if (values[2] != "X" || values[2] != "O")
			values[2] = move;
		break;
	case 4:
		if (values[3] != " X " || values[3] != "O")
			values[3] = move;
		break;
	case 5:
		if (values[4] != "X" || values[4] != "O")
			values[4] = move;
		break;
	case 6:
		if (values[5] != "X" || values[5] != "O")
			values[5] = move;
		break;
	case 7:
		if (values[6] != "X" || values[6] != "O")
			values[6] = move;
		break;
	case 8:
		if (values[7] != "X" || values[7] != "O")
			values[7] = move;
		break;
	case 9:
		if (values[8] != "X" || values[8] != "O")
			values[8] = move;
		break;
	default:
		cout << "Something went wrong..." << endl;
		break;
	}
}

int GetMoveLocation(string turn)
{
	string moveLocationString;

	cout << "Make a valid move " << turn << ": ";
	cin >> moveLocationString;
	cout << endl;

	int moveLocation = stoi(moveLocationString);

	return moveLocation;
}

void MakeMove(string turn, string values[])
{
	int moveLocation;

	// Make sure that they actually entered one of the right numbers
	do
	{
		moveLocation = GetMoveLocation(turn);
	} while ((moveLocation != 1) && (moveLocation != 2) && (moveLocation != 3) && (moveLocation != 4) && (moveLocation != 5) && (moveLocation != 6) && (moveLocation != 7) && (moveLocation != 8) && (moveLocation != 9));

	UpdateValues(moveLocation, turn, values);

	if (turn == "X")
		turn = "O";
	else if (turn == "O")
		turn = "X";
	else
		turn = "?";
}

int main()
{
	// Create the values for the grids on the board
	string gridValues[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	string turn = "X";

	DrawBoard(gridValues);

	MakeMove(turn, gridValues);

	DrawBoard(gridValues);

	return 0;
}