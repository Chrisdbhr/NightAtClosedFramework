#include "GameMenu.h"



GameMenu::GameMenu()
{
}


GameMenu::~GameMenu()
{
}
void GameMenu::update()
{

}

void GameMenu::draw()
{
	if (ofGetMousePressed())
	{
		ofDrawCircle(100, 100, 100);
		FILE *arq;
		arq = fopen("bin/data/save.txt", "w");
		fputs("teste", arq);
		fclose(arq);

	};

}