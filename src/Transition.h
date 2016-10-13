#pragma once
#include "ofMain.h"
#include "GameManager.h"

class Transition
{
public:
	Transition::Transition();

	ofSoundPlayer m_snd;
	void draw();
	float m_duracaoDaTransicao = 1.1f; // duracao do efeito, definir para > 0 recomeca o efeito
private:
	float m_velocidade = 0.05f; // Velocidade da transicao 
};