#include "Projectile.h"
#include "World.h"
#include "Config.h"


Projectile::Projectile() {
	setImage("textures/projectile.png");
	name = "Projectile";
	hasCollision = true;

	setVelocity(0, -1 * Config::playerProjectileSpeed);
}


Projectile::~Projectile() {
}

void Projectile::update() {
	Actor::update();

	//location.y -= Config::playerProjectileSpeed * ofGetLastFrameTime();

	if (location.y < 50) {
		world->deleteObject(this);
	}
}