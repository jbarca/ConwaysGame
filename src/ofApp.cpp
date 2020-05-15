#include "ofApp.h"
#include "../GameGrid.h"

const int SCALE_FACTOR = 10;
GameGrid *gameGrid = NULL;

// TODO: Figure out the sizing of the grid and how to draw appropriately sized rectangles for each cell

//--------------------------------------------------------------
void ofApp::setup(){
	gameGrid = new GameGrid(ofGetViewportWidth() / SCALE_FACTOR, ofGetViewportHeight() / SCALE_FACTOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Draw grid
	int width = ofGetViewportWidth();
	int height = ofGetViewportHeight();
	for (int i = width / SCALE_FACTOR; i < width; i += width / SCALE_FACTOR) {
		ofDrawLine(i, 0, i, height);
	}
	for (int i = height / 10; i < height; i += height / 10) {
		ofDrawLine(0, i, width, i);
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
