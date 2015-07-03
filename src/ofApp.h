#pragma once

#ifndef _example_ofApp_h
#define _example_ofApp_h

#include "ofMain.h"
#include "ofxPiMapper.h"
#include "ImageSource.h"
#include "CustomSource.h"
#include "AnimManager.h"

class ofApp : public ofBaseApp {
public:
    ofApp();
    virtual ~ofApp(); // virtual destructor to override ofBaseApp
    void setup();
    void draw();
    
private:
    ofxPiMapper* piMapper;
    AnimManager* animManager;

		void drawSurfaceId();
};
#endif
