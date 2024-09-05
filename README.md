# Spacial-Audio App

## Introduction

An GUI application built with JUCE framework which calculates the dBFS of 4 surrounded speakers to simulate the virtual sound source in the room.

The user can adjust the positions of the listener, speakers and supposed virtual sound source to calculate the volume outputs of the 4 speakers.

<center><img src="https://github.com/Silver92/Spacial-Audio/blob/Develop/Sample%20Pictures/Screen%20Shot%202019-10-04%20at%2014.27.13.png" alt="Screen Shot 2019-11-11 at 19.08.05" align="center"/></center>

Building Projects
==================

The project is built with CMake. Make sure to have the latest version of CMake installed before building the project.

Visual Studio
-------------

The project's default generator is Visual Studio 17 2022. JUCE framework is included as a submodule. To build the project, the JUCE framework must be updated ahead with the following command:

```
git submodule update --remote --merge JUCE
```

After the submodule update finished, the following commands could be executed to build the project.

```
cd current/project/path
cmake -B Builds/
cmake --build Builds/
```