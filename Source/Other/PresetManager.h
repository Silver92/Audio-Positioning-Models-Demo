/*
  ==============================================================================

    PresetManager.h
    Created: 3 Oct 2019 9:15:35pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Parameters.h"

class PresetManager
{
public:
    PresetManager();
    ~PresetManager();
    void saveCurrentPreset(std::vector<std::shared_ptr<juce::Label>>& mPos,
                           PanelModelType inType);
    void loadPreviousPreset(std::vector<std::shared_ptr<juce::Label>>& mPos,
                            PanelModelType inType);
    PanelModelType loadPreviousModelType();
private:
    
    juce::String mPresetDirectory;
    juce::File myCurrentPreset;
    
    /** The saving and  loading buffer */
    std::unique_ptr<juce::XmlElement> posList;
};
