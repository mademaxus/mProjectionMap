//
//  AnimSet.h
//  example
//
//  Created by Metalworks on 24/6/15.
//
//

#ifndef __example__AnimSet__
#define __example__AnimSet__

#include <stdio.h>
#include "ofxPiMapper.h"

/****
 ** AnimationSet abstract class cannot be initialized
 ** Can be a pointer, AnimSet* varName
 ** This class is extended to display different animation types
 **/

class AnimSet{
public:
    AnimSet(int _duration) : duration(_duration), hasEnded(false) {
        elapsedTime = ofGetElapsedTimeMillis();
    }
    virtual ~AnimSet() { }
    int getDuration()   { return duration; }
    bool getHasEnded()  { return hasEnded; }
    virtual void setup() { }
    virtual void draw() = 0; // abstract virtual fn must be overrided
    
protected:
    int duration; // specify duration of the main animation
    bool hasEnded; // check if this animation set has ended
    int elapsedTime; // store how much time has elapsed
};

#endif /* defined(__example__AnimSet__) */
