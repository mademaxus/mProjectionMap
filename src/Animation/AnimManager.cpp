//
//  AnimManager.cpp
//  example
//
//  Created by Metalworks on 24/6/15.
//
//

#include "AnimManager.h"
#include "AnimInputInfo.h"

AnimManager::AnimManager(){
    inputInfoManager = new InputInfoManager();

		// Adds the AnimInputInfo class to the animation array
		// Each AnimInputInfo represents one image/text
    currentIndex = 0;
    animSetArr.push_back(new AnimInputInfo(inputInfoManager, 9000));
    animSetArr.push_back(new AnimInputInfo(inputInfoManager, 9000));
}

AnimManager::~AnimManager(){
    std::cout << "AnimManager Destructor called\n";
    if(inputInfoManager != 0){
        std::cout << "InputInfoManager destroyed\n";
        delete inputInfoManager;
        inputInfoManager = 0;
    }

    for(int i=0; i<animSetArr.size(); i++){
        std::cout << "AnimSet " << i << " destroyed\n";
        delete animSetArr[i];
        animSetArr[i] = 0;
    }
}

void AnimManager::setup(){
    animSetArr[currentIndex]->setup();
}
void AnimManager::draw(){
    AnimSet* animSet = animSetArr[currentIndex];
		
    if(animSet->getHasEnded()){
        currentIndex = (currentIndex+1)%animSetArr.size();
        animSetArr[currentIndex]->setup();
        std::cout << "New draw\n";
    }else{
        animSet->draw();
    }
		
	 	//animSet->draw();
}
