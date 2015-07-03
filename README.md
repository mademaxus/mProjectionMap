#Maxus Singapore Projection Map
Projection mapping for the art installation in Maxus Singapore. The program is developed in C++ using the openFrameworks library. It is developed to run on the Raspberry PI 2.0 running on the Rapsbian operating system.

##Installation Instructions
The instructions below are a guide to setting up the projection mapping program on the Raspberry PI 2.0. The PI 2.0 is chosen over the PI B+ for its increased processing power. 

###1. Install Raspbian OS
Download the NOOBS installation package and upload it to a micro SD card for the PI. 
You may find the download at https://www.raspberrypi.org/downloads/.

Follow the instructions found in: https://www.raspberrypi.org/help/noobs-setup/

Once you have installed the Raspbian OS, boot into your Raspberry PI for the first time. The default username is **pi** and the default password is **raspberry**. Enter the following commands to configure your Raspberry PI:

````linux
sudo raspi-config
````
1. Select 8: Advanced Options
2. Select 3: Memory Split
3. Enter 128
4. Enter and exit config

At the terminal, run the reboot command.
````linux
sudo reboot
````

The firmware has to be updated to prevent the keyboard and mouse inputs from being unresponsive. Note that this may take some time. Enter the following commands:
````linux
sudo apt-get clean
sudo apt-get update
sudo apt-get upgrade
````

###2. Install OpenFrameworks and Addon libraries
ofxPiMapper is an Open Frameworks addon that is developed to create projection maps using the Raspberry PI. The ofxPiMapper github page has a comprehensive installation guide.

ofxPiMapper Github: https://github.com/kr15h/ofxPiMapper

Raspberry 2 OpenFramework Setup Guide: http://forum.openframeworks.cc/t/raspberry-pi-2-setup-guide/18690

Note that compiling the codes on the Raspberry PI may take a long time. You may attempt to try cross compiling the program however the process to do so is challenging.

###3. Install mProjectionMap
Once you have verified that an example is running, you are ready to begin running the projection mapping program. **OF_ROOT** shall refer to the root directory of the Open Frameworks library for the rest of this document.

````linux
cd OF_ROOT/apps/myApps/
git clone https://github.com/mademaxus/mProjectionMap.git
````

_Note that any project that uses the Open Framework library must be at **exactly 3** levels below OF_ROOT_

At the root directory of mProjectionMap, run the _make_ command to compile the program.

Once the program has been compiled without any errors, run _make run_ to run the program.

## Development Instructions
ofxPiMapper does not have any API documentations. This is typically the case for all openFrameworks addons.
If you have any doubts about a particular class or wish to find out about the API, open the ofxPiMapper source files located at _OF_ROOT/addons/ofxPiMapper/src_.

###1. Brief Overview
The design of the program consists of 4 main components:
1. CustomSource: Creates different custom sources that is mapped onto each surface
2. Animation: Components that organises and manages the animation
3. InputInfo: Manages the user inputs which consists of different images and texts read from an XML file
4. CustomPiMapper: Singleton that initialises all CustomSource classes and settings in the program

###2. Custom Source
Surfaces are all texture mapped using either an image or custom source. To add a new custom source to be displayed on a surface, do the following:

1. Create a new CustomSource class and header file in the CustomSource directory by duplicating and renaming existing ones
2. Add and initialise the new CustomSource in CustomPiMapper.h/cpp
3. You may use the new CustomSource in an animation set (see example in AnimInputInfo.cpp)

````c++
#include <NewCustomSource.h>
...
NewCustomSource* newCustomSource;
...
NewCustomSource* getNewCustomSource();
...
```` 
CustomPiMapper.h

````c++
...
newCustomSource = new NewCustomSource(); // Initialise
...
// Destroy the NewCustomSource
delete newCustomSource;
newCustomSource = 0;
...
// Definte getMethod
NewCustomSource* CustomPiMapper::getNewCustomSource(){
	return newCustomSource;
}
````
CustomPiMapper.cpp

### 3. Animation
Animations are designed so that the program calls only one animation set at a time. An animation set is an animation or display that lasts for a specified duration. After an animation set has ended, the next animation set is called and played. After the last animation set, the first animation set will be played again.

Animation sets are managed by the Animation Manager which stores a list of animation sets and cycles through them.

To add a new animation set, do the following:
1. Create a new AnimSet class and header file in the Animation directory by duplicating and renaming AnimInputInfo.cpp/h
2. Ensure that your new class extends AnimSet which is an abstract class
3. Ensure that all virtual methods are overriden
4. Update the new class to perform a different animation
5. Add the new animation set to the Animation Manager and specify how long it should last in milliseconds

````c++
AnimManager::AnimManager(){
    inputInfoManager = new InputInfoManager();

    currentIndex = 0;
    animSetArr.push_back(new AnimInputInfo(inputInfoManager, 5000));
    animSetArr.push_back(new AnimInputInfo(inputInfoManager, 5000));
    animSetArr.push_back(new NewAnimSet(inputInfoManager, 9000)); // Adds new animation set which lasts for 9seconds
}
```

### 4. Notes

#### Clock Skew Error
You may encounter a clock skew error when recompiling modified codes. This means that the timestamps of the files are not synchronized and cannot be compiled. You will see a list of affected files during compile time. This may be resolved by changing to the specified directory and running the following command.
````linux
touch *
````
This command will update the timestamps in the file. Attempt to recompile the codes again and repeat as necessary.

#### Correcting PI Resolution
If the resolution of the output display does not seem correct, you may follow a list of instructions at the following site. The projector at the Maxus Singapore office runs best at DMT 1024x768. 

http://weblogs.asp.net/bleroy/getting-your-raspberry-pi-to-output-the-right-resolution


