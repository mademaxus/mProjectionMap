//
//  ColoredBgSource.h
//  example
//
//  Created by Metalworks on 25/6/15.
//
//
#pragma once

#ifndef __example__ColoredBgSource__
#define __example__ColoredBgSource__

#include "ofMain.h"
#include "FboSource.h"

class ColoredBgSource : public ofx::piMapper::FboSource {
public:
    ColoredBgSource(ofColor _color, std::string _name);
    // These are overrides of FboSource virtual functions.
    // FBO sources are not executing before they have been assigned to a surface.
    void setup();
    void update();
    void draw(); // You don't have to care about fbo.begin() or fbo.end() here
    
    void setDisplayText(std::string text);
    
private:
    ofColor newSourceColor;
    std::string displayText;
    int increment;
    int counter;
    int maxIncrement;
    
};

#endif /* defined(__example__ColoredBgSource__) */
