#pragma once
#include "ofMain.h"
#include "GameManager.h"

#define M_MUDAR_DE_SALA 0
#define M_DESATIVAR_CAMERA 1
#define M_DESLIGAR_LUZ 2

class Monster
{
public:
	Monster::Monster(float dl,  GameManager *game); // Recebe Delay o GameManager para alterar variaveis Globais.

	ofImage m_naCamera[6]; // Ele aparecendo nas cameras e na janela
	ofImage m_imgJumpscare; //animacao de susto 
	ofSoundPlayer m_noise;
	ofSoundPlayer m_jumpscare;
	int m_salaAtual; // Qual sala esta
	float m_delay; // Um valor para atrasar o monstro, quanto maior mais lento ele é
	int m_acao; // IA Maquina de Estados. Cada numero é uma ação
	bool m_eMorreu; // No caso mostrar a jumpscare
	bool m_kill; // Valido para desenhar, se a variavel anterior ta ativada, em algum momento o jogador perde, tempo aleatorio para ficar mais imprevissivel

	int animFrameAtual; //Qual frame da animação esta
	int animFrameTotal; //Quantos frames tem a animacao 
	float animTempo; //Contador de tempo decorrido da animacao

	float tempoParaDarGameOver; //Quanto tempo com o monstro na tela para dar GameOver

	void fazerBarulho();

	void update(GameManager *game);
	void draw();
	void reset(); // Setar/resetar as variaveis com valores iniciais
private:
	float m_wait; // Tempo de espera entre acoes (Deve começar com 100.f para demorar para começar a agir)



};