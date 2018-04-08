#pragma once
#include "ofMain.h"

class World;
class Player;

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

