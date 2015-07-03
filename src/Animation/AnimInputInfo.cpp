//
//  AnimInputInfo.cpp
//  example
//
//  Created by Metalworks on 24/6/15.
//
//

#include "AnimInputInfo.h"
#include "ColoredBgSource.h"
#include "TextSource.h"
#include "BlankSource.h"

/*******************
 ** PUBLIC
 ******************/

AnimInputInfo::AnimInputInfo(InputInfoManager* _inputInfoManager, int _duration) : AnimSet(_duration){
    piMapper = CustomPiMapper::getInstance()->getPiMapper();
    inputInfoManager = _inputInfoManager;
    userImage = new ofx::piMapper::ImageSource();
    
    reset();
    updateInterval = 15;
    surfacesSize = piMapper->getSurfaceManager().size(); // setup piMapper before calling size

    for(int i=0; i<surfacesSize; i++){
        shuffledSurfaceIdArr.push_back(i);
    }
    random_shuffle(shuffledSurfaceIdArr.begin(), shuffledSurfaceIdArr.end());
}
AnimInputInfo::~AnimInputInfo(){
    std::cout << "AnimInputInfo Destructor called\n";
    
    if(userImage != 0){
        delete userImage;
        userImage = 0;
    }
}

void AnimInputInfo::reset(){
    elapsedTime = ofGetElapsedTimeMillis();
    currentElapsedTime = ofGetElapsedTimeMillis();
    hasEnded = false;
    flyInNum = 0;
    canFlyIn = true;
    canFlyOut = false;
    piMapper->getMediaServer().clear();
}

void AnimInputInfo::updateInputInfo(){
    imagePath =  inputInfoManager->getCurrentInfo().imagePath;
    displayText = inputInfoManager->getCurrentInfo().displayText;
    imageSurfaceId = inputInfoManager->getCurrentDisplay().imageSurfaceId;
    textSurfaceId = inputInfoManager->getCurrentDisplay().textSurfaceId;
    inputInfoManager->increaseCurrentIndex();
}

void AnimInputInfo::flyIn(){
    // Perform flyIn animation only for number of surfaces
    if(flyInNum < surfacesSize){
        int shuffleIndex = shuffledSurfaceIdArr[flyInNum];
        ofx::piMapper::BaseSurface* surface = piMapper->getSurfaceManager().getSurface(shuffleIndex);
        if(imageSurfaceId == shuffleIndex){
            userImage->loadImage(imagePath);
            surface->setSource(userImage);
            
        }else if(textSurfaceId == shuffleIndex){
            // Set text for specific surface
            ofColor color = CustomPiMapper::getInstance()->getColor();
            TextSource* textSource = CustomPiMapper::getInstance()->getTextSource();
            textSource->setDisplayColor(CustomPiMapper::getInstance()->getColor());
            textSource->setDisplayText(displayText);
            surface->setSource(textSource);
            std::cout << "Surface Name: " << surface->getSource()->getName() << "\n";
            
        }else{
            ColoredBgSource* bgSource = CustomPiMapper::getInstance()->getColoredBgSource();
            surface->setSource(bgSource);
        }
        flyInNum++;
        currentElapsedTime = ofGetElapsedTimeMillis();
    }else{
        canFlyIn = false;
    }
}

void AnimInputInfo::flyOut(){
    // Perform flyOut animation only for number of surfaces
    if(flyInNum > 0){
        flyInNum--;
        
        int shuffleIndex = shuffledSurfaceIdArr[flyInNum];
        ofx::piMapper::BaseSurface* surface = piMapper->getSurfaceManager().getSurface(shuffleIndex);
        BlankSource* blankSource = CustomPiMapper::getInstance()->getBlankSource();
        surface->setSource(blankSource);
        
        // Change the value of duration so the flyout according to updateInterval
        currentElapsedTime = ofGetElapsedTimeMillis();
    }else{
        hasEnded = true;
    }
}


void AnimInputInfo::draw(){
    // Check for end of display duration to start flying out
    if(ofGetElapsedTimeMillis() - elapsedTime >= duration && !canFlyOut){
        canFlyOut = true;
    }else if(ofGetElapsedTimeMillis() - currentElapsedTime >= updateInterval){
        // Check if flyIn or flyOut animation should be played every update
        if(canFlyIn){
            flyIn();
        }else if(canFlyOut){
            flyOut();
        }
    }else{
        /*
        // Test Animation on the surface
        if(percentMoved < 1){
            percentMoved += 0.002;
            for(int j=0; j<surfacesSize; j++){
                if(imageSurfaceId == j){
                    continue;
                }
                
                ofx::piMapper::BaseSurface* surface = piMapper->getSurfaceManager().getSurface(j);
                
                for(int i=0; i<surface->getVertices().size(); i++){
                    ofVec3f point1 = surface->getVertices()[i];
                    ofVec3f point2 = surface->getVertices()[(i+1)%surface->getVertices().size()];
                    float x = (1-percentMoved)*point1.x + percentMoved*point2.x;
                    float y = (1-percentMoved)*point1.y + percentMoved*point2.y;
                    //std::cout << "X/Y: " << x << " | " << y;
                    //ofCircle(x, y, 3);
                }
            }
        }else{
            // percentMoved = 0;
        }
        */
    }
}

/*******************
 ** PRIVATE
 ******************/
void AnimInputInfo::setup(){
    
    std::cout << "New Setup\n";
    reset();
    updateInputInfo();
    
    if(userImage->isLoaded()){
        userImage->clear();
    }
    
    // Initialise to blank surfaces for fly in
    for(int j=0; j<surfacesSize; j++){
        ofx::piMapper::BaseSurface* surface = piMapper->getSurfaceManager().getSurface(j);
        BlankSource* blankSource = CustomPiMapper::getInstance()->getBlankSource();
        surface->setSource(blankSource);
    }
    
    percentMoved = 0.0;
}
