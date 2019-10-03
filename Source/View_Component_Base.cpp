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
    setSize(30, 30);
}

ViewComponentBase::~ViewComponentBase()
{
    
}

void ViewComponentBase::paint(Graphics& g)
{
    
}

void ViewComponentBase::mouseDown (const MouseEvent&)
{
//    setBounds(mouseEvent.getMouseDownX(),
//              mouseEvent.getMouseDownY(),
//              getWidth(),
//              getHeight());
}
