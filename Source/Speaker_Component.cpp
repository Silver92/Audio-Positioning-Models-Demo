/*
  ==============================================================================

    Speaker_Component.cpp
    Created: 2 Oct 2019 8:33:15pm
    Author:  Silver

  ==============================================================================
*/

#include "Speaker_Component.h"

Speaker::Speaker()
{
    
}

Speaker::~Speaker()
{
    
}

void Speaker::paint(Graphics& g)
{
    g.setColour(Colours::lightgrey);
    g.fillEllipse(getLocalBounds().toFloat());
    
    g.setColour(Colours::black);
    g.drawText("0.5", getLocalBounds(), Justification::centred);
}

void Speaker::mouseDown (const MouseEvent& mouseEvent)
{

}
