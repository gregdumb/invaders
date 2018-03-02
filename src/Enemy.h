#pragma once
#include "Actor.h"

// Enemy
// An enemy that flies down the screen and can be shot by the player
//
class Enemy : public Actor {
public:
	Enemy();
	~Enemy();

	void update();

	virtual void collide(Actor*);
};

