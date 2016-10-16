#pragma once
#include "ofMain.h"
#include "GameManager.h"

class GameWin
{

public:
	float m_contador;
	std::string m_mensagem;
	ofTrueTypeFont m_text;
	bool m_mostraTexto;
	ofSoundPlayer m_snd_win;

	GameWin();
	void update(GameManager *game);
	void draw(GameManager *game);
	void reset();
};

