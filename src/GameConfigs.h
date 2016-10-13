#pragma once
#include "ofMain.h"
#include "GameManager.h"

class GameConfigs 
{

public:
	
	GameConfigs();
	~GameConfigs();
	void update(GameManager *game);
	void draw();
};

