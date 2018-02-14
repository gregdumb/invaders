#include "Actor.h"
#include "World.h"

// **********************************************
// ** Constructors & Initialization

Actor::Actor() {
	name = "Object";
	world = nullptr;

	location = ofPoint(0, 0);
	lastFrameLocation = location;
	rotation = 0.f;
}

Actor::Actor(string img) :Actor() {
	
	// Initialize sprite
	if (img.length() > 0) {
		setImage(img);
	}
}

Actor::~Actor() {
}

void Actor::setWorld(World* newWorld) {
	world = newWorld;
}

void Actor::setImage(string path) {
	imageName = path;
	sprite.loadImage(path);
}

// **********************************************
// ** Tick

void Actor::update() {
	updateVelocity();
}

void Actor::draw() {

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

ofPoint Actor::getLocation() {
	return location;
}

void Actor::setLocation(ofPoint newLocation) {
	location = newLocation;
}

ofPoint Actor::addLocation(ofPoint deltaLocation) {
	location += deltaLocation;
	return location;
}

// **********************************************
// ** Rotation

float Actor::getRotation() {
	return rotation;
}

void Actor::setRotation(float newRotation) {
	rotation = newRotation;
}

float Actor::addRotation(float deltaRotation) {
	rotation += deltaRotation;
	return rotation;
}

// **********************************************
// ** Velocity

void Actor::updateVelocity() {
	ofPoint deltaLoc = location - lastFrameLocation;
	velocity = deltaLoc / ofGetLastFrameTime();
	lastFrameLocation = location;
}

ofPoint Actor::getVelocity() {
	return velocity;
}