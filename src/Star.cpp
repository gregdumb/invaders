#include "Star.h"
#include "World.h"



Star::Star(float speed) {
	this->speed = speed;
	name = "Star";
	zDepth = 0;
}

Star::~Star() {
}

void Star::update() {

	if (location.y > ofGetViewportHeight() + 5) {
		world->deleteObject(this);
	}

	addLocation(ofPoint(0, speed * ofGetLastFrameTime()));
}

void Star::draw() {
	ofSetColor(ofColor::white);
	ofDrawCircle(location, 2.f);
}