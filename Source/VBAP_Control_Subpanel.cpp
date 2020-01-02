/*
  ==============================================================================

    VBAP_Control_Subpanel.cpp
    Created: 30 Sep 2019 3:28:59pm
    Author:  Silver

  ==============================================================================
*/

#include "VBAP_Control_Subpanel.h"

VBAPSubpanel::VBAPSubpanel()
{
    setBounds(VIEW_PANEL_WIDTH,
              COMBOBOX_HEIGHT,
              CONTROL_PANEL_WIDTH,
              CONTROL_PANEL_HEIGHT - COMBOBOX_HEIGHT - RUNBUTTON_HEIGHT);
    
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
    
    yPos += 25;
    setText(sourcePosTitle, 20, 0, yPos, CONTROL_PANEL_WIDTH, "Sound Source Position");
    yPos += 20;
    setInput(20, yPos);
}

VBAPSubpanel::~VBAPSubpanel()
{
    mXYLabels.clear();
    mPosLabels.clear();
}

void VBAPSubpanel::paint(Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    g.fillAll();
    g.setColour(Colours::black);
    g.drawRect(0,
               0,
               CONTROL_PANEL_WIDTH,
               CONTROL_PANEL_HEIGHT,
               2);
    int lineDistance = 0;
    drawLine(g, lineDistance);
    lineDistance += 25 * 2;
    drawLine(g, lineDistance);
    lineDistance += 25 * 5;
    drawLine(g, lineDistance);
    lineDistance += 25 * 2;
    drawLine(g, lineDistance);
}
