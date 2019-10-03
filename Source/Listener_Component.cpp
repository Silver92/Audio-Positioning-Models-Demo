/*
  ==============================================================================

    Listener_Component.cpp
    Created: 2 Oct 2019 8:32:59pm
    Author:  Silver

  ==============================================================================
*/

#include "Listener_Component.h"

Listener::Listener()
{
    
}

Listener::~Listener()
{
    
}

void Listener::paint(Graphics& g)
{
    g.setColour(Colours::mediumpurple);
    g.fillEllipse(getLocalBounds().toFloat());
    
    g.setColour(Colours::black);
    g.setFont(16);
    g.drawText("L", getLocalBounds(), Justification::centred);
}

void Listener::mouseDown(const MouseEvent&)
{
    
}
