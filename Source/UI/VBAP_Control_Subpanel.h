/*
  ==============================================================================

    VBAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:28:59pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "PositionControl_Panel.h"

class VBAPSubpanel
:   public PositionControl_Panel
    
{
public:
    
    VBAPSubpanel();
    ~VBAPSubpanel();
    
private:
    void paint (juce::Graphics& g) override;
};
