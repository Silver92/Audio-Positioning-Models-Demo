/*
  ==============================================================================

    Input_Label.h
    Created: 4 Oct 2019 1:16:31pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "juce_gui_basics/juce_gui_basics.h"

class InputLabel
:   public juce::Label
{
public:
    InputLabel();
    ~InputLabel();
    juce::TextEditor* createEditorComponent() override;
};
