#pragma once

/**
* Global game config variables
*/

class Config {
public:

	// Distance from bottom of screen to ship
	const static int playerYOffset = 100;

	// Speed of player
	const static int playerXSpeed = 400;
	const static int playerYSpeed = 200; // This one just controls the speed of stars in the background

	// Speed of projectiles
	const static int playerProjectileSpeed = 800;

};