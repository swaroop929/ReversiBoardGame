/*
 * ReversiBoard.h
 *
 *  Created on: 07-Nov-2023
 *      Author: Sai Swaroop Maram
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @class ReversiBoard
 * @brief The Reversi game board
 */
class ReversiBoard
{

public:
	typedef enum
	{
		EMPTY, P1_DISK, P2_DISK
	} state; ///<state of a slot on the board

private:
	int row; ///< row on the board
	int col; ///< Column on the board
	state Board[8][8]; ///< Game board

public:
	/**
	 * Constructor, initializes the board with center pieces
	 */
	ReversiBoard();
	/**
	 * Destructor for ReversiBoard
	 */
	virtual ~ReversiBoard();
	/**
	 * Used to return the state of a position
	 * \param int row			: [IN] the row from user move
	 * \param int col			: [IN] the column from user move
	 * \return state			: [OUT] returns state of the passed position
	 */
	state stateOfSquare(int row, int col);
	/**
	 * Used to set the players state only if its valid
	 * \param state s			: [IN] Player state
	 * \param int row			: [IN] the row from user move
	 * \param int col			: [IN] the column from user move
	 * \return void
	 */
	void setState(state s, int row, int col);
	/**
	 * Used to check if players move is valid and flips if valid
	 * \param state s			: [IN] Player state
	 * \param int row			: [IN] the row from user move
	 * \param int col			: [IN] the column from user move
	 * \return bool 			: [OUT] returns true if valid move else False
	 */
	bool isValidThenFlip(state s, int row, int col);
};

#endif /* REVERSIBOARD_H_ */
