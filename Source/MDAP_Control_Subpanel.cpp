/*
  ==============================================================================

    MDAP_Control_Subpanel.cpp
    Created: 30 Sep 2019 3:29:33pm
    Author:  Silver

  ==============================================================================
*/

#include "MDAP_Control_Subpanel.h"

MDAPSubpanel::MDAPSubpanel()
{
    setSize(CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
}

MDAPSubpanel::~MDAPSubpanel()
{
    
}

TextButton& MDAPSubpanel::getRunButton()
{
    return runButton;
}

std::vector<std::shared_ptr<Point<float>>> MDAPSubpanel::getPos()
{
    return mPos;
}

std::vector<float>& MDAPSubpanel::getGainVals()
{
    return mGainVals;
}

std::vector<std::shared_ptr<Label>> MDAPSubpanel::getLabels()
{
    return mPosLabel;
}

void MDAPSubpanel::calPos()
{
    
}

void MDAPSubpanel::paint(Graphics& g)
{
    g.setFont(25);
    g.setColour(Colours::black);
    g.drawText("MDAP Model",
               0,
               0,
               CONTROL_PANEL_WIDTH,
               CONTROL_PANEL_HEIGHT,
               Justification::centred);
}
