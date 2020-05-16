#pragma once

class Cell {

public:
	Cell(int x, int y);
	~Cell();

	enum CellState { ALIVE, DEAD };

	void setState(CellState cellState);
	CellState getState();

private:
	int cX;
	int cY;

	CellState cState;
};
