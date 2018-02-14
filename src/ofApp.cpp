#include "ofApp.h"
#include "Config.h"
#include <cstdint>
#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup() {

	world = new World();
	player = (Player*) world->addObject(new Player());
	player->setLocation(ofPoint(ofGetViewportWidth() * 0.5, ofGetViewportHeight() - Config::playerYOffset));

	leftKeyPressed = false;
	rightKeyPressed = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (leftKeyPressed) {
		player->addLocation(ofPoint(-1 * Config::playerXSpeed * ofGetLastFrameTime(), 0));
	}
	else if (rightKeyPressed) {
		player->addLocation(ofPoint(Config::playerXSpeed * ofGetLastFrameTime(), 0));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (world) {
		world->draw();
	}

	//player->setRotation(player->getVelocity().x * -0.025);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == GLFW_KEY_SPACE) {
		player->startFiring();
	}

	if (key == OF_KEY_LEFT) {
		leftKeyPressed = true;
	}

	if (key == OF_KEY_RIGHT) {
		rightKeyPressed = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_LEFT) {
		leftKeyPressed = false;
	}

	if (key == OF_KEY_RIGHT) {
		rightKeyPressed = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

	int deltaX = x - lastMousePosition.x;
	player->addLocation(ofPoint(deltaX, 0));

	lastMousePosition = ofPoint(x, y);
	
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
