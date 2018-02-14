
#include "World.h"

// **********************************************
// ** Constructors & Initialization

World::World() {
	std::cout << "World initialized" << std::endl;

}

// **********************************************
// ** Tick

void World::draw() {

	cout << "Scene length " << scene.size() << endl;

	deltaTime = ofGetLastFrameTime();

 	for (Actor* obj : toDelete) {
		unsafeDeleteObject(obj);
	}

	for (Actor* obj : toAdd) {
		unsafeAddObject(obj);
	}

	toDelete.clear();
	toAdd.clear();

	for (Actor* obj : scene) {
		if (obj != nullptr) {
			obj->update();
			obj->draw();
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