//
//  CustomPiMapper.cpp
//  example
//
//  Created by Metalworks on 25/6/15.
//
//  Singleton class that initializes and some settings
//	Initialized and destroyed by ofApp
//	Creates ofxPiMapper class
//	Creates 1 copy of all custom sources
//	Creates 5 differed colored bg source
//	Creates the font used in the projection map
//
//

#include "CustomPiMapper.h"

bool CustomPiMapper::instanceFlag = false;
CustomPiMapper* CustomPiMapper::instance = 0;

CustomPiMapper::CustomPiMapper()
{
    std::cout << "CustomPiMapper Created\n";

    customPiMapper = new ofxPiMapper();
    customSource = new CustomSource();
    textSource = new TextSource();
    blankSource = new BlankSource();

		// Store size of color array and current index pointer
    coloredBgSize = 5;
    coloredBgIndex = 0;
    coloredBgArr.push_back(new ColoredBgSource(ofColor(248,155,48), "Color 1 Bg Source"));
    coloredBgArr.push_back(new ColoredBgSource(ofColor(187,213,49), "Color 2 Bg Source"));
    coloredBgArr.push_back(new ColoredBgSource(ofColor(249,237,46), "Color 3 Bg Source"));
    coloredBgArr.push_back(new ColoredBgSource(ofColor(11,183,170), "Color 4 Bg Source"));
    coloredBgArr.push_back(new ColoredBgSource(ofColor(240,110,165), "Color 5 Bg Source"));
    
    colorArr.push_back(ofColor(248,155,48));
    colorArr.push_back(ofColor(187,213,49));
    colorArr.push_back(ofColor(249,237,46));
    colorArr.push_back(ofColor(11,183,170));
    colorArr.push_back(ofColor(240,110,165));
    
		// Font: Update the font in bin/data if required
		// Change font name in loadFont method
    displayFont = new ofTrueTypeFont();
    displayFont->loadFont("AldotheApache.ttf", 30);
}

CustomPiMapper::~CustomPiMapper(){
    instanceFlag = false;
    
    std::cout << "CustomPiMapper Destructor called\n";
    
    if(customPiMapper != 0){
        delete customPiMapper;
        customPiMapper = 0;
    }
    if(customSource != 0){
        delete customSource;
        customSource = 0;
    }
    if(textSource != 0){
        delete textSource;
        textSource = 0;
    }
		if(blankSource != 0){
			delete blankSource;
			blankSource = 0;
		}
    for(int i=0; i<coloredBgSize; i++){
        delete coloredBgArr.at(i);
        coloredBgArr[i] = 0;
    }
}

ofxPiMapper* CustomPiMapper::getPiMapper(){
    return customPiMapper;
}
CustomSource* CustomPiMapper::getCustomSource(){
    return customSource;
}
TextSource* CustomPiMapper::getTextSource(){
    return textSource;
}
BlankSource* CustomPiMapper::getBlankSource(){
    return blankSource;
}
// Get a ColoredBg according to the index pointer
// Automatically increases the index pointer to the next colour
ColoredBgSource* CustomPiMapper::getColoredBgSource(){
    ColoredBgSource* bg = coloredBgArr[coloredBgIndex];
    coloredBgIndex = (coloredBgIndex+1)%coloredBgSize;
    return bg;
}
// Get a specfic color according to the index pointer
// Automatically increases the index pointer to the next colour
ofColor CustomPiMapper::getColor(){
    ofColor color = colorArr[coloredBgIndex];
    coloredBgIndex = (coloredBgIndex+1)%coloredBgSize;
    return color;
}
int CustomPiMapper::getColoredBgSize(){
    return coloredBgSize;
}
int CustomPiMapper::getColoredBgIndex(){
    int index = coloredBgIndex;
    coloredBgIndex = (coloredBgIndex+1)%coloredBgSize;
    return index;
}
ofTrueTypeFont* CustomPiMapper::getFont(){
    return displayFont;
}
CustomPiMapper* CustomPiMapper::getInstance()
{
    if(! instanceFlag)
    {
        instance = new CustomPiMapper();
        instanceFlag = true;
        return instance;
    }
    else
    {
        return instance;
    }
}
void CustomPiMapper::deleteInstance()
{
    delete instance;
    instance = 0;
}
