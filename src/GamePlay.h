#pragma once
#include "ofMain.h"
#include "GameManager.h"
#include "Monster.h"

#define CONSUMO_MINIMO 0.01f

class GamePlay
{
public:
	ofTrueTypeFont horas;

	ofImage m_bg;
	ofImage m_bg_off;
	ofSoundPlayer m_ambient;

	ofImage m_powerBg;
	ofImage m_powerBar;
	float m_powerTime; // Contador para o tempo ir diminuindo, a cada 1 segundo ele consome m_powerRate de energia
	float m_powerRate; // Quantidade de energia que esta sendo utilizada e sera descontada
	ofSoundPlayer m_snd_powerOff;
	float calcularConsumoDeEnergia();

	Transition *transicao;

	ofImage m_camera[3]; // imagem da camera que aparece no monitor
	ofImage m_monitorHud;
	ofImage m_luzVermelha; //detalhe

	Button *m_celular; // Ver mensagem do celular
	float m_celularTempoParaTocar;
	ofSoundPlayer m_celularSnd;
	ofSoundPlayer m_celularVoice;

	Button *m_room[5]; // Cameras
	Button *m_monitor; // Ligar e desligar o monitor
	Button *m_light_room[5]; // luz da sala

	void m_cameraOff(); // Desenha o efeito de Camera Desligada
	ofSoundPlayer m_sndCameraOff; // Som da statica
	float m_cameraTempoEfeitoTroca; // Tempo para reproduzir o efeito de troca de camera

	GamePlay(GameManager *game);
	~GamePlay();

	int m_cameraNaTela; // comeca sem nada mostrando, depois ou fica com a camera ou estatico

	Monster *monstro;

	void update(GameManager *game);
	void draw(GameManager *game);
	void reset(GameManager *game);
};

