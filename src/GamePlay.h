#pragma once
#include "ofMain.h"
#include "GameManager.h"

class GamePlay 
{
public:
	ofImage m_bg;
	ofSoundPlayer m_ambient;

	Transition *transicao;

	ofImage m_camera[3]; // imagem da camera que aparece no monitor
	ofImage m_monitorHud;
	ofImage m_luzVermelha;

	Button *m_room[5]; // Cameras
	Button *m_monitor; // Ligar e desligar o monitor
	Button *m_light_room[5]; // luz da sala

	void m_cameraOff(); // Desenha o efeito de Camera Desligada
	ofSoundPlayer m_sndCameraOff; // Som da statica
	float m_cameraTempoEfeitoTroca = 0; // Tempo para reproduzir o efeito de troca de camera

	GamePlay();
	~GamePlay();
	
	int m_cameraNaTela; // comeca sem nada mostrando, depois ou fica com a camera ou estatico

	void update(GameManager *game);
	void draw();

};

