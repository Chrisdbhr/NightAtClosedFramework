#pragma once
#include "ofMain.h"
#include "GameManager.h"

class Button
{
public:
	int m_x;
	int m_y;
	int m_width; // largura
	int m_height; // altura

	bool m_estado = true; // Interruptor, LIGADO(ON) ou DESLIGADO(OFF)
	bool m_online = true; // Valido para as cameras, se tiver online funciona
	bool m_drawIt; // Se vai desenhar o botao ou apenas detectar toque

	int getW() { return m_width; }; // retorna largura
	int getH() { return m_height; }; // retorn altura

	void draw();

	bool mouseOver(); // ver se o mouse esta em cima dele

	Button::Button(int x, int y, int w, int h, bool desenheEle);
	Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado);


};