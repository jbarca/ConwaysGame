#include "GameGrid.h"

GameGrid::GameGrid(int width, int height)
{
	gWidth = width;
	gHeight = height;
	createArray(gWidth, gHeight);
}

GameGrid::~GameGrid() {
	for (int i = 0; i < gridArray.size(); i++) {
		for (int j = 0; j < gridArray[i].size(); j++) {
			delete gridArray[i][j];
		}
	}
}

void GameGrid::createArray(int width, int height) {
	for (int i = 0; i < width; i++) {
		std::vector<Cell*> row;
		for (int j = 0; j < height; j++) {
			Cell* newCell = new Cell(i, j);
			row.push_back(newCell);
		}
		gridArray.push_back(row);
	}
}
