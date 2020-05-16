#include "GameGrid.h"

/*
Constructor.

Initialises a new GameGrid with a specified width and
a specified height. The width corresponds to the
number of rows and the height columns. When a GameGrid
is created, it is immediately filled with Cells.

*/
GameGrid::GameGrid(int width, int height)
{
	gWidth = width;
	gHeight = height;
	createArray(gWidth, gHeight);
}

/*
Destructor.

Used to clean up the memory allocated by the Cell objects
that are inserted into the GameGrid.

*/
GameGrid::~GameGrid() {
	for (int i = 0; i < gridArray.size(); i++) {
		for (int j = 0; j < gridArray[i].size(); j++) {
			delete gridArray[i][j];
		}
	}
}

/*
Creates the grid array by inserting new Cell objects into
each location in the grid array.

*/
void GameGrid::createArray(int width, int height) {
	for (int i = 0; i < width; i++) {
		std::vector<Cell*> row;
		for (int j = 0; j < height; j++) {
			// Make sure the pointer to the Cell can't be changed
			Cell* const newCell = new Cell(i, j);
			row.push_back(newCell);
		}
		gridArray.push_back(row);
	}
}

/*
Gets a reference to the Cell object contained at
location i, j. This reference address cannot be
changed.

*/
Cell* GameGrid::getCell(int i, int j) {
	return gridArray[i][j];
}
