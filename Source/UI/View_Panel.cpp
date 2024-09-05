/*
  ==============================================================================

    View_Panel.cpp
    Created: 30 Sep 2019 3:11:56pm
    Author:  Silver

  ==============================================================================
*/

#include "View_Panel.h"

ViewPanel::ViewPanel()
{
    setSize(VIEW_PANEL_WIDTH, VIEW_PANEL_HEIGHT);
    
    m2DPanel.reset(new TwoDSubpanel());
    addAndMakeVisible(m2DPanel.get());
}

ViewPanel::~ViewPanel()
{
    
}
