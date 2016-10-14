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

#define DURACAO_DA_NOITE 120 // No caso de cada hora

class GameManager
{

public:

	ofImage m_bg;
	ofImage m_bgMusic;

	ofImage m_mouse;

	ofSoundPlayer m_mousePress;

	int gameState;
	bool mouseFoiPressionado;
	int m_night = 1; // Noite que esta, influencia na dificuldade e mensagem do celular
	int m_horas = 0; // As "horas" vao passando  
	float m_minutos = DURACAO_DA_NOITE; // "minutos"
	int luzADesligar = 5; // 5 == nenhuma
	int cameraADesativar = 5; // 5 == nenhuma

	void update();
	void draw();  // O que o Game Manager desenhar, será desenhado em todas as cenas, útil para mouse e notificações/conquistas

	GameManager(int gs);

};

