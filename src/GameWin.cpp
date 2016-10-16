#include "GameWin.h"

GameWin::GameWin()
{
	m_snd_win.loadSound("sounds/win.mp3");
	m_mensagem.append("YOU SURVIVED THIS NIGHT");
	m_text.loadFont("cour.ttf", 18, true);
	reset();
}

void GameWin::reset() 
{
	m_mostraTexto = false;
	m_contador = 3;

}
void GameWin::update(GameManager *game)
{
	if (m_contador < 0 && m_mostraTexto == false)
	{
		ofSoundStopAll();
		m_snd_win.play();
		m_mostraTexto = true;
		m_contador = 5;
	}
	m_contador -= ofGetLastFrameTime();
}

void GameWin::draw(GameManager *game)
{
	if (m_mostraTexto)
	{
		m_text.drawString(m_mensagem, 570, 360);
		if (m_contador < 0)
		{
			game->m_night = 2;
			game->gameState = GAME_RESET;
		}

	}

}