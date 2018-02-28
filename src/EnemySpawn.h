#pragma once
#include "Actor.h"

class EnemySpawn : public Actor {
public:
	EnemySpawn();
	~EnemySpawn();

	void startSpawn();

private:
	void spawnEnemy();
};

