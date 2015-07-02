//
//  TextSource.h
//  example
//
//  Created by Metalworks on 30/6/15.
//
//

#ifndef __example__TextSource__
#define __example__TextSource__

#include "ofMain.h"
#include "FboSource.h"

class TextSource : public ofx::piMapper::FboSource {
public:
    TextSource();
    // These are overrides of FboSource virtual functions.
    // FBO sources are not executing before they have been assigned to a surface.
    void setup();
    void update();
    void draw(); // You don't have to care about fbo.begin() or fbo.end() here
    
    void setDisplayText(std::string text);
    void setDisplayColor(ofColor color);
    
private:
    ofColor newSourceColor;
    std::string displayText;
    int increment;
    int counter;
    int maxIncrement;
    
};

#endif /* defined(__example__TextSource__) */
