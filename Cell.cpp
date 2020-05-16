#include "Cell.h"

Cell::Cell(int x, int y)
{
	cX = x;
	cY = y;
	cState = CellState::DEAD;
}

Cell::~Cell() {}

void Cell::setState(CellState cellState) {
	cState = cellState;
}

Cell::CellState Cell::getState() {
	return cState;
}


