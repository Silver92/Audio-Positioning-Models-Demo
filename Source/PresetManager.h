/*
  ==============================================================================

    PresetManager.h
    Created: 3 Oct 2019 9:15:35pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "Parameters.h"

class PresetManager
{
public:
    PresetManager();
    ~PresetManager();
    void saveCurrentPreset(std::vector<std::shared_ptr<Label>>& mPos,
                           PanelModelType inType);
    void loadPreviousPreset(std::vector<std::shared_ptr<Label>>& mPos,
                            PanelModelType inType);
    PanelModelType loadPreviousModelType();
private:
    String mPresetDirectory;
    File myCurrentPreset;
    std::unique_ptr<XmlElement> mainElement;
    
    XmlElement posList;
};
