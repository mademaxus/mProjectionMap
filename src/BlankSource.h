//
//  BlankSource.h
//  example
//
//  Created by Metalworks on 2/7/15.
//
//

#ifndef __example__BlankSource__
#define __example__BlankSource__

#include "ofMain.h"
#include "FboSource.h"

class BlankSource : public ofx::piMapper::FboSource {
public:
    BlankSource();
    // These are overrides of FboSource virtual functions.
    // FBO sources are not executing before they have been assigned to a surface.
    void setup();
    void update();
    void draw(); // You don't have to care about fbo.begin() or fbo.end() here
    
};

#endif /* defined(__example__BlankSource__) */
