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

void SoundSource::paint(Graphics& g)
{
    g.setColour(Colours::blueviolet);
    g.fillEllipse(getLocalBounds().toFloat());
    
    g.setColour(Colours::black);
    g.setFont(16);
    g.drawText("S", getLocalBounds(), Justification::centred);
}

void SoundSource::mouseDown(const MouseEvent&)
{
    
}
