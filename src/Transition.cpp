#include "Transition.h"

Transition::Transition()
{
	m_snd.loadSound("sounds/static.mp3");

}

void Transition::draw()
{
	if (m_duracaoDaTransicao <= 0)
	{
		m_snd.stop();

	}
	else
	{
		if (m_snd.isPlaying() == false)
			m_snd.play();

		int temp;
		// Desenha os quadrados
		for (int i = 0; i < 3; i++)
		{
			ofSetColor(ofRandom(255));
			ofDrawRectangle(0, ofRandom(10, 250), ofGetWindowWidth(), ofRandom(ofGetWindowHeight()));
		}
		// Desenha as linhas
		for (int i = 0; i < 5; i++)
		{
			temp = ofRandom(ofGetWindowHeight());
			ofSetColor(ofRandom(255));
			ofDrawLine(0, temp, ofGetWindowWidth(), temp);
		}
		// Desenha o ruido
		for (int i = 0; i < 2000; i++)
		{
			ofSetColor(ofRandom(255));
			ofDrawRectangle(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(1, 5), ofRandom(1, 5));
		}

		m_duracaoDaTransicao -= ofGetLastFrameTime();
		ofSetColor(255);
	}
}