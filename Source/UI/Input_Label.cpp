/*
  ==============================================================================

    Input_Label.cpp
    Created: 4 Oct 2019 1:16:31pm
    Author:  Silver

  ==============================================================================
*/

#include "Input_Label.h"

InputLabel::InputLabel()
{
    
}

InputLabel::~InputLabel()
{
    
}

juce::TextEditor* InputLabel::createEditorComponent()
{
    juce::TextEditor* textEditor = new juce::TextEditor();
    textEditor->setInputRestrictions(7, "0123456789.");
    return textEditor;
}
