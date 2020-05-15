#pragma once

class Cell {

public:
	Cell(int x, int y);
	~Cell();

	enum CellState { ALIVE, DEAD };

private:
	int cX;
	int cY;

	unsigned int cState;
};
