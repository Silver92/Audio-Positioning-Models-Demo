/*
  ==============================================================================

    Listener_Component.h
    Created: 2 Oct 2019 8:32:59pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../UI/View_Component_Base.h"

class Listener
:   public ViewComponentBase
{
public:
    Listener();
    ~Listener();
    void paint(juce::Graphics& g) override;
    void mouseDown (const juce::MouseEvent&) override;
private:
};
