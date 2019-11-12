# Spacial-Audio App

Introduction

An GUI application built with JUCE framework which calculates the dBFS of 4 surrounded speakers to simulate the virtual sound source in the room.

The user can adjust the positions of the listener, speakers and supposed virtual sound source to calculate the volume outputs of the 4 speakers.

![](Sample Pictures/Screen Shot 2019-10-04 at 14.27.13.png)

## Compile the Project

A simple way to compile the project:

1. Download the latest version of the Juce Framework.

   https://shop.juce.com/get-juce/download

2. download the project or simply using the git clone command in the console:``

   `git clone https://github.com/Silver92/Spacial-Audio.git`

3. Open the projucer in the Juce Framework folder then select the open button in the File panel, or select the "Open Existing Project" in the New Project guiding panel.

   <img src="https://github.com/Silver92/Spacial-Audio/blob/Develop/Sample%20Pictures/Screen%20Shot%202019-11-11%20at%2019.08.05.png" alt="Screen Shot 2019-11-11 at 19.08.05" style="zoom:30%" align="center"/>

4. Find the directory of the project and select the ".jucer" file

5. Selected the exporter for the project based on the OS and click "save and open in IDE" button on the right side

   <img src="https://github.com/Silver92/Spacial-Audio/blob/Develop/Sample%20Pictures/Screen%20Shot%202019-11-11%20at%2019.08.24.png" alt="Screen Shot 2019-11-11 at 19.08.24" style="zoom:40%" align="center"/>

## Other Questions

The project is developed and tested under the Mac + Xcode environment. Users who compile in Windows OS may have following problems:

<img src="https://github.com/Silver92/Spacial-Audio/blob/Develop/Sample%20Pictures/Screen%20Shot%202019-11-11%20at%2019.20.16.png" alt="Screen Shot 2019-11-11 at 19.20.16" style="zoom:30%" align="center"/>

1. There may be some lost path of the JUCE models

   Select the "..." button on the right side of the "path to JUCE" or "JUCE Modules" panel to locate the folder of the downloaded framework

2. Under Windows OS the users need to download VST3 SDK and add the path to the juce client app in order to export the correct format of audio plugin.

   VST3 SDK link:

   https://www.steinberg.net/en/company/developers.html

   

For mor information about the juce setup, please see the tutorials below:

https://docs.juce.com/master/tutorial_new_projucer_project.html

https://docs.juce.com/master/tutorial_manage_projucer_project.html

