#include "Enemy.h"
#include "World.h"
#include "Emitter.h"


Enemy::Enemy() {
	setImage("textures/enemy.png");
	name = "Enemy";

	hasCollision = true;
}


Enemy::~Enemy() {
}

void Enemy::update() {
	Actor::update();

	if (location.y > ofGetViewportHeight()) {
		world->deleteObject(this);
	}
}

void Enemy::explode() {

	Emitter<EnemyFragment>* explosion = new Emitter<EnemyFragment>(world);
	explosion->interval = 0;
	explosion->burst = 5;
	explosion->setLocation(this->location);
	explosion->initialVelocityMin = ofPoint(-200, -200);
	explosion->initialVelocityMax = ofPoint(200, 200);

	world->addObject(explosion);
	explosion->start();

	world->deleteObject(this);
}

void Enemy::collide(Actor* obj) {
	if (obj && world && (obj->getName() == "Projectile")) {
		world->incrementScore();
		this->explode();
	}
}