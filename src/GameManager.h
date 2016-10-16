#pragma once
#include "ofMain.h"
#include "Button.h"
#include "Transition.h"

#define GAME_MENU 0
#define GAME_WIN 1
#define GAME_PLAY 2
#define GAME_OVER 3
#define GAME_RESET 4 // Reseta algumas variaveis para rejogabilidade
 
#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

#define ON true
#define OFF false

#define DURACAO_DA_NOITE 120 // No caso de cada hora
#define QUANTIDADE_DE_ENERGIA_INICIAL 100.f // Quanto de energia comeca

#define DEBUG

class GameManager
{

public:
	ofImage m_bg;

	ofImage m_mouse;

	ofSoundPlayer m_mousePress;

	int gameState; // Qual cena esta
	bool mouseFoiPressionado;
	int m_night = 1; // Noite que esta, influencia na dificuldade e mensagem do celular
	int m_horas = 0; // As "horas" q vao passando  
	float m_minutos = DURACAO_DA_NOITE; // duracao dos "minutos"
	int luzADesligar = 5; // 5 == nenhuma
	int cameraADesativar = 5; // 5 == nenhuma
	float power; // Quantidade de energia da noite
	bool powerOff = false; // Se acabou a energia

	void update();
	void draw();  // O que o Game Manager desenhar, será desenhado em cima de todas as cenas, útil para mouse e notificações/conquistas

	GameManager(int gs);

};

