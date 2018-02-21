#pragma once
#include "Actor.h"
class Enemy : public Actor {
public:
	Enemy();
	~Enemy();

	void update();

	virtual void collide(Actor*);
};

