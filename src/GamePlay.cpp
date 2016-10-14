#include "GamePlay.h"

GamePlay::GamePlay(GameManager *gm)
{
	game = gm;
	horas.loadFont("cour.ttf", 12, true);

	m_ambient.loadSound("sounds/ambient.mp3");
	m_sndCameraOff.loadSound("sounds/static.mp3");
	m_celularSnd.loadSound("sounds/phone.mp3");
	m_celularSnd.setPan(-0.8f);

	m_bg.loadImage("images/bg_play.png");

	m_camera[0].loadImage("images/camera1.png");
	m_camera[1].loadImage("images/camera2.png");
	m_camera[2].loadImage("images/camera4.png");
	m_monitorHud.loadImage("images/monitorHud.png");
	m_luzVermelha.loadImage("images/luzVermelha.png");

	transicao = new Transition();
	// Botoes para clicar e mostrar a imagem da camera
	m_room[0] = new Button(750, 430, 28, 28, true, ON);
	m_room[0]->m_online = false;
	m_room[1] = new Button(707, 422, 26, 28, true, ON);
	m_room[2] = new Button(724, 381, 46, 26, true, ON);
	m_room[3] = new Button(795, 380, 36, 26, true, ON);
	m_room[3]->m_online = false;
	m_room[4] = new Button(795, 415, 34, 26, true, ON);

	m_monitor = new Button(819, 461, 12, 12, true, OFF);
	m_celular = new Button(455, 514, 57, 62, true, OFF);

	// Botoes de ligar e desligar as luzes
	m_light_room[0] = new Button(745, 345, 11, 11, true, ON);
	m_light_room[1] = new Button(745 + 18, 345, 11, 11, true, OFF);
	m_light_room[2] = new Button(745 + 36, 345, 11, 11, true, OFF);
	m_light_room[3] = new Button(745 + 54, 345, 11, 11, true, OFF);
	m_light_room[4] = new Button(745 + 72, 345, 11, 11, true, OFF);

	//Monstro
	monstro = new Monster(3, game);
}

GamePlay::~GamePlay()
{

}

void GamePlay::update(GameManager *game)
{

	if (m_ambient.isPlaying() == false)
		m_ambient.play();

	if (m_celularVoice.isPlaying() == false)
		if (m_celular->m_online == OFF) // Aqui uso a variavel online para ver se apertou no celular ou nao
			m_celular->m_estado = OFF;

	game->m_minutos -= ofGetLastFrameTime();
	if (game->m_minutos < 0)
	{
		game->m_horas++;
		game->m_minutos = DURACAO_DA_NOITE;
	}

	if (m_celular->m_online == ON)
	{
		if (m_celularTempoParaTocar < 0)
		{
			m_celular->m_estado == ON ? m_celular->m_estado = OFF : m_celular->m_estado = ON;
			m_celularTempoParaTocar = 2.6f;
			if (m_celular->m_estado == ON)
			{
				m_celularSnd.play();
			}
		}
		else
		{
			m_celularTempoParaTocar -= ofGetLastFrameTime();
		}
	}

	if (game->mouseFoiPressionado)
	{

		if (m_celular->mouseOver())
		{
			if (m_celular->m_online == ON) // Aqui uso a variavel online para ver se apertou no celular ou nao
			{
				m_celular->m_estado = ON;
				m_celularSnd.stop();
				std::string voz;
				voz.erase();
				voz.append("sounds/voice");
				voz.append(ofToString(game->m_night));
				voz.append(".mp3");
				m_celularVoice.loadSound(voz);
				m_celularVoice.setPan(-0.8f);
				m_celularVoice.play();
				m_celular->m_online = OFF;

			}
		}

		if (m_monitor->m_estado == ON)
		{
			for (int i = 0; i < 5; i++)
			{
				if (m_room[i]->mouseOver())
				{
					game->m_mousePress.play();
					m_cameraNaTela = i;
					m_cameraTempoEfeitoTroca = 0.2f;
				}

			}
			if (m_light_room[0]->mouseOver())
			{
				game->m_mousePress.play();
				if (m_light_room[0]->m_estado == ON) // se ta ligado, desliga
				{
					m_bg.loadImage("images/bg_play_off.png");
					m_light_room[0]->m_estado = OFF;
					m_ambient.setVolume(0.5f);
				}
				else
				{
					m_bg.loadImage("images/bg_play.png");
					m_light_room[0]->m_estado = ON;
					m_ambient.setVolume(1.f);
				}

			}
			for (int i = 1; i < 5; i++)
			{
				if (m_light_room[i]->mouseOver())
				{
					game->m_mousePress.play();
					m_light_room[i]->m_estado == ON ? m_light_room[i]->m_estado = OFF : m_light_room[i]->m_estado = ON;
				}
			}
		}
		if (m_monitor->mouseOver())
		{
			game->m_mousePress.play();
			m_monitor->m_estado == ON ? m_monitor->m_estado = OFF : m_monitor->m_estado = ON;
			m_sndCameraOff.stop();
		}

	}
	//-----------------
	// Monstro
	//-----------------
	monstro->update();
	if (monstro->m_salaAtual == 0 && m_light_room[0]->m_estado == OFF) // se ta na sala do jogador e a luz ta apagada: se fudeu
	{
		monstro->m_eMorreu = true;
	}

	if (m_cameraNaTela == monstro->m_salaAtual)
	{
		if (m_light_room[m_cameraNaTela]->m_estado == ON)
		{
			m_cameraTempoEfeitoTroca = 0.1f;
			monstro->m_noise.stop();
		}
	}
	if (game->luzADesligar != 5)
	{
		game->m_mousePress.play();
		m_light_room[game->luzADesligar]->m_estado = OFF;
		game->luzADesligar = ofRandom(1, 4);
		m_light_room[game->luzADesligar]->m_estado = OFF;
		game->luzADesligar = 5;
	}
	if (game->cameraADesativar != 5)
	{
		m_room[1]->m_online = ON;
		m_room[2]->m_online = ON;
		m_room[4]->m_online = ON;
		m_room[game->cameraADesativar]->m_online = OFF;
		game->cameraADesativar = 5;
	}
}

