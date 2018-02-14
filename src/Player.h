#pragma once
#include "Actor.h"

class Player :
	public Actor
{
public:
	Player();
	~Player();

	void startFiring();
	void stopFiring();

private:
	void fireProjectile();

};

