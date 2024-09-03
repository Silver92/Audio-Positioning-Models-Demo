/*
  ==============================================================================

    Speaker_Component.cpp
    Created: 2 Oct 2019 8:33:15pm
    Author:  Silver

  ==============================================================================
*/

#include "Speaker_Component.h"

Speaker::Speaker(juce::String indBValue)
{
    dBValue = indBValue;
}

Speaker::~Speaker()
{
    
}

void Speaker::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::lightgrey);
    g.fillEllipse(getLocalBounds().toFloat());
    
    g.setColour(juce::Colours::black);
    g.setFont(10);
    g.drawText(dBValue + "dB", getLocalBounds(), juce::Justification::centred);
}

void Speaker::mouseDown (const juce::MouseEvent& mouseEvent)
{

}
