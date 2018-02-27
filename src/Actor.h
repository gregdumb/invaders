#pragma once

#include "ofMain.h"

class World;

class Actor
{
public:
	Actor();
	~Actor();

	virtual void draw();
	virtual void update();

	void setWorld(World*);

	void setImage(string);

	// Get the object's location
	ofPoint getLocation();

	// Set the object's location
	void setLocation(ofPoint);

	// Add to object's location
	ofPoint addLocation(ofPoint);

	float getRotation();
	void setRotation(float);
	float addRotation(float);

	// Get the object's velocity
	ofPoint getVelocity();

	void setVelocity(float, float);

	// Should other things collide with this object
	bool hasCollision;

	virtual void collide(Actor*);

	bool overlaps(ofPoint);

	// Depth to render at
	int zDepth;

	string getName();

protected:
	// Reference to the world
	World* world;

	// Name of object
	string name;

	// Location of the object
	ofPoint location;

	// Rotation of the object in degrees
	float rotation;

	ofImage sprite;

private:
	// Place we were last frame, used to calculate velocity
	ofPoint lastFrameLocation;

	// Velocity of the object (do not set)
	ofPoint velocity;

	// Updates the velocity
	void updateVelocity();
	
};

