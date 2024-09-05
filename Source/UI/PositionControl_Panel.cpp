/*
  ==============================================================================

    PositionControl_Panel.cpp
    Created: 1 Jan 2020 8:50:43pm
    Author:  Silver

  ==============================================================================
*/

#include "PositionControl_Panel.h"

//==============================================================================

PositionControl_Panel::PositionControl_Panel()
{
    setBounds(VIEW_PANEL_WIDTH,
              COMBOBOX_HEIGHT,
              CONTROL_PANEL_WIDTH,
              CONTROL_PANEL_HEIGHT - COMBOBOX_HEIGHT - RUNBUTTON_HEIGHT);
}

PositionControl_Panel::~PositionControl_Panel()
{
    
}

//==============================================================================
/** Methods for subpanel use*/

void PositionControl_Panel::drawLine(juce::Graphics &g, int lineDistance)
{
    juce::Line<float> line (juce::Point<float> (0, lineDistance),
        juce::Point<float> (CONTROL_PANEL_WIDTH, lineDistance));
    g.drawLine(line, 2);
}

void PositionControl_Panel::setText(juce::Label& label,
                           int fontSize,
                           int xPos,
                           int yPos,
                           int width,
                            juce::String text)
{
    label.setFont(fontSize);
    label.setColour(juce::Label::textColourId, juce::Colours::black);
    label.setText(text, juce::dontSendNotification);
    label.setBounds(xPos + 1, yPos, width, fontSize);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}

void PositionControl_Panel::setInputText(int fontSize,
                                int xPos,
                                int yPos,
                                int width)
{
    std::shared_ptr<InputLabel> input (new InputLabel());
    setText(*input, fontSize, xPos, yPos, width);
    input->setEditable(true);
    input->setColour(juce::Label::backgroundColourId,
        juce::Colours::whitesmoke.withBrightness(0.9));
    input->setColour(juce::Label::textWhenEditingColourId,
        juce::Colours::black.brighter());
    input->onTextChange = [this]{};
    mPosLabels.push_back(input);
}

void PositionControl_Panel::setInput(int fontSize, int yPos)
{
    std::shared_ptr<juce::Label> textX (new juce::Label());
    setText(*textX, fontSize, 3, yPos, getWidth()/4, "X:");
    mXYLabels.push_back(textX);
    
    std::shared_ptr<juce::Label> textY (new juce::Label());
    setText(*textY, fontSize, getWidth()/2 - 10, yPos, getWidth()/4, "Y:");
    mXYLabels.push_back(textY);
    
    setInputText(fontSize, getWidth()/4, yPos, getWidth()/4);
    setInputText(fontSize, getWidth()/4*3 - 20, yPos, getWidth()/4);
}

std::vector<std::shared_ptr<juce::Label>>& PositionControl_Panel::getPosLabels()
{
    return mPosLabels;
}
