//
//  CustomPiMapper.h
//  example
//
//  Created by Metalworks on 24/6/15.
//
//

#ifndef example_CustomPiMapper_h
#define example_CustomPiMapper_h

#include <vector>
#include "ofxPiMapper.h"
#include "CustomSource.h"
#include "TextSource.h"
#include "ColoredBgSource.h"
#include "BlankSource.h"

using namespace std;

class CustomPiMapper
{
private:
    static bool instanceFlag;
    static CustomPiMapper *instance;
    ofxPiMapper* customPiMapper;
    
    // By using a custom source that is derived from FboSource
    // you will be able to see the source listed in sources editor
    // Create the sources only once and re-use it in all surfaces
    CustomSource* customSource;
    TextSource* textSource;
    BlankSource* blankSource;

    int coloredBgSize;
    int coloredBgIndex;
    std::vector<ColoredBgSource*> coloredBgArr;
    std::vector<ofColor> colorArr;
    
    ofTrueTypeFont* displayFont;
    
    CustomPiMapper();
    ~CustomPiMapper();
    
public:
    static CustomPiMapper* getInstance();
    static void deleteInstance();
    ofxPiMapper* getPiMapper();
    CustomSource* getCustomSource();
    TextSource* getTextSource();
    BlankSource* getBlankSource();

    int getColoredBgSize();
    int getColoredBgIndex();
    ColoredBgSource* getColoredBgSource();
    ofColor getColor();
    
    ofTrueTypeFont* getFont();
};

#endif
