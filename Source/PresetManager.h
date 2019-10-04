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
    void saveCurrentPreset(std::vector<std::shared_ptr<Label>> mPos);
    void loadPreviousPreset(std::vector<std::shared_ptr<Label>> mPos);
private:
    String mPresetDirectory;
    File myCurrentPreset;
};
