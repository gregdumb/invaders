#pragma once
#include "Actor.h"
#include "World.h"

// Enemy
// An enemy that flies down the screen and can be shot by the player
//
class Enemy : public Actor {
public:
	Enemy();
	~Enemy();

	void update();

	void explode();
	virtual void collide(Actor*);
};

class EnemyFragment : public Actor {
public:
	EnemyFragment() {
		setImage("textures/ship.png");
		name = "EnemyFragment";
		hasCollision = false;
		spawnTime = ofGetElapsedTimeMillis();
	}

	void update() {
		if (ofGetElapsedTimeMillis() > spawnTime + 100) {
			world->deleteObject(this);
		}
	}

	float spawnTime;
};