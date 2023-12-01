/**
 * @mainpage Reversi Game project Documentation
 *
 * Welcome to the documentation for Reversi Game Project.
 *
 */
#include "ReversiConsoleView.h"

using namespace std;

// Main program
int main()
{
	ReversiBoard Board;
	ReversiConsoleView ViewBoard(&Board);

	cout<<endl<<"Game starts..."<<endl;
	cout << "=========" << endl;
	ViewBoard.print();


	int row = 0;
	int col = 0;
	int player = 0;

	while (1)
	{
		cout << "Enter player number (1 or 2) and any other number"
				" to quit: " << endl;
		cin >> player;

		if (player == 1)
		{
			cout << "Enter row and column " << endl;
			cin >> row >> col;
			Board.setState(ReversiBoard::P1_DISK, row, col);
			ViewBoard.print();
		}
		else if (player == 2)
		{
			cout << "Enter row and column " << endl;
			cin >> row >> col;
			Board.setState(ReversiBoard::P2_DISK, row, col);
			ViewBoard.print();
		}
		else
			break;
	}
	return 0;
}
