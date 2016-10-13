#include "GamePlay.h"

GamePlay::GamePlay()
{
	m_ambient.loadSound("sounds/ambient.mp3");
	m_bg.loadImage("images/bg_play.png");

	m_camera1.loadImage("images/camera1.png");
	m_camera2.loadImage("images/camera2.png");
	m_camera4.loadImage("images/camera4.png");
	m_monitorHud.loadImage("images/monitorHud.png");
	m_luzVermelha.loadImage("images/luzVermelha.png");

	transicao = new Transition();
	m_sndCameraOff.loadSound("sounds/static.mp3");
	// Botoes para clicar e mostrar a imagem da camera
	m_room0 = new Button(750, 430, 28, 28, true, ON);
	m_room0->m_online = false;
	m_room1 = new Button(707, 422, 26, 28, true, ON);
	m_room2 = new Button(724, 381, 46, 26, true, ON);
	m_room3 = new Button(795, 380, 36, 26, true, ON);
	m_room3->m_online = false;
	m_room4 = new Button(795, 415, 34, 26, true, ON);

	m_monitor = new Button(819, 461, 12, 12, true, OFF);

	// Botoes de ligar e desligar as luzes
	m_light_room0 = new Button(745, 345, 11, 11, true, ON);
	m_light_room1 = new Button(745 + 18, 345, 11, 11, true, OFF);
	m_light_room2 = new Button(745 + 36, 345, 11, 11, true, OFF);
	m_light_room3 = new Button(745 + 54, 345, 11, 11, true, OFF);
	m_light_room4 = new Button(745 + 72, 345, 11, 11, true, OFF);

}

GamePlay::~GamePlay()
{

}

void GamePlay::update(GameManager *game)
{
	if (m_ambient.isPlaying() == false)
	{
		m_ambient.play();

	}

	if (game->mouseFoiPressionado)
	{
		if (m_monitor->m_estado == ON)
		{
			if (m_room0->mouseOver())
			{
				game->m_mousePress.play();
				m_cameraNaTela = 0;
				m_cameraTempoEfeitoTroca += 0.2f;
			}
			if (m_room1->mouseOver())
			{
				game->m_mousePress.play();
				m_cameraNaTela = 1;
				m_cameraTempoEfeitoTroca += 0.2f;
			}
			if (m_room2->mouseOver())
			{
				game->m_mousePress.play();
				m_cameraNaTela = 2;
				m_cameraTempoEfeitoTroca += 0.2f;
			}
			if (m_room3->mouseOver())
			{
				game->m_mousePress.play();
				m_cameraNaTela = 3;
				m_cameraTempoEfeitoTroca += 0.2f;
			}
			if (m_room4->mouseOver())
			{
				game->m_mousePress.play();
				m_cameraNaTela = 4;
				m_cameraTempoEfeitoTroca += 0.2f;
			}
			if (m_light_room0->mouseOver())
			{
				game->m_mousePress.play();
				if (m_light_room0->m_estado == ON) // se ta ligado, desliga
				{
					m_bg.loadImage("images/bg_play_off.png");
					m_light_room0->m_estado = OFF;
					m_ambient.setVolume(0.5f);
				}
				else
				{
					m_bg.loadImage("images/bg_play.png");
					m_light_room0->m_estado = ON;
					m_ambient.setVolume(1.f);
				}

			}
			if (m_light_room1->mouseOver())
			{
				game->m_mousePress.play();
				m_light_room1->m_estado == ON ? m_light_room1->m_estado = OFF : m_light_room1->m_estado = ON;
			}
			if (m_light_room2->mouseOver())
			{
				game->m_mousePress.play();
				m_light_room2->m_estado == ON ? m_light_room2->m_estado = OFF : m_light_room2->m_estado = ON;
			}
			if (m_light_room3->mouseOver())
			{
				game->m_mousePress.play();
				m_light_room3->m_estado == ON ? m_light_room3->m_estado = OFF : m_light_room3->m_estado = ON;
			}
			if (m_light_room4->mouseOver())
			{
				game->m_mousePress.play();
				m_light_room4->m_estado == ON ? m_light_room4->m_estado = OFF : m_light_room4->m_estado = ON;
			}
		}
		if (m_monitor->mouseOver())
		{
			game->m_mousePress.play();
			m_monitor->m_estado == ON ? m_monitor->m_estado = OFF : m_monitor->m_estado = ON;
		}

	}

}

void GamePlay::draw()
{
	if (m_monitor->m_estado == ON)
	{
		switch (m_cameraNaTela)
		{
		case 0:
			m_cameraOff();
			break;
		case 1:
			if (m_room1->m_online)
			{
				m_sndCameraOff.stop();
				if (m_light_room1->m_estado == ON)
				{
					m_camera1.draw(0, 0);
				}
			}
			else
				m_cameraOff();
			break;
		case 2:
			if (m_room2->m_online)
			{
				m_sndCameraOff.stop();
				if (m_light_room2->m_estado == ON)
				{
					m_camera2.draw(0, 0);
				}
			}
			else
				m_cameraOff();
			break;
		case 3:
			m_cameraOff();
			break;
		case 4:
			if (m_room4->m_online)
			{
				m_sndCameraOff.stop();
				if (m_light_room4->m_estado == ON)
				{
					m_camera4.draw(0, 0);

				}
			}
			else
				m_cameraOff();
			break;
		}

		if (m_room1->m_online)
			m_room1->draw();
		if (m_room2->m_online)
			m_room2->draw();
		if (m_room4->m_online)
			m_room4->draw();
	}
	if (m_cameraTempoEfeitoTroca > 0)
	{
		m_cameraOff();
		m_cameraTempoEfeitoTroca -= ofGetLastFrameTime();
	}

	m_bg.draw(0, 0);

	if (m_cameraNaTela == 0)
	{
		m_luzVermelha.draw(310, 80);
	}

	if (m_monitor->m_estado == ON) // repetindo condicao para desenhar em cima
	{
		m_monitorHud.draw(0, 0);
		m_light_room0->draw();
		m_light_room1->draw();
		m_light_room2->draw();
		m_light_room3->draw();
		m_light_room4->draw();
	}

	m_monitor->draw();
	transicao->draw();

}

void GamePlay::m_cameraOff()
{

	if (m_sndCameraOff.isPlaying() == false)
	{
		m_sndCameraOff.play();
		m_sndCameraOff.setVolume(0.5f);
	}
	int temp;
	int x = 530;
	int y = 288;
	int size = 165;
	// Desenha os quadrados
	for (int i = 0; i < 3; i++)
	{
		ofSetColor(ofRandom(255));
		ofDrawRectangle(x, ofRandom(y, y + size), size, ofRandom(5, 60));
	}
	// Desenha as linhas
	for (int i = 0; i < 5; i++)
	{
		temp = ofRandom(size);
		ofSetColor(ofRandom(255));
		ofDrawLine(x, y + temp, x + size, y + temp);
	}
	// Desenha o ruido
	for (int i = 0; i < 170; i++)
	{
		ofSetColor(ofRandom(255));
		ofDrawRectangle(ofRandom(x, x + size), ofRandom(y, y + size), ofRandom(1, 2), ofRandom(1, 2));
	}

	ofSetColor(255);

}