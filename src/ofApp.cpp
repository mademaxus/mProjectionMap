#include "ofApp.h"
#include "CustomPiMapper.h"

ofApp::~ofApp(){
    std::cout << "ofApp Destructor called\n";
    
    if(animManager != 0){
        delete animManager;
        animManager = 0;
    }
    
    // Delete the CustomPiMapper settings singleton
    if(CustomPiMapper::getInstance() != 0){
        CustomPiMapper::deleteInstance();
    }
}

void ofApp::setup() {
    ofBackground(0);

    // Add our CustomSource to list of fbo sources of the piMapper
    // FBO sources should be added before piMapper.setup() so the
    // piMapper is able to load the source if it is assigned to
    // a surface in XML settings.
    piMapper->addFboSource(*CustomPiMapper::getInstance()->getCustomSource());
    piMapper->addFboSource(*CustomPiMapper::getInstance()->getTextSource());
    
    // Setup colored bg
    for(int i=0; i<CustomPiMapper::getInstance()->getColoredBgSize(); i++){
        piMapper->addFboSource(*CustomPiMapper::getInstance()->getColoredBgSource());
    }
    
    piMapper->setup();
    piMapper->getMediaServer().clear(); // clears the previous loaded sources
    
		// Must be called after piMapper setup
		animManager = new AnimManager();
    animManager->setup();
}

void ofApp::draw() {
    animManager->draw();
    piMapper->draw();
		// Uncomment to display surface Ids
		// drawSurfaceId();
}

// Displays surfaceId to be used for debugging
void ofApp::drawSurfaceId() {
	for(int i=0; i<piMapper->getSurfaceManager().size(); i++){
		stringstream ss;
		ss << i;
		ofPoint point = piMapper->getSurfaceManager().getSurface(i)->getHitArea().getCentroid2D();
		CustomPiMapper::getInstance()->getFont()->drawString(ss.str(), point.x, point.y);
	}
}
