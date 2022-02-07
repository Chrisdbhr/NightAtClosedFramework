#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
	ofHideCursor();

	gameManager = new GameManager(GAME_MENU); // Tudo comecara no menu

	gameMenu = new GameMenu();
	gameWin = new GameWin();
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
	case GAME_WIN:
		gameWin->update(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->update(gameManager);
		break;
	case GAME_OVER:
		gameOver->update(gameManager);
		break;
	case GAME_RESET:
		gameMenu->reset();
		gamePlay->reset(gameManager);
		gameOver->reset();
		gameManager->gameState = GAME_MENU;
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
		gameMenu->draw(gameManager);
		break;
	case GAME_WIN:
		gameWin->draw(gameManager);
		break;
	case GAME_PLAY:
		gamePlay->draw(gameManager);
		break;
	case GAME_OVER:
		gameOver->draw();
		break;
	}

	gameManager->draw(); // O que o Game Manager desenhar, será desenhado em todas as cenas, útil para mouse e notificações/conquistas
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key){
	case OF_KEY_F2:
		gameManager->m_horas += 1;
	case OF_KEY_F3:
		gameManager->power -= 10;
	case OF_KEY_F4:
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	};
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

	//ofSetWindowShape(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
