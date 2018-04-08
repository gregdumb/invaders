#include "HUD.h"
#include "World.h"
#include "Player.h"


HUD::HUD(World* w, Player* p) {

	this->world = w;
	this->player = p;
}


HUD::~HUD() {
}

void HUD::draw() {

	string scoreStr = "Score: " + to_string(world->getScore());
	string healthStr = "Lives: " + to_string(player->getHealth());
	string levelStr = "Level: " + to_string(world->getLevel());

	ofDrawBitmapString(scoreStr, ofPoint(10, 20));
	ofDrawBitmapString(healthStr, ofPoint(10, 40));
	ofDrawBitmapString(levelStr, ofPoint(10, 60));
}