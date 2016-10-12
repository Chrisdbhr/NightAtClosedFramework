#pragma once

#include "ofMain.h"
#include <string>
#include "Scene.h"
#include "GameConfigs.h"
#include "GamePlay.h"
#include "GameMenu.h"
#include "GameOver.h"

#define GAME_MENU 0
#define GAME_CONFIG 1
#define GAME_PLAY 2
#define GAME_OVER 3

#define MOUSE_NORMAL 0
#define MOUSE_MOVED_MUCH 1
#define MOUSE_PRESSED 2

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768


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
		
		int gameState = GAME_MENU;
		int mouseState;
		

		Scene *scene;
		GameMenu *gameMenu;
		GameConfigs *gameConfigs;
		GamePlay *gamePlay;
		GameOver *gameOver;

		
		
};
