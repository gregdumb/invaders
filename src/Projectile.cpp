#include "Projectile.h"
#include "World.h"


Projectile::Projectile() {
	setImage("projectile.png");
	cout << "Projectile spawned" << endl;
}


Projectile::~Projectile()
{
}

void Projectile::update() {
	Object::update();

	location.y -= 500 * ofGetLastFrameTime();

	//cout << "Location: " << location << endl;

	if (location.y < 50) {
		world->deleteObject(this);
		cout << "Projectile deleted" << endl;
	}
}