#include "Player.h"
#include "World.h"
#include "Projectile.h"
#include "Enemy.h"


Player::Player() {
	name = "Player";
	setImage("textures/ship.png");
	hasCollision = true;
	zDepth = 3;

	health = 5;

	fireSoundPlayer.setVolume(0.5);
	fireSoundPlayer.load("sounds/laser_1.wav");

	timer = new Timer();
	auto fp = std::bind(&Player::fireProjectile, this);
	fireTask = new TimerTask(fp, 0.1); //timer->createTask(fp, 1);
}

Player::~Player() {
}

void Player::startFiring() {
	//fireProjectile();
	timer->addTask(fireTask);
}

void Player::stopFiring() {
	timer->removeTask(fireTask);
}

void Player::fireProjectile() {
	if (world) {
		Actor* projectileR = world->addObject(new Projectile());
		Actor* projectileL = world->addObject(new Projectile());
		projectileR->setLocation(this->location + ofPoint(45, 0));
		projectileL->setLocation(this->location + ofPoint(-45, 0));
		fireSoundPlayer.play();
	}
}

void Player::update() {
	if (location.x < 0) location.x = 0;
	if (location.x > ofGetViewportWidth()) location.x = ofGetViewportWidth();

	timer->update();
}

void Player::collide(Actor* obj) {
	if (obj && obj->getName() == "Enemy") {
		health--;
		static_cast<Enemy*>(obj)->explode();
		if (health <= 0) {
			// Game over
			world->restartGame();
		}
	}
}

int Player::getHealth() {
	return health;
}