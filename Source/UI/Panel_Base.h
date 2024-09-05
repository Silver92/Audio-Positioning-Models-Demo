/*
  ==============================================================================

    Panel_Base.h
    Created: 30 Sep 2019 5:15:58pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "juce_gui_basics/juce_gui_basics.h"
#include "UI_Dimensions.h"
#include "../Models/Model_Manager.h"

class PanelBase
:   public  juce::Component
{
public:
    PanelBase();
    ~PanelBase();
    
    void paint (juce::Graphics& g) override;
    
protected:
};
