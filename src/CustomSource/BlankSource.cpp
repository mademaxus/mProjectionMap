//
//  BlankSource.cpp
//  example
//
//  Created by Metalworks on 2/7/15.
//
//

#include "BlankSource.h"

BlankSource::BlankSource() : ofx::piMapper::FboSource(){
    // Give our source a decent name
    name = "Blank Source";
}

// Don't do any drawing here
void BlankSource::setup() {
    // Allocate our FBO source, decide how big it should be
    allocate(10, 10);
}

// Don't do any drawing here
void BlankSource::update() {
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void BlankSource::draw() {
		// Black background only
    ofClear(255);
}
