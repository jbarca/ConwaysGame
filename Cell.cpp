#include "Cell.h"

Cell::Cell(int x, int y)
{
	cX = x;
	cY = y;
	cState = CellState::ALIVE;
}

Cell::~Cell() {}