void GamePlay::draw()
{
	if (m_celular->m_estado == ON)
	{
		m_celular->draw();
	}

	if (m_monitor->m_estado == ON)
	{
		switch (m_cameraNaTela)
		{
		case 0:
			m_cameraOff();
			break;
		case 1:
			if (m_room[1]->m_online)
			{
				m_sndCameraOff.stop();
				if (m_light_room[1]->m_estado == ON)
				{
					m_camera[0].draw(0, 0);
				}
			}
			else
				m_cameraOff();
			break;
		case 2:
			if (m_room[2]->m_online)
			{
				m_sndCameraOff.stop();
				if (m_light_room[2]->m_estado == ON)
				{
					m_camera[1].draw(0, 0);
				}
			}
			else
				m_cameraOff();
			break;
		case 3:
			m_cameraOff();
			break;
		case 4:
			if (m_room[4]->m_online)
			{
				m_sndCameraOff.stop();
				if (m_light_room[4]->m_estado == ON)
				{
					m_camera[2].draw(0, 0);

				}
			}
			else
				m_cameraOff();
			break;
		}

		for (int i = 0; i < 5; i++)
		{
			if (m_room[i]->m_online)
				m_room[i]->draw();

		}
	}
	//------------------------------
	// Monstro
	//------------------------------
	//Mostra ele nas cameras
	if (m_monitor->m_estado == ON)
	{
		if (m_cameraNaTela == monstro->m_salaAtual)
		{
			if (m_light_room[monstro->m_salaAtual]->m_estado == ON)
			{
				if (m_room[m_cameraNaTela]->m_online)
				{
					monstro->m_naCamera[monstro->m_salaAtual].draw(0, 0);

				}
			}
		}
	}
	if (m_light_room[0]->m_estado == ON)
	{
		if (monstro->m_salaAtual == 5)
			monstro->m_naCamera[5].draw(0, 0);
	}

	if (m_cameraTempoEfeitoTroca > 0)
	{
		m_cameraOff();
		m_cameraTempoEfeitoTroca -= ofGetLastFrameTime();
	}
	//------------------------------
	m_bg.draw(0, 0);
	//------------------------------

	if (m_cameraNaTela == 0)
	{
		m_luzVermelha.draw(310, 80);
	}

	if (m_monitor->m_estado == ON) // repetindo condicao para desenhar em cima
	{
		m_monitorHud.draw(0, 0);
		horas.drawString(ofToString(game->m_horas), 640, 445);
		for (int i = 0; i < 5; i++)
		{
			m_light_room[i]->draw();
		}

	}

	m_monitor->draw();

	//------------------------------
	transicao->draw();
	monstro->draw(); // Se precisar desenhar o jumpscare
}

void GamePlay::m_cameraOff()
{

	if (m_sndCameraOff.getIsPlaying())
	{
		// ué?
	}
	else
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