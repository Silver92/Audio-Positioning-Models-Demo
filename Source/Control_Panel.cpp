/*
  ==============================================================================

    Control_Panel.cpp
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#include "Control_Panel.h"

ControlPanel::ControlPanel(std::shared_ptr<ModelManager> inModelManager)
: PanelBase(inModelManager)
{
    setSize(CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
    
    mModelManager.reset(new VBAP());
    mVBAP_Panel.reset(new VBAP_Panel(inModelManager));
    addAndMakeVisible(mVBAP_Panel.get());
}

ControlPanel::~ControlPanel()
{
    
}
