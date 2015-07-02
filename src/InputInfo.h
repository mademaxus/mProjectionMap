//
//  InputInfo.h
//  example
//
//  Created by Metalworks on 23/6/15.
//
//

#ifndef example_InputInfo_h
#define example_InputInfo_h

#include <string>
#include "CustomPiMapper.h"

struct InputInfo {
    std::string imagePath;
    std::string displayText;
    InputInfo(const std::string path, const std::string text){
        imagePath = CustomPiMapper::getInstance()->getPiMapper()->getMediaServer().getDefaultImageDir() + "/" + path;
        displayText = text;
    }
};

struct InputDisplay {
    int imageSurfaceId;
    int textSurfaceId;
    
    InputDisplay(int image, int text) : imageSurfaceId(image), textSurfaceId(text) { }
};

#endif
