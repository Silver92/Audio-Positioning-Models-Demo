# Spacial-Audio App For the Virtual Source Locationing

## Introduction

This GUI application, built with the JUCE framework, calculates the dBFS levels of four surround speakers to simulate a virtual sound source in a room. This simple model simulates a virtual sound source in a fixed position over time, which is applicable in traditional movie theaters or virtual game scenes that require a surround sound system.

Users can adjust the positions of the listener, speakers, and virtual sound source to calculate the output levels of the four speakers.

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
cd /current/project/path
cmake -B Builds/
cmake --build Builds/
```