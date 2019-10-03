/*
  ==============================================================================

    View_Component_Base.h
    Created: 2 Oct 2019 10:39:02pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class ViewComponentBase
:   public Component
{
public:
    ViewComponentBase();
    ~ViewComponentBase();
    void paint(Graphics& g) override;
    void mouseDown (const MouseEvent&) override;
};
