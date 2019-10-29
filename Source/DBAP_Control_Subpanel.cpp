/*
  ==============================================================================

    DBAP_Control_Subpanel.cpp
    Created: 30 Sep 2019 3:29:50pm
    Author:  Silver

  ==============================================================================
*/

#include "DBAP_Control_Subpanel.h"

DBAPSubpanel::DBAPSubpanel()
{
    setSize(CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
}

DBAPSubpanel::~DBAPSubpanel()
{
    
}

TextButton& DBAPSubpanel::getRunButton()
{
    return runButton;
}

std::vector<std::shared_ptr<Point<float>>> DBAPSubpanel::getPos()
{
    return mPos;
}

std::vector<float>& DBAPSubpanel::getGainVals()
{
    return mGainVals;
}

std::vector<std::shared_ptr<Label>> DBAPSubpanel::getLabels()
{
    return mPosLabel;
}

void DBAPSubpanel::calPos()
{
    
}

void DBAPSubpanel::paint(Graphics& g)
{
    g.setFont(25);
    g.setColour(Colours::black);
    g.drawText("DBAP Model",
               0,
               0,
               CONTROL_PANEL_WIDTH,
               CONTROL_PANEL_HEIGHT,
               Justification::centred);
}
