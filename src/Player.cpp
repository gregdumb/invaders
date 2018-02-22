#include "Player.h"
#include "World.h"
#include "Projectile.h"


Player::Player() {
	name = "Player";
	setImage("textures/ship.png");
	hasCollision = true;

	fireSoundPlayer.setVolume(0.5);
	fireSoundPlayer.load("sounds/laser_1.wav");
}

Player::~Player() {
}

void Player::startFiring() {
	fireProjectile();
}

void Player::fireProjectile() {
	if (world) {
		Actor* projectile = world->addObject(new Projectile());
		projectile->setLocation(this->location);
		fireSoundPlayer.play();
	}
}

void Player::update() {
	if (location.x < 0) location.x = 0;
	if (location.x > ofGetViewportWidth()) location.x = ofGetViewportWidth();
}