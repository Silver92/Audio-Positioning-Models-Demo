/*
  ==============================================================================

    View_Panel.h
    Created: 30 Sep 2019 3:11:56pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "2D_View_Subpanel.h"

class ViewPanel
: public PanelBase
{
public:
    ViewPanel();
    ~ViewPanel();
    
    std::unique_ptr<TwoDSubpanel> m2DPanel;
private:
    
};
