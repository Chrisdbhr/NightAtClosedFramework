#pragma once
#include "ofMain.h"
#include "Button.h"
#include "Transition.h"

#define GAME_MENU 0
#define GAME_CONFIG 1
#define GAME_PLAY 2
#define GAME_OVER 3

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

#define ON true
#define OFF false

class GameManager
{

public:

	ofImage m_bg;
	ofImage m_bgMusic;

	ofImage m_mouse;

	ofSoundPlayer m_mousePress;

	int gameState;
	bool mouseFoiPressionado;

	void update();
	void draw();  // O que o Game Manager desenhar, ser� desenhado em todas as cenas, �til para mouse e notifica��es/conquistas

	GameManager(int gs);

};

