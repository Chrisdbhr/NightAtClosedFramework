#pragma once
#include "ofMain.h"
#include "GameManager.h"

class GameMenu
{

public:

	ofImage m_bg;
	ofImage m_bgImages[4];
	float m_imgShowTime = 0;
	int m_imgToShow = 1;
	
	ofSoundPlayer m_snd_music;

	Button *newGame;
	Button *extras;
	Button *exit;

	Transition *transicao;

	GameMenu();
	~GameMenu();

	void update(GameManager *game);
	void draw();


};

