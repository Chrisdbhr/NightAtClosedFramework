#include "GameOver.h"

GameOver::GameOver()
{
	m_gameoverBg.loadImage("images/bg_gameover.png");
	reset();
}

void GameOver::reset()
{
	m_tempoParaSairDessaTela = 4.f;
}

GameOver::~GameOver()
{

}

void GameOver::update(GameManager *game)
{
	m_tempoParaSairDessaTela -= ofGetLastFrameTime();
	if (m_tempoParaSairDessaTela < 0)
	{
		game->gameState = GAME_RESET;
	}
}

void GameOver::draw()
{
	m_gameoverBg.draw(0, 0);

}