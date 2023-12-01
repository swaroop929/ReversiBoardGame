/*
 * ReversiBoard.cpp
 *
 *  Created on: 07-Nov-2023
 *      Author: Sai Swaroop Maram
 */

#include "ReversiBoard.h"
#include<iostream>
#include <vector>
using namespace std;

/**
 * Constructor, initializes the board with center pieces
 */

ReversiBoard::ReversiBoard()
{
	row = 8;
	col = 8;

	for (int row_iterator = 0; row_iterator < 8; row_iterator++)
	{
		for (int column_iterator = 0; column_iterator < 8; column_iterator++)
		{
			if ((row_iterator == 4 && column_iterator == 4)
					|| (row_iterator == 3 && column_iterator == 3))
			{
				Board[row_iterator][column_iterator] = P1_DISK;
			}
			else if ((row_iterator == 3 && column_iterator == 4)
					|| (row_iterator == 4 && column_iterator == 3))
			{
				Board[row_iterator][column_iterator] = P2_DISK;
			}
			else
				Board[row_iterator][column_iterator] = EMPTY;
		}
	}
	cout << "ReversiBoard object is created at " << this << endl;

}
/**
 * Destructor for ReversiBoard
 */

ReversiBoard::~ReversiBoard()
{
	cout << "ReversiBoard object is destructed at " << this << endl;
}

/**
 * Used to return the state of a position
 * \param int row			: [IN] the row from user move
 * \param int col			: [IN] the column from user move
 * \return state			: [OUT] returns the state of the passed position
 */

ReversiBoard::state ReversiBoard::stateOfSquare(int row, int col)
{
	return Board[row][col];
}

/**
 * Used to set the players state only if its valid
 * \param state s			: [IN] Player state
 * \param int row			: [IN] the row from user move
 * \param int col			: [IN] the column from user move
 * \return void
 */

void ReversiBoard::setState(state s, int row, int col)
{
	if (isValidThenFlip(s, row, col))
	{
		Board[row][col] = s;
	}
	else
		cout << "Wrong move" << endl;
}

/**
 * Used to check if players move is valid and flips if valid
 * \param state s			: [IN] Player state
 * \param int row			: [IN] the row from user move
 * \param int col			: [IN] the column from user move
 * \return bool 			: [OUT] returns true if its valid move else False
 */

bool ReversiBoard::isValidThenFlip(state s, int row, int col)
{
	bool flag = false;

	ReversiBoard::state SAME = (s == P1_DISK) ? P1_DISK : P2_DISK;
	ReversiBoard::state OPPONENT = (s == P1_DISK) ? P2_DISK : P1_DISK;

	int dir_row[8] =
	{ -1, 0, -1, -1, 0, 1, 1, 1 };
	int dir_col[8] =
	{ 0, -1, -1, 1, 1, 1, 0, -1 };
	// U, L, UL, UR, R, DR, D, DL
	if (stateOfSquare(row, col) != EMPTY)
		return false;

	vector<int> opponent_row =
	{ };
	vector<int> opponent_col =
	{ };

	for (int direction_itr = 0; direction_itr < 8; direction_itr++)
		//directions traversal loop
	{
		int next_row = row + dir_row[direction_itr];
		int next_col = col + dir_col[direction_itr];

		if (next_col >= 0 && next_row >= 0 && next_row < 8 && next_col < 8)
		{
			if (stateOfSquare(next_row, next_col) != EMPTY
					&& stateOfSquare(next_row, next_col) != SAME)
			{
				if (stateOfSquare(next_row, next_col) == OPPONENT)
				{
					while (stateOfSquare(next_row, next_col) == OPPONENT)
					//_,W,W,W
					{
						opponent_row.push_back(next_row);
						opponent_col.push_back(next_col);

						if (next_col >= 0 && next_row >= 0 && next_row < 8
								&& next_col < 8)
						{
							next_row = next_row + dir_row[direction_itr];
							next_col = next_col + dir_col[direction_itr];
						}
						else
							break;

					}
					if (stateOfSquare(next_row, next_col) == SAME
							&& next_col >= 0 && next_row >= 0 && next_row < 8
							&& next_col < 8) //_,W,W,W,B
					{
						for (size_t k = 0; k < opponent_col.size(); k++)
						{
							Board[opponent_row[k]][opponent_col[k]] = SAME;
						}
						flag = true;
					}
					else if (stateOfSquare(next_row, next_col) == EMPTY
							|| next_row < 0 || next_col < 0 || next_row >= 8
							|| next_col >= 8)
					//_,W,W;W;E
					{
						opponent_col.clear();
						opponent_row.clear();
					}

				}
				else if (stateOfSquare(next_row, next_col) == SAME) //_,W,W,W,B
				{
					flag = false;

				}
				else
					flag = false;
			}
		}
	}
	return flag;
}
