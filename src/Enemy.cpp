#include "Enemy.h"
#include "World.h"


Enemy::Enemy() {
	setImage("textures/enemy.png");
	name = "Enemy";

	hasCollision = true;
}


Enemy::~Enemy() {
}

void Enemy::update() {
	Actor::update();

	if (location.y > ofGetViewportHeight() - 50) {
		world->deleteObject(this);
	}
}

void Enemy::collide(Actor* obj) {
	if (obj && world && (obj->getName() == "Projectile")) {
		world->incrementScore();
		world->deleteObject(this);
	}
}