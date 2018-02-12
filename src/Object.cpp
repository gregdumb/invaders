#include "Object.h"
#include "World.h"

// **********************************************
// ** Constructors & Initialization

Object::Object() {
	name = "Object";
	world = nullptr;

	location = ofPoint(0, 0);
	lastFrameLocation = location;
	rotation = 0.f;
}

Object::Object(string img) :Object() {
	
	// Initialize sprite
	if (img.length() > 0) {
		setImage(img);
	}
}

Object::~Object() {
}

void Object::setWorld(World* newWorld) {
	world = newWorld;
}

void Object::setImage(string path) {
	imageName = path;
	sprite.loadImage(path);
}

// **********************************************
// ** Tick

void Object::update() {
	updateVelocity();
}

void Object::draw() {

	if (sprite.isAllocated()) {
		ofPushMatrix();
			ofTranslate(location);
			ofRotate(rotation * -1);
			sprite.draw(sprite.getWidth() / -2, sprite.getHeight() / -2);
		ofPopMatrix();
	}
}

// **********************************************
// ** Location

ofPoint Object::getLocation() {
	return location;
}

void Object::setLocation(ofPoint newLocation) {
	location = newLocation;
}

ofPoint Object::addLocation(ofPoint deltaLocation) {
	location += deltaLocation;
	return location;
}

// **********************************************
// ** Rotation

float Object::getRotation() {
	return rotation;
}

void Object::setRotation(float newRotation) {
	rotation = newRotation;
}

float Object::addRotation(float deltaRotation) {
	rotation += deltaRotation;
	return rotation;
}

// **********************************************
// ** Velocity

void Object::updateVelocity() {
	ofPoint deltaLoc = location - lastFrameLocation;
	velocity = deltaLoc / ofGetLastFrameTime();
	lastFrameLocation = location;
}

ofPoint Object::getVelocity() {
	return velocity;
}