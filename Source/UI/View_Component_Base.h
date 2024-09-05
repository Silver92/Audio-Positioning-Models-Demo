/*
  ==============================================================================

    View_Component_Base.h
    Created: 2 Oct 2019 10:39:02pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "juce_gui_basics/juce_gui_basics.h"

class ViewComponentBase
:   public juce::Component
{
public:
    ViewComponentBase();
    ~ViewComponentBase();
    void paint(juce::Graphics& g) override;
    void mouseDown (const juce::MouseEvent&) override;
};
