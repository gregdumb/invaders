#include "ofApp.h"
#include "Config.h"
#include <cstdint>
#include <algorithm>

#include "Star.h"

//--------------------------------------------------------------
void ofApp::setup() {

	world = new World();

	// Spawn player
	player = (Player*) world->addObject(new Player());
	player->setLocation(ofPoint(ofGetViewportWidth() * 0.5, ofGetViewportHeight() - Config::playerYOffset));

	// Spawn test enemy
	for (int i = 1; i <= 5; i++) {
		Enemy* enemy = (Enemy*) world->addObject(new Enemy());
		enemy->setLocation(ofPoint(200 * i, 300));
	}

	// Spawn some stars
	lastStarSpawnTime = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (keys[OF_KEY_LEFT]) {
		player->addLocation(ofPoint(-1 * Config::playerXSpeed * ofGetLastFrameTime(), 0));
	}
	else if (keys[OF_KEY_RIGHT]) {
		player->addLocation(ofPoint(Config::playerXSpeed * ofGetLastFrameTime(), 0));
	}

	float now = ofGetElapsedTimef();
	float interval = 0.05;

	if (now > lastStarSpawnTime + interval) {
		lastStarSpawnTime = now;
		float xPos = ofRandom(ofGetViewportWidth());
		float speed = Config::playerYSpeed - ofRandom(100);
		cout << ofRandom(1) << endl;

		Star* star = (Star*)world->addObject(new Star(speed));
		star->setLocation(ofPoint(xPos, 0));
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	if (world) {
		world->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == GLFW_KEY_SPACE && !keys[GLFW_KEY_SPACE]) {
		player->startFiring();
	}

	keys[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

	keys[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

	int deltaX = x - lastMousePosition.x;
	player->addLocation(ofPoint(deltaX, 0));

	lastMousePosition = ofPoint(x, y);
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

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
