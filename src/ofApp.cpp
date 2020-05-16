#include "ofApp.h"
#include "../GameGrid.h"

const int SCALE_FACTOR = 10;
GameGrid *gameGrid = NULL;

// TODO: Figure out the sizing of the grid and how to draw appropriately sized rectangles for each cell

//--------------------------------------------------------------
void ofApp::setup(){
	gameGrid = new GameGrid(SCALE_FACTOR, SCALE_FACTOR);
	ofSetFrameRate(1);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	int width = ofGetViewportWidth() / SCALE_FACTOR;
	int height = ofGetViewportHeight() / SCALE_FACTOR;

	gameGrid->getCell(SCALE_FACTOR / 2, SCALE_FACTOR / 2)->setState(Cell::CellState::ALIVE);
	gameGrid->getCell(SCALE_FACTOR / 2 - 1, SCALE_FACTOR / 2)->setState(Cell::CellState::ALIVE);
	gameGrid->getCell(SCALE_FACTOR / 2 - 2, SCALE_FACTOR / 2)->setState(Cell::CellState::ALIVE);

	ofSetColor(255, 255, 255);
	// Draw grid
	for (int j = 0; j < SCALE_FACTOR; j++) {
		for (int i = 0; i < SCALE_FACTOR; i++) {
			if (gameGrid->getCell(j, i)->getState() == Cell::CellState::DEAD) ofNoFill();
			else ofFill();
			ofDrawRectangle(i * width, j * height, width, height);
		}
	}

	vector<vector<Cell::CellState>> changes;
	int liveNeighbours;
	// Get changes in current generation
	for (int i = 0; i < SCALE_FACTOR; i++) {
		vector<Cell::CellState> rowChange;
		for (int j = 0; j < SCALE_FACTOR; j++) {
			liveNeighbours = 0;
			// Get the number of live neighbours around the current Cell
			for (int k = -1; k < 2; k++) {
				for (int l = -1; l < 2; l++) {
					if (k == 0 && l == 0) continue;

					if (i + k >= 0 && i + k < SCALE_FACTOR
						&& j + l >= 0 && j + l < SCALE_FACTOR) {
						if (gameGrid->getCell(i + k, j + l)->getState() == Cell::CellState::ALIVE) {
							liveNeighbours++;
						}
					}
				}
			}
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	if (button == 0) cout << "x: " << to_string(x) + ", y: " << to_string(y) << endl;
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
