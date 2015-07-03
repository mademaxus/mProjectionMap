//
//  InputInfoManager.h
//  example
//
//  Created by Metalworks on 23/6/15.
//
//

#ifndef example_InputInfoManager_h
#define example_InputInfoManager_h

/*
 * Stores and manages all the InputInfo specified by the user
 * Created by AnimManager to be passed to different animation sets
 */

#define USER_INPUT_FILENAME "users.xml"

#include <vector>
#include "InputInfo.h"

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
    int currentIndex,currentDisplayIndex;
    vector<InputInfo> inputInfoList;
    ofxXmlSettings xmlUserInput;
    
    vector<InputDisplay> inputDisplayList;
    
		void loadUserInputXml();
};

#endif
