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

void GameManager::draw()  // O que o Game Manager desenhar, será desenhado em todas as cenas, útil para mouse e notificações/conquistas
{
	m_mouse.draw(ofGetMouseX(), ofGetMouseY());
}