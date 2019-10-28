/*
  ==============================================================================

    MDAP_Control_Subpanel.cpp
    Created: 30 Sep 2019 3:29:33pm
    Author:  Silver

  ==============================================================================
*/

#include "MDAP_Control_Subpanel.h"

void MDAPSubpanel::paint(Graphics& g)
{
    g.setFont(25);
    g.setColour(Colours::black);
    g.drawText("MDAP Model", getLocalBounds(), Justification::centredTop);
}
