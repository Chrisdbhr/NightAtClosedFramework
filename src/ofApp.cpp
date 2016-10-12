#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	scene = new Scene();
	gameMenu = new GameMenu();
	gameConfigs = new GameConfigs();
	gamePlay = new GamePlay();
	gameOver = new GameOver();

}

//--------------------------------------------------------------
void ofApp::update(){
	switch (gameState)
	{
	case GAME_MENU:
		gameMenu->update();
		break;
	case GAME_CONFIG:
		gameConfigs->update();
		break;
	case GAME_PLAY:
		gamePlay->update();
		break;
	case GAME_OVER:
		gameOver->update();
		break;
	}


}

//--------------------------------------------------------------
void ofApp::draw(){
	switch (gameState)
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
