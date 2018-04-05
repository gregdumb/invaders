#pragma once

#include "Actor.h"
#include "World.h"
#include "Timer.h"

template<class A>
class Emitter : public Actor {
public:
	Emitter(World* world);

	void start();
	void stop();

	float interval;
	ofPoint initialVelocity;

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
	initialVelocity = ofPoint(0, 0);
}

template<class A>
void Emitter<A>::emit() {
	A* emitted = new A();
	emitted->setWorld(world);
	emitted->setLocation(location);
	emitted->setVelocity(initialVelocity.x, initialVelocity.y);
	world->addObject(emitted);
}

template<class A>
void Emitter<A>::start() {
	if (interval > 0) {
		auto fp = bind(&Emitter<A>::emit, this);
		task = world->timer->createTask(fp, interval);
	}
	else {
		emit();
		destroy();
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