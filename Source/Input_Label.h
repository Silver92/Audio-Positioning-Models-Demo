/*
  ==============================================================================

    Input_Label.h
    Created: 4 Oct 2019 1:16:31pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class InputLabel
:   public Label
{
public:
    InputLabel();
    ~InputLabel();
    TextEditor* createEditorComponent() override;
};
