/*
  ==============================================================================

    View_Component_Base.cpp
    Created: 2 Oct 2019 10:39:02pm
    Author:  Silver

  ==============================================================================
*/

#include "View_Component_Base.h"

ViewComponentBase::ViewComponentBase()
{
    setSize(50, 50);
}

ViewComponentBase::~ViewComponentBase()
{
    
}

void ViewComponentBase::paint(juce::Graphics& g)
{
    
}

void ViewComponentBase::mouseDown (const juce::MouseEvent&)
{
//    setBounds(mouseEvent.getMouseDownX(),
//              mouseEvent.getMouseDownY(),
//              getWidth(),
//              getHeight());
}
