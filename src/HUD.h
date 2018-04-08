// Copyright Gregory Brisebois 4/8/2018

#pragma once
#include "ofMain.h"

class World;
class Player;

// HUD
// Displays informational text on screen for the player
class HUD
{
public:
	HUD(World* w, Player* p);
	~HUD();

	void draw();

private:
	World* world;
	Player* player;

	ofImage winImg;
	ofImage loseImg;

	ofTrueTypeFont* font;
};

