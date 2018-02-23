#pragma once
#include "Actor.h"
#include "Timer.h"

class Player : public Actor {
public:
	Player();
	~Player();

	void startFiring();
	void stopFiring();

	virtual void update();

private:
	void fireProjectile();
	ofSoundPlayer fireSoundPlayer;

	Timer* timer;
	TimerTask* fireTask;
};

