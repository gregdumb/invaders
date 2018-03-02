#pragma once
#include "Actor.h"

// Star
// A small circle that is drawn in the background as a star
//
class Star : public Actor {
public:
	Star(float);
	~Star();

	virtual void update();
	virtual void draw();

private:
	float speed;
};

