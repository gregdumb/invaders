#include "ofApp.h"
#include <cstdint>
#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup() {

	world = new World();
	player = (Player*) world->addObject(new Player());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (world) {
		world->draw();
	}

	player->setRotation(player->getVelocity().x * -0.025);
	//player->addRotation(90 * ofGetLastFrameTime());
	//std::cout << ofGetElapsedTimef() << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	player->startFiring();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	player->setLocation(ofPoint(x, y));
	
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
