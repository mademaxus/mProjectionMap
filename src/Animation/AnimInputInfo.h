//
//  AnimInputInfo.h
//  example
//
//  Created by Metalworks on 24/6/15.
//
//

#ifndef __example__AnimInputInfo__
#define __example__AnimInputInfo__

#include <stdio.h>
#include <string>

using namespace std;

#include <vector>
#include "InputInfoManager.h"
#include "AnimSet.h"
#include "ofxPiMapper.h"
#include "CustomPiMapper.h"

/****
 ** Displays an image, a text and animations on other frames
 ** Has a flyIn and flyOut method to draw enter and exit animations
 **/

class AnimInputInfo : public AnimSet{
public:
    AnimInputInfo(InputInfoManager* _inputInfoManager, int _duration);
    virtual ~AnimInputInfo();
    void setup();
    void draw();
    
private:
    ofxPiMapper* piMapper;
    InputInfoManager* inputInfoManager;
    ofx::piMapper::ImageSource* userImage;

    string imagePath;
    string displayText;
    int imageSurfaceId, textSurfaceId;
    float percentMoved;
    
    // Used to track animation within this class
    int flyInNum, updateInterval, surfacesSize, currentElapsedTime;
    bool canFlyIn, canFlyOut;
    vector<int> shuffledSurfaceIdArr;
    
    void flyIn();
    void flyOut();
    void reset();
    void updateInputInfo();
};
#endif /* defined(__example__AnimInputInfo__) */
