/*
  ==============================================================================

    PresetManager.h
    Created: 3 Oct 2019 9:15:35pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class PresetManager
{
public:
    PresetManager();
    ~PresetManager();
    void saveCurrentPreset();
    void loadPreviousPreset();
private:
    String mPresetDirectory;
    File myCurrentPreset;
};
