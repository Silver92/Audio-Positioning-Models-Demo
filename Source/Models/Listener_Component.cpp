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

void Listener::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::mediumpurple);
    g.fillEllipse(getLocalBounds().toFloat());
    
    g.setColour(juce::Colours::black);
    g.setFont(16);
    g.drawText("L", getLocalBounds(), juce::Justification::centred);
}

void Listener::mouseDown(const juce::MouseEvent&)
{
    
}
