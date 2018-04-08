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

		int randInt = (int)ofRandom(2.99);

		setImage("textures/enemy-fragment-" + to_string(randInt) + ".png");
		name = "EnemyFragment";
		hasCollision = false;
		lifetime = 1000;
		rotation = ofRandom(360);
		//spawnTime = ofGetElapsedTimeMillis();
	}

	/*void update() {
		if (ofGetElapsedTimeMillis() > spawnTime + 100) {
			world->deleteObject(this);
		}
	}*/

	float spawnTime;
};