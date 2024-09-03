/*
  ==============================================================================

    Speaker_Component.h
    Created: 2 Oct 2019 8:33:15pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../UI/View_Component_Base.h"

class Speaker
:   public ViewComponentBase
{
public:
    Speaker(juce::String indBValue);
    ~Speaker();
    void paint(juce::Graphics& g) override;
    void mouseDown (const juce::MouseEvent&) override;
private:
    juce::String dBValue;
};
