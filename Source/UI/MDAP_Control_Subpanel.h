/*
  ==============================================================================

    MDAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:29:33pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Input_Label.h"
#include "PositionControl_Panel.h"

class MDAPSubpanel
:   public PositionControl_Panel
{
public:
    MDAPSubpanel();
    ~MDAPSubpanel();
    
private:
    void paint (juce::Graphics& g) override;
};
