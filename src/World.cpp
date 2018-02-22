
#include "World.h"

// **********************************************
// ** Constructors & Initialization

World::World() {
	std::cout << "World initialized" << std::endl;

	ofBackground(ofColor(42, 4, 64));
}

// **********************************************
// ** Tick

void World::draw() {
	// DeltaTime
	deltaTime = ofGetLastFrameTime();

	// Remove objects scheduled for deletion
 	for (Actor* obj : toDelete) {
		unsafeDeleteObject(obj);
	}

	// Add objects scheduled for addition
	for (Actor* obj : toAdd) {
		unsafeAddObject(obj);
	}

	// Clear addition/deletion queues
	toDelete.clear();
	toAdd.clear();

	updateCollision();

	// Update
	for (Actor* obj : scene) {
		if (obj != nullptr) {
			obj->update();
		}
	}

	// Draw
	for (Actor* obj : scene) {
		if (obj != nullptr) {
			obj->draw();
		}
	}
}

void World::updateCollision() {

	for (Actor* obj1 : scene) {
		if (obj1->hasCollision) {
			for (Actor* obj2 : scene) {
				if (obj1 != obj2 &&
					obj1->overlaps(obj2->getLocation()) &&
					obj2->hasCollision) {

					obj1->collide(obj2);
				}
			}
		}
	}
}

// **********************************************
// ** Adding Objects

Actor* World::addObject(Actor* newObject) {
	toAdd.push_back(newObject);
	return newObject;
}

Actor* World::unsafeAddObject(Actor* newObject) {

	if (std::find(scene.begin(), scene.end(), newObject) == scene.end()) {
		newObject->setWorld(this);
		scene.push_back(newObject);
		return newObject;
	}
	else {
		cout << "Prevented addition of duplicate object" << endl;
		return nullptr;
	}
}

// **********************************************
// ** Deleting Objects

void World::deleteObject(Actor* toRemove) {
	toDelete.push_back(toRemove);
}

bool World::unsafeDeleteObject(Actor* toRemove) {
	// Get index
	ptrdiff_t index = std::find(scene.begin(), scene.end(), toRemove) - scene.begin();

	if (index < scene.size()) {
		// Remove and delete if exists
		scene.erase(scene.begin() + index);
		delete toRemove;
	}
	else {
		return false;
	}

	return true;
}

float World::getDeltaTime() {
	return deltaTime;
}