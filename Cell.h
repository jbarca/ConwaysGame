#pragma once

/*
Implementation of a "Cell" in the game grid that holds
an x, y position and a state: either dead or alive

*/

class Cell {

public:
	Cell(int x, int y);
	~Cell();

	/*
	 An enum that determines the current state of the Cell

    */
	enum CellState { ALIVE, DEAD };

	void setState(CellState cellState);
	CellState getState();

private:
	int cX;
	int cY;

	CellState cState;
};
