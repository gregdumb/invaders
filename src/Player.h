#pragma once
#include "Object.h"

class Player :
	public Object
{
public:
	Player();
	~Player();

	void startFiring();
	void stopFiring();

private:
	void fireProjectile();

};

