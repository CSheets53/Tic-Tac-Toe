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
	cout << values[6] << " | " << values[7] << " | " << values[8] << endl;
}

int main()
{
	// Create the values for the grids on the board
	string gridValues[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	DrawBoard(gridValues);

	return 0;
}