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

	virtual void update();

private:
	void fireProjectile();

};

