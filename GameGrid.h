#pragma once

#include <vector>
#include "Cell.h"

/*
Implementation of a "Grid" that holds a Cell in each
i, j location.

This grid is used to query Cells so that they can
be updated accordingly.

*/
class GameGrid {
	
public:
	GameGrid(int width, int height);
	~GameGrid();

	Cell* getCell(int i, int j);

private:
	int gWidth;
	int gHeight;
	
	std::vector<std::vector<Cell*>> gridArray;

	void createArray(int width, int height);
};
