#pragma once

#include "ofMain.h"
#include <string>
#include <vector>
#include "Scene.h"
#include "GameConfigs.h"
#include "GamePlay.h"
#include "GameMenu.h"
#include "GameOver.h"

#define GAME_MENU 0
#define GAME_CONFIG 1
#define GAME_PLAY 2
#define GAME_OVER 3


class ofApp : public ofBaseApp{

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
		
		
};
