/*
 * ReversiConsoleView.cpp
 *
 *  Created on: 07-Nov-2023
 *      Author: Sai Swaroop Maram
 */

#include "ReversiConsoleView.h"

using namespace std;

ReversiConsoleView::ReversiConsoleView(ReversiBoard *b)
{
	Board = b;
	cout<<"ReversiConsoleView Object created at "<<this<<endl;
}

ReversiConsoleView::~ReversiConsoleView()
{
	cout<<"ReversiConsoleView Object destructed at "<<this<<endl;
}

/**
 * Prints the Board on screen
 */
void ReversiConsoleView::print() const
{
	for(int row_itr = 0; row_itr < 8; row_itr++)
			{
				for (int col_itr = 0; col_itr < 8; col_itr++)
				{
					if(Board->stateOfSquare(row_itr, col_itr) \
							== ReversiBoard::P1_DISK)
					cout<<" B ";
					else if(Board->stateOfSquare(row_itr, col_itr) \
							== ReversiBoard::P2_DISK)
					cout<<" W ";
					else
						cout<<" . ";
				}
				cout<<endl;
			}
}
