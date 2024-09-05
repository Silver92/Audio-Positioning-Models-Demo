/*
  ==============================================================================

    Panel_Base.cpp
    Created: 30 Sep 2019 5:15:58pm
    Author:  Silver

  ==============================================================================
*/

#include "Panel_Base.h"

PanelBase::PanelBase()
{
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 2);
}
