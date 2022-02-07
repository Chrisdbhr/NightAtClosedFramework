#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	ofGLFWWindowSettings settings;
	settings.glVersionMajor = 3;
	settings.glVersionMinor = 2;
	settings.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	settings.setPosition(glm::vec2(320, 240));
	settings.windowMode = OF_WINDOW;
	settings.multiMonitorFullScreen = false;
	ofCreateWindow(settings);
	//ofSetupOpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
