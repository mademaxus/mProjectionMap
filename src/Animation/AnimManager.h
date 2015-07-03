//
//  AnimManager.h
//  example
//
//  Created by Metalworks on 24/6/15.
//
//

#ifndef __example__AnimManager__
#define __example__AnimManager__

#include <stdio.h>
#include <vector>
#include "AnimInputInfo.h"
#include "ofxPiMapper.h"
#include "InputInfoManager.h"

/****
 ** Manages all the animation sets
 ** Plays the next animation set after the first one has ended
 **/

class AnimManager{
public:
    AnimManager();
    ~AnimManager();
    
    void setup();
    void draw();
    
private:
    int currentIndex;
    
    InputInfoManager* inputInfoManager;
    std::vector<AnimSet*> animSetArr;
};

#endif /* defined(__example__AnimManager__) */
