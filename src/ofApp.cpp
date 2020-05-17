#include "ofApp.h"
#include "GameGrid.h"
#include <algorithm>

// Setup necessary globals
ofxIntSlider scale;
ofxPanel gui;

int SCALE_FACTOR = 100;
GameGrid *gameGrid = NULL;
bool canStartGame;

// TODO: Fix game drawing with slider value as scale factor. Every time scale factor
// is changed, update gameGrid to reflect the new scale factor

//--------------------------------------------------------------
void ofApp::setup(){
	// Create a new GameGrid with size SCALE_FACTOR * SCALE_FACTOR
	gameGrid = new GameGrid(SCALE_FACTOR, SCALE_FACTOR);
	// Initially, the game will not start
	canStartGame = false;
	ofSetFrameRate(30);

	gui.setup();
	gui.add(scale.setup("scale", 10, 10, 100));

	//gameGrid->getCell(2, 1)->setState(Cell::CellState::ALIVE);
	//gameGrid->getCell(1, 1)->setState(Cell::CellState::ALIVE);
	//gameGrid->getCell(0, 1)->setState(Cell::CellState::ALIVE);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Get the width and height of each Cell for drawing
	int width = ofGetViewportWidth() / SCALE_FACTOR;
	int height = ofGetViewportHeight() / SCALE_FACTOR;

	ofSetColor(255, 255, 255);
	// Draw grid
	for (int j = 0; j < SCALE_FACTOR; j++) {
		for (int i = 0; i < SCALE_FACTOR; i++) {
			if (gameGrid->getCell(j, i)->getState() == Cell::CellState::DEAD) ofNoFill();
			else ofFill();
			ofDrawRectangle(i * width, j * height, width, height);
		}
	}

	// Allow to pause and play the game by pressing the 's' key
	if (canStartGame) {
		vector<vector<Cell::CellState>> changes;
		int liveNeighbours;
		// Get changes in current generation
		for (int i = 0; i < SCALE_FACTOR; i++) {
			vector<Cell::CellState> rowChange;
			for (int j = 0; j < SCALE_FACTOR; j++) {
				// Get the number of live neighbours around the current Cell
				liveNeighbours = gameGrid->getLiveNeighbours(i, j);

				// If the Cell is alive and it has 2 or 3 live neighbours, it survives, otherwise
				// it dies
				if (gameGrid->getCell(i, j)->getState() == Cell::CellState::ALIVE) {
					if (liveNeighbours == 2 || liveNeighbours == 3) rowChange.push_back(Cell::CellState::ALIVE);
					else rowChange.push_back(Cell::CellState::DEAD);
				}
				// If the Cell is dead and it has 3 live neighbours, it becomes a live cell, otherwise,
				// it stays dead
				else {
					if (liveNeighbours == 3) rowChange.push_back(Cell::CellState::ALIVE);
					else rowChange.push_back(Cell::CellState::DEAD);
				}
			}
			changes.push_back(rowChange);
		}

		// Apply changes to the grid
		for (int i = 0; i < changes.size(); i++) {
			for (int j = 0; j < changes[i].size(); j++) {
				gameGrid->getCell(i, j)->setState(changes[i][j]);
			}
		}
	}
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		if (canStartGame) canStartGame = false;
		else canStartGame = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	// Map the x, y coordinates of the window to a specific cell location
	// The formula is: cellLocationI = y / (widthOfWindow / scaleFactor)
	//				   cellLocationJ = x / (heightOfWindow / scaleFactor)
	int width = ofGetViewportWidth() / SCALE_FACTOR;
	int height = ofGetViewportHeight() / SCALE_FACTOR;
	int j = x / width;
	int i = y / height;

	// Turn the cells on and off when left clicking on them
	if (button == 0) {
		if (gameGrid->getCell(i, j)->getState() == Cell::CellState::DEAD) {
			gameGrid->getCell(i, j)->setState(Cell::CellState::ALIVE);
		}
		else {
			gameGrid->getCell(i, j)->setState(Cell::CellState::DEAD);
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
