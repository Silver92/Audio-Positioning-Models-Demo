/*
  ==============================================================================

    VBAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:28:59pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "Control_Panel.h"

class VBAPSubpanel
:   public ControlPanel
    
{
public:
    
    VBAPSubpanel();
    ~VBAPSubpanel();
    
private:
    void paint (Graphics& g) override;
};
