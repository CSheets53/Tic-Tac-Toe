#include <iostream>
#include <string>
using namespace std;

// Create the values for the grids on the board
string gridValues[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

void DrawBoard()
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

	cout << gridValues[0] << " | " << gridValues[1] << " | " << gridValues[2] << endl;
	cout << "---------" << endl;
	cout << gridValues[3] << " | " << gridValues[4] << " | " << gridValues[5] << endl;
	cout << "---------" << endl;
	cout << gridValues[6] << " | " << gridValues[7] << " | " << gridValues[8] << endl;
}

int main()
{
	DrawBoard();

	return 0;
}