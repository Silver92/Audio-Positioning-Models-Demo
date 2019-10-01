/*
  ==============================================================================

    Control_Panel.cpp
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#include "Control_Panel.h"

ControlPanel::ControlPanel()
{
    setSize(CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
    
    mVBAP_Panel.reset(new VBAP_Panel());
    addAndMakeVisible(mVBAP_Panel.get());
}

ControlPanel::~ControlPanel()
{
    
}
