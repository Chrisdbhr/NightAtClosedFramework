#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
	ofHideCursor();

	gameManager = new GameManager(GAME_MENU); // Tudo comecara no menu

	gameMenu = new GameMenu();
	gameConfigs = new GameConfigs();
	gamePlay = new GamePlay(gameManager);
	gameOver = new GameOver();

}

//--------------------------------------------------------------
void ofApp::update(){

	switch (gameManager->gameState)
	{
	case GAME_MENU:
		gameMenu->update(gameManager);
		break;
	case GAME_CONFIG:
		gameConfigs->update(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->update(gameManager);
		break;
	case GAME_OVER:
		gameOver->update(gameManager);
		break;
	}
	
	// Se passou por todos os updates e ninguem usou o clique do mouse, anula o BOOL para simular um clique 
	// ao inves de deixar ligado, pois seria um "SEGURANDO BOTAO DO MOUSE"
	gameManager->mouseFoiPressionado = false; 
}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (gameManager->gameState)
	{
	case GAME_MENU:
		gameMenu->draw();
		break;
	case GAME_CONFIG:
		gameConfigs->draw();
		break;
	case GAME_PLAY:
		gamePlay->draw();
		break;
	case GAME_OVER:
		gameOver->draw();
		break;
	}

	gameManager->draw(); // O que o Game Manager desenhar, será desenhado em todas as cenas, útil para mouse e notificações/conquistas
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	gameManager->mouseFoiPressionado = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
