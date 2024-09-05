/*
  ==============================================================================

    DBAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:29:50pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Input_Label.h"
#include "PositionControl_Panel.h"

class DBAPSubpanel
:   public PositionControl_Panel
{
public:
    DBAPSubpanel();
    ~DBAPSubpanel();
    
private:
    void paint (juce::Graphics& g) override;
};
