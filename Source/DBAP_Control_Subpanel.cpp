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
    
    int yPos = 0;
    setText(listenerPosTitle, 20, 0, yPos, CONTROL_PANEL_WIDTH, "Listener Position");
    yPos += 25;
    setInput(20, yPos);
    
    yPos += 25;
    setText(speakerPosTitle, 20, 0, yPos, CONTROL_PANEL_WIDTH, "Speakers Position");
    yPos += 25;
    setInput(20, yPos);
    yPos += 25;
    setInput(20, yPos);
    yPos += 25;
    setInput(20, yPos);
    yPos += 25;
    setInput(20, yPos);
}

DBAPSubpanel::~DBAPSubpanel()
{
    mXYLabels.clear();
    mPosLabels.clear();
}

void DBAPSubpanel::paint(Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    g.fillAll();
    g.setColour(Colours::black);
    g.drawRect(0,
               0,
               CONTROL_PANEL_WIDTH,
               CONTROL_PANEL_HEIGHT,
               2);

    int lineDistance = 25 * 2;
    drawLine(g, lineDistance);
    lineDistance += 25 * 5;
    drawLine(g, lineDistance);
}
