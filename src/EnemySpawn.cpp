#include "EnemySpawn.h"
#include "World.h"
#include "Timer.h"
#include "Enemy.h"

EnemySpawn::EnemySpawn() {
}

EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::startSpawn() {
	if (world) {
		auto fp = bind(&EnemySpawn::spawnEnemy, this);
		world->timer->createTask(fp, 1);
	}
}

void EnemySpawn::spawnEnemy() {

	Enemy* newEnemy = new Enemy();
	
	int randX = ofRandom(ofGetViewportWidth());
	int randV = ofRandomf() * 50;
	newEnemy->setVelocity(randV, 200);
	newEnemy->setLocation(ofPoint(randX, -100));

	world->addObject(newEnemy);
}