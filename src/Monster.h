#pragma once
#include "ofMain.h"
#include "GameManager.h"

#define M_MUDAR_DE_SALA 0
#define M_DESATIVAR_CAMERA 1
#define M_DESLIGAR_LUZ 2

class Monster
{
public:
	Monster::Monster(float dl,  GameManager *gm); // Recebe Delay o GameManager para alterar variaveis Globais.

	ofImage m_naCamera[5]; // Ele aparecendo nas cameras e na janela
	ofImage m_imgJumpscare; //animacao de susto 
	ofSoundPlayer m_noise;
	ofSoundPlayer m_jumpscare;
	int m_salaAtual = 3; // Qual sala esta
	float m_delay; // Um valor para atrasar o monstro, quanto maior mais fácil
	int m_acao; // IA Maquina de Estados. Cada numero é uma ação
	bool m_eMorreu = false; // No caso mostrar a jumpscare
	bool m_kill = false; // Valido para desenhar, se a variavel anterior ta ativada, em algum momento o jogador perde, tempo aleatorio para ficar mais imprevissivel

	void fazerBarulho();
	void update();
	void draw();
private:
	GameManager *game;
	float m_wait = 5.f; // Tempo de espera entre acoes (100.f)
};