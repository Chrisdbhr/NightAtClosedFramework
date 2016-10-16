#include "GameManager.h"

GameManager::GameManager(int gs)
{
	gameState = gs;
	m_mouse.loadImage("images/mouse.png");
	m_mousePress.loadSound("sounds/mousePress.mp3");
}

void GameManager::update()
{

}

void GameManager::draw()  // O que o Game Manager desenhar, ser� desenhado em todas as cenas, �til para mouse e notifica��es/conquistas
{
	m_mouse.draw(ofGetMouseX(), ofGetMouseY());
}