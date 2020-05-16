#pragma once

#include <vector>
#include "Cell.h"

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
