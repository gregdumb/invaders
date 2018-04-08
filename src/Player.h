#pragma once
#include "Actor.h"
#include "Timer.h"

// Player
// Spaceship that flies along the bottom of the screen controlled by the user
//
class Player : public Actor {
public:
	Player();
	~Player();

	void startFiring();
	void stopFiring();

	virtual void update();
	virtual void collide(Actor*);

	int getHealth();
	int health;

private:
	void fireProjectile();
	ofSoundPlayer fireSoundPlayer;

	Timer* timer;
	TimerTask* fireTask;
};

