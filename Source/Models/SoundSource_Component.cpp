/*
  ==============================================================================

    SoundSource_Component.cpp
    Created: 2 Oct 2019 8:33:40pm
    Author:  Silver

  ==============================================================================
*/

#include "SoundSource_Component.h"

SoundSource::SoundSource()
{
    
}

SoundSource::~SoundSource()
{
    
}

void SoundSource::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::blueviolet);
    g.fillEllipse(getLocalBounds().toFloat());
    
    g.setColour(juce::Colours::black);
    g.setFont(16);
    g.drawText("S", getLocalBounds(), juce::Justification::centred);
}

void SoundSource::mouseDown(const juce::MouseEvent&)
{
    
}
