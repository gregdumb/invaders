#pragma once

#include "Actor.h"
#include "World.h"
#include "Timer.h"

template<class A>
class Emitter : public Actor {
public:
	Emitter(World* world);
	~Emitter();

	void start();
	void stop();

	float interval;
	ofPoint initialVelocityMin;
	ofPoint initialVelocityMax;

	int burst;

private:
	void emit();
	void destroy();

	World* world;
	TimerTask* task;
};

template<class A>
Emitter<A>::Emitter(World* world) {
	this->world = world;
	interval = 1;
	burst = 1;
	initialVelocityMin = ofPoint(0, 0);
	initialVelocityMax = ofPoint(0, 0);
}

template<class A>
Emitter<A>::~Emitter() {
	cout << "Emitter destroyed" << endl;
}

template<class A>
void Emitter<A>::emit() {
	if (burst < 1) return;

	for (int i = 0; i < burst; i++) {
		A* emitted = new A();
		emitted->setWorld(world);
		emitted->setLocation(location);

		// Randomized velocity
		float minX = initialVelocityMin.x;
		float minY = initialVelocityMin.y;
		float maxX = initialVelocityMax.x;
		float maxY = initialVelocityMax.y;

		float randX = ofRandom(1);
		float randY = ofRandom(1);

		float diffX = maxX - minX;
		float diffY = maxY - minY;

		float x = minX + diffX * randX;
		float y = minY + diffY * randY;

		emitted->setVelocity(x, y);
		world->addObject(emitted);
	}
}

template<class A>
void Emitter<A>::start() {
	if (interval > 0) {
		auto fp = bind(&Emitter<A>::emit, this);
		task = world->timer->createTask(fp, interval);
	}
	else {
		emit();
		this->lifetime = 100;
	}
	
}

template<class A>
void Emitter<A>::stop() {
	if (task) {
		world->timer->removeTask(task);
		delete task;
	}
}

template<class A>
void Emitter<A>::destroy() {
	stop();
	world->deleteObject(this);
}