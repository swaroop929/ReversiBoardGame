/*
 * ReversiConsoleView.h
 *
 *  Created on: 07-Nov-2023
 *      Author: Sai Swaroop Maram
 */
#include "ReversiBoard.h"
#include <iostream>

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

/**
 * @class ReversiConsoleView
 * @brief Used to print the board on screen
 */
class ReversiConsoleView
{
	ReversiBoard *Board; ///< pointer to the ReversiBoard
public:
	/**
	 * Constructor takes in Board as parameter
	 * \param ReversiBoard *Board : [IN] Pointer to ReversiBoard
	 */
	ReversiConsoleView(ReversiBoard *Board);
	/**
	 * Destructor for ReversiConsoleView object
	 */
	~ReversiConsoleView();
	/**
	 * Prints the Board on screen
	 */
	void print() const;
};

#endif /* REVERSICONSOLEVIEW_H_ */
