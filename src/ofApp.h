#pragma once

#include "ofMain.h"

#include "World.h"
#include "HUD.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include "EnemySpawn.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		World * world;
		HUD* hud;
		Player* player;

		ofPoint lastMousePosition;

		map<int, bool> keys;

		float lastStarSpawnTime;
};
