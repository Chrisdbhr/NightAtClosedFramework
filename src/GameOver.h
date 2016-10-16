#pragma once
#include "ofMain.h"
#include "GameManager.h"

class GameOver
{

public:
	ofImage m_gameoverBg;

	float m_tempoParaSairDessaTela;

	GameOver();
	~GameOver();
	
	void update(GameManager *game);
	void draw();
	void reset();
};

