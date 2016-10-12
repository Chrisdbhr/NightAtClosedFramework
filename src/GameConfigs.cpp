#include "GameConfigs.h"



GameConfigs::GameConfigs()
{

}


GameConfigs::~GameConfigs()
{

}
void GameConfigs::update()
{
	
}

void GameConfigs::draw()
{
	if (ofGetMousePressed())
	{
		ofDrawCircle(100, 100, 100);
	};

}