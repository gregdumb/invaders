// Copyright Gregory Brisebois 4/8/2018

#pragma once
#include "Actor.h"

// Projectile
// Fired by the player
//
class Projectile : 	public Actor {
public:
	Projectile();
	~Projectile();

	virtual void update();

	virtual void collide(Actor* obj);

protected:
	
};

