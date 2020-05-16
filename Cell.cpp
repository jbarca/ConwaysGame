#include "Cell.h"

/*
Constructor.

Assigns the row, column pair to the associated attributes.
When a Cell is spawned, it's default state is dead, until
changed.

*/
Cell::Cell(int x, int y)
{
	cX = x;
	cY = y;
	cState = CellState::DEAD;
}

/*
Destructor.

Not used.


*/
Cell::~Cell() {}

/*
Sets the state of the Cell to the state specified.

The two possible inputs for this function are:
* CellState::ALIVE
* CellState::DEAD

*/
void Cell::setState(CellState cellState) {
	cState = cellState;
}

/*
Gets the current state of the Cell.

*/
Cell::CellState Cell::getState() {
	return cState;
}


