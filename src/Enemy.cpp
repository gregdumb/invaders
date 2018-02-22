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
}

void Enemy::collide(Actor* obj) {
	if (obj && world) {
		world->deleteObject(this);
		world->deleteObject(obj);
	}
}