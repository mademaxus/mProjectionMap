//
//  ColoredBgSource.cpp
//  example
//
//  Created by Metalworks on 25/6/15.
//
//

#include "ColoredBgSource.h"
#include "CustomPiMapper.h"

ColoredBgSource::ColoredBgSource(ofColor _color, std::string _name) : ofx::piMapper::FboSource(){
    newSourceColor = _color;
    increment = 1;
    counter = 0;
    maxIncrement = ofRandom(15, 30);
    
    // Give our source a decent name
    name = _name;
}

void ColoredBgSource::setDisplayText(std::string text){
    displayText = text;
}

// Don't do any drawing here
void ColoredBgSource::setup() {
    // Allocate our FBO source, decide how big it should be
    allocate(200, 200);
}

// Don't do any drawing here
void ColoredBgSource::update() {
    newSourceColor += increment;
    counter++;
    
    // Flashing effect
    if(counter == maxIncrement){
        counter = 0;
        increment *= -1;
    }
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void ColoredBgSource::draw() {
    // Fill FBO with our rects
    ofClear(0);
    ofFill();
    
    // Sets buffer to the specified color and fills it
    ofClear(newSourceColor);
    
    // If the a text should be shown display it
    if(!displayText.empty()){
        ofSetColor(0);
        CustomPiMapper::getInstance()->getFont()->drawString(displayText, 10, 100);
    }
    
    ofSetColor(255);
}
