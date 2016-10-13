#include "Button.h"

void Button::draw()
{
	if (m_drawIt)
	{
		if (m_estado == ON)
		{
			ofSetColor(255);
			ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
		}
		else
		{
			ofSetColor(255);
			ofDrawRectangle(m_x - (getW() / 2), m_y - (getH() / 2), getW(), getH());
			ofSetColor(0);
			ofDrawRectangle(m_x - (getW() / 2)+1, m_y - (getH() / 2)+1, getW()-2, getH()-2);
			ofSetColor(255);

		}

	}

}

bool Button::mouseOver()
{
	if (
		((ofGetMouseX() > m_x - (getW() / 2)) && (ofGetMouseX() < m_x + (getW() / 2))) &&
		((ofGetMouseY() > m_y - (getH() / 2)) && (ofGetMouseY() < m_y + (getH() / 2)))
		)
	{
		return true;
	}
	else
		return false;
}

Button::Button(int x, int y, int w, int h, bool desenheEle)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_drawIt = desenheEle;
}
Button::Button(int x, int y, int w, int h, bool desenheEle, bool estado)
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_drawIt = desenheEle;
	m_estado = estado;
}



