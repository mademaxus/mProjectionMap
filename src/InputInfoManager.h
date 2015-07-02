//
//  InputInfoManager.h
//  example
//
//  Created by Metalworks on 23/6/15.
//
//
#include <vector>
#include "InputInfo.h"

#ifndef example_InputInfoManager_h
#define example_InputInfoManager_h

#define USER_INPUT_FILENAME "users.xml"

using namespace std;

class InputInfoManager {
public:
    InputInfoManager();
    ~InputInfoManager();
    InputInfo getCurrentInfo();
    InputDisplay getCurrentDisplay();
    InputInfo getInputInfo(int index);
    void increaseCurrentIndex();
    int getCurrentIndex();
    
private:
    int currentIndex;
    vector<InputInfo> inputInfoList;
    ofxXmlSettings xmlUserInput;
    
    int currentDisplayIndex;
    vector<InputDisplay> inputDisplayList;
    
};

#endif
