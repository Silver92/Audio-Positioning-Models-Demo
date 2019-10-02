/*
  ==============================================================================

    View_Panel.cpp
    Created: 30 Sep 2019 3:11:56pm
    Author:  Silver

  ==============================================================================
*/

#include "View_Panel.h"

ViewPanel::ViewPanel(std::shared_ptr<ModelManager> inModelManager)
:   PanelBase(inModelManager)
{
    setSize(VIEW_PANEL_WIDTH, VIEW_PANEL_HEIGHT);
}

ViewPanel::~ViewPanel()
{
    
}
