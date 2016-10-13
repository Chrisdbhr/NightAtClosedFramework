#include "GameMenu.h"

GameMenu::GameMenu()
{
	m_bg.loadImage("images/bg_menu.png");
	m_bgImages[0].loadImage("images/menu_image1.png");
	m_bgImages[1].loadImage("images/menu_image2.png");
	m_bgImages[2].loadImage("images/menu_image3.png");
	m_bgImages[3].loadImage("images/menu_image4.png");
	transicao = new Transition();

	newGame = new Button(1105, 405, 333, 50, false);
	extras = new Button(1105, 480, 333, 50, false);
	exit = new Button(1105, 560, 333, 50, false);

	m_snd_music.loadSound("sounds/menu.mp3");
	m_snd_music.setLoop(true);
	m_snd_music.play();

}

GameMenu::~GameMenu()
{

}
void GameMenu::update(GameManager *game)
{

	if (newGame->mouseOver())
	{
		newGame->m_drawIt = true;
		if (game->mouseFoiPressionado)
		{
			m_snd_music.stop();
			game->gameState = GAME_PLAY;
		}
	}
	else
	{
		newGame->m_drawIt = false;
	}

	if (extras->mouseOver())
	{
		extras->m_drawIt = true;
		if (game->mouseFoiPressionado)
		{
			transicao->m_duracaoDaTransicao = 0.1f;
		}

	}
	else
	{
		extras->m_drawIt = false;
	}

	if (exit->mouseOver())
	{
		exit->m_drawIt = true;
		if (game->mouseFoiPressionado)
		{
			std::exit(0);
		}
	}
	else
	{
		exit->m_drawIt = false;
	}


}

void GameMenu::draw()
{
	newGame->draw();
	extras->draw();
	exit->draw();
	if (m_imgShowTime < 0)
	{
		m_imgToShow = ofRandom(0, 3);
		if (m_imgToShow == 0)
		{
			m_imgShowTime = 0.1f;

		}
		else
			m_imgShowTime = ofRandom(0.5f, 2);

	}
	else
	{
		m_bgImages[m_imgToShow].draw(30+ofRandom(-4,4), 0 + ofRandom(-4, 4));
		m_imgShowTime -= ofGetLastFrameTime();
	}

	// A ordem importa, aqui desenha a imagem por ultimo para os botoes ficarem atras
	m_bg.draw(0, 0);
	transicao->draw();

}