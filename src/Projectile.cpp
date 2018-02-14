#include "Projectile.h"
#include "World.h"
#include "Config.h"


Projectile::Projectile() {
	setImage("projectile.png");
	cout << "Projectile spawned" << endl;
}


Projectile::~Projectile()
{
}

void Projectile::update() {
	Actor::update();

	location.y -= Config::playerProjectileSpeed * ofGetLastFrameTime();

	//cout << "Location: " << location << endl;

	if (location.y < 50) {
		world->deleteObject(this);
		cout << "Projectile deleted" << endl;
	}
}