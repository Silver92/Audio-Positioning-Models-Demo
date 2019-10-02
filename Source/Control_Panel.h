/*
  ==============================================================================

    Control_Panel.h
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "VBAP_Control_Subpanel.h"
#include "VBAP.h"

class ControlPanel
: public PanelBase
{
public:
    ControlPanel(std::shared_ptr<ModelManager> inModelManager);
    ~ControlPanel();
    
private:
    std::unique_ptr<VBAP_Panel> mVBAP_Panel;
};
