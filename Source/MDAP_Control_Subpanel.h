/*
  ==============================================================================

    MDAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:29:33pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Input_Label.h"
#include "Control_Panel.h"

class MDAPSubpanel
:   public ControlPanel
{
public:
    MDAPSubpanel();
    ~MDAPSubpanel();
    
private:
    void paint (Graphics& g) override;
};
