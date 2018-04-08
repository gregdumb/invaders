// Copyright Gregory Brisebois 4/8/2018

#pragma once
#include "Actor.h"
#include "TimerTask.h"

// EnemySpawn
// Handles spawning enemies
//
class EnemySpawn : public Actor {
public:
	EnemySpawn();
	~EnemySpawn();

	void startSpawn();
	void stopSpawn();

	void setRate(float newRate);

private:
	void spawnEnemy();
	TimerTask* task;
	float rate;
};

