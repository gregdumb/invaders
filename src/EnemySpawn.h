#pragma once
#include "Actor.h"

// EnemySpawn
// Handles spawning enemies
//
class EnemySpawn : public Actor {
public:
	EnemySpawn();
	~EnemySpawn();

	void startSpawn();

private:
	void spawnEnemy();
};

