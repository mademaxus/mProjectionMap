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

