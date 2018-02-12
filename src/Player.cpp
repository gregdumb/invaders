#include "Player.h"
#include "World.h"
#include "Projectile.h"


Player::Player() :Object("ship.png") {
	
	name = "Player";
	imageName = "ship.png";
}

Player::~Player() {
}

void Player::startFiring() {

	fireProjectile();
}

void Player::fireProjectile() {
	if (world) {
		Object* projectile = world->addObject(new Projectile());
		projectile->setLocation(this->location);
	}
}