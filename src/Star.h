#pragma once
#include "Actor.h"

class Star :
	public Actor
{
public:
	Star(float);
	~Star();

	virtual void update();
	virtual void draw();

private:
	float speed;
};
