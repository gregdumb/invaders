// Copyright Gregory Brisebois 4/8/2018

#include "EnemySpawn.h"
#include "World.h"
#include "Enemy.h"
#include "Timer.h"

EnemySpawn::EnemySpawn() {
	name = "EnemySpawn";
	rate = 1.f;
}

EnemySpawn::~EnemySpawn() {
}

void EnemySpawn::setRate(float newRate) {
	this->rate = newRate;
}

void EnemySpawn::startSpawn() {
	if (world) {
		auto fp = bind(&EnemySpawn::spawnEnemy, this);
		task = new TimerTask(fp, rate);
		world->timer->addTask(task);
	}
}

void EnemySpawn::stopSpawn() {
	if (world && task) {
		world->timer->removeTask(task);
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