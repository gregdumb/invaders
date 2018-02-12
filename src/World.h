#pragma once

#include "ofMain.h"
#include "Object.h"

class World {
public:
	World();
	~World();

	// Called every frame, draws all objects in the scene
	void draw();

	// Adds an object to the scene for rendering
	Object* addObject(Object*);

	// Removes an object from the scene and deletes it
	void deleteObject(Object*);

	// Get time between frames
	float getDeltaTime();

private:
	// Holds all the objects we need to render
	vector<Object*> scene;

	// Objects scheduled for addition
	vector<Object*> toAdd;

	// Objects scheduled for deletion
	vector<Object*> toDelete;

	// Immediately adds an object from the scene
	Object* unsafeAddObject(Object*);

	// Immediately removes an object from the scene
	bool unsafeDeleteObject(Object*);

	// Time between frames
	float deltaTime;
};