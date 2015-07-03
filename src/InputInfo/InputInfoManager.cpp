//
//  InputInfoManager.cpp
//  example
//
//  Created by Metalworks on 23/6/15.
//
//

#include <stdio.h>

#include "InputInfoManager.h"

/*
 * Stores and manages all the InputInfo specified by the user
 * Created by AnimManager to be passed to different animation sets
 */

InputInfoManager::InputInfoManager(){
	// load xmlFiles
	loadUserInputXml();

	// Initialise images and display text
	currentIndex = 0;

	// Initialise displayable surfaces, InputDisplay(imageSurfaceId, textSurfaceId)
	// Manually configure texture map for images/text surface
	currentDisplayIndex = 0;
	inputDisplayList.push_back(InputDisplay(1, 0));
	inputDisplayList.push_back(InputDisplay(5, 6));
	inputDisplayList.push_back(InputDisplay(12, 14));
	inputDisplayList.push_back(InputDisplay(18, 16));
	inputDisplayList.push_back(InputDisplay(4, 2));
	inputDisplayList.push_back(InputDisplay(8, 6));
	inputDisplayList.push_back(InputDisplay(10, 9));
}

InputInfoManager::~InputInfoManager(){
	inputInfoList.clear();
	std::cout << "InputInfoManager Destructor called\n";
}

void InputInfoManager::loadUserInputXml(){
	//Attempt to load file from XML
	if(!xmlUserInput.loadFile(USER_INPUT_FILENAME)){
		ofLogWarning("InputInfoManager") << "Could not load XML user input file at " << USER_INPUT_FILENAME;
	}else{
		// Load XML File to inputInfoList
		xmlUserInput.pushTag("users");
		int numOfUsers = xmlUserInput.getNumTags("user");
		for(int i=0; i<numOfUsers; i++){
			xmlUserInput.pushTag("user", i);

			std::string imagePath = xmlUserInput.getValue("image", "");
			std::string displayText = xmlUserInput.getValue("text", "");

			if(imagePath != "" && displayText != ""){
				inputInfoList.push_back(InputInfo(imagePath, displayText));
			}

			xmlUserInput.popTag();
		}
		xmlUserInput.popTag();
	}
}

InputInfo InputInfoManager::getCurrentInfo(){
	if (inputInfoList.size() == 0){
		return InputInfo("", "");
	}
	return inputInfoList.at(currentIndex);
}
InputDisplay InputInfoManager::getCurrentDisplay(){
	if (inputDisplayList.size() == 0){
		return InputDisplay(0, 0);
	}
	return inputDisplayList.at(currentDisplayIndex);
}

InputInfo InputInfoManager::getInputInfo(int index){
	if (inputInfoList.size() == 0){
		return InputInfo("", "");
	}
	return inputInfoList.at(index);
}

void InputInfoManager::increaseCurrentIndex(){
	currentIndex = (currentIndex+1)%inputInfoList.size();
	currentDisplayIndex = (currentDisplayIndex+1)%inputDisplayList.size();
}

int InputInfoManager::getCurrentIndex(){
	return currentIndex;
}
