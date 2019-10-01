/*
  ==============================================================================

    Panel_Base.h
    Created: 30 Sep 2019 5:15:58pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "UI_Dimensions.h"

class PanelBase
:   public  Component
{
public:
    PanelBase();
    ~PanelBase();
    
    void paint (Graphics& g) override;
    
protected:
    
};
