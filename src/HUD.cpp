#include "HUD.h"
#include "World.h"
#include "Player.h"


HUD::HUD(World* w, Player* p) {

	this->world = w;
	this->player = p;

	winImg.loadImage("textures/win.png");
	loseImg.loadImage("textures/lose.png");

	font = new ofTrueTypeFont();
	font->loadFont("fonts/neuropol.ttf", 20);
}


HUD::~HUD() {
}

void HUD::draw() {

	string scoreStr = "Score: " + to_string(world->getScore());
	string healthStr = "Lives: " + to_string(player->getHealth());
	string levelStr = "Level: " + to_string(world->getLevel());

	font->drawString(scoreStr, 20, 40);
	font->drawString(healthStr, 20, 70);
	font->drawString(levelStr, 20, 100);

	// Show WIN screen
	if (world->getLevel() >= 11) {
		ofPoint loc = ofPoint(
			ofGetViewportWidth() * 0.5 - winImg.getWidth() * 0.5,
			100
		);
		winImg.draw(loc);
	}

	if (player->getHealth() <= 0) {
		ofPoint loc = ofPoint(
			ofGetViewportWidth() * 0.5 - loseImg.getWidth() * 0.5,
			100
		);
		loseImg.draw(loc);
	}
}