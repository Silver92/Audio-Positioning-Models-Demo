/*
  ==============================================================================

    Control_Panel.cpp
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#include "Control_Panel.h"

ControlPanel::ControlPanel()
{
    setSize (CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
    
    // draw a run button
    runButton.setButtonText("Run");
    runButton.setColour(TextButton::buttonColourId, Colours::whitesmoke.darker());
    runButton.setBounds(2,
                         getBottom() - 45 - 2,
                         CONTROL_PANEL_WIDTH - 2*2,
                         45);
    addAndMakeVisible(runButton);
}

ControlPanel::~ControlPanel()
{
    
}

void ControlPanel::drawLine(juce::Graphics &g, int lineDistance)
{
    Line<float> line (Point<float> (0, lineDistance),
                      Point<float> (CONTROL_PANEL_WIDTH, lineDistance));
    g.drawLine(line, 2);
}

void ControlPanel::resized()
{
    Rectangle<int> area (2,
                         getBottom() - 45 - 2,
                         CONTROL_PANEL_WIDTH - 2*2,
                         45);
    runButton.setBounds(area);
}

void ControlPanel::setText(Label& label,
                           int fontSize,
                           int xPos,
                           int yPos,
                           int width,
                           String text)
{
    label.setFont(fontSize);
    label.setColour(Label::textColourId, Colours::black);
    label.setText(text, dontSendNotification);
    label.setBounds(xPos + 1, yPos, width, fontSize);
    label.setJustificationType(Justification::centred);
    addAndMakeVisible(label);
}

void ControlPanel::setInputText(int fontSize,
                                int xPos,
                                int yPos,
                                int width)
{
    std::shared_ptr<InputLabel> input (new InputLabel());
    setText(*input, fontSize, xPos, yPos, width);
    input->setEditable(true);
    input->setColour(Label::backgroundColourId,
                     Colours::whitesmoke.withBrightness(0.9));
    input->setColour(Label::textWhenEditingColourId,
                     Colours::black.brighter());
    input->onTextChange = [this]{};
    mPosLabels.push_back(input);
}

void ControlPanel::setInput(int fontSize, int yPos)
{
    std::shared_ptr<Label> textX (new Label());
    setText(*textX, fontSize, 3, yPos, getWidth()/4, "X:");
    mXYLabels.push_back(textX);
    
    std::shared_ptr<Label> textY (new Label());
    setText(*textY, fontSize, getWidth()/2 - 10, yPos, getWidth()/4, "Y:");
    mXYLabels.push_back(textY);
    
    setInputText(fontSize, getWidth()/4, yPos, getWidth()/4);
    setInputText(fontSize, getWidth()/4*3 - 20, yPos, getWidth()/4);
}

// Interface for external use

TextButton& ControlPanel::getRunButton()
{
    return runButton;
}

std::vector<std::shared_ptr<Label>> ControlPanel::getLabels()
{
    return mPosLabels;
}

std::vector<std::shared_ptr<Point<float>>> ControlPanel::getPos()
{
    return mPos;
}

std::vector<float>& ControlPanel::getGainVals()
{
    return mGainVals;
}

// Save the user input into the position vectors
void ControlPanel::calPos()
{
    for (int i = 0; i < mPosLabels.size() - 1; i += 2)
    {
        std::shared_ptr<Point<float>> point(new Point<float>
                                            (mPosLabels[i]->getText()
                                             .getFloatValue(),
                                             mPosLabels[i+1]->getText()
                                             .getFloatValue()));
        mPosLabels[i]->onTextChange = [this, i, point]{point->
                                    setX(mPosLabels[i]->getText()
                                    .getFloatValue());};
        mPosLabels[i+1]->onTextChange = [this, i, point]{point->
                                    setY(mPosLabels[i+1]->getText()
                                    .getFloatValue());};
        mPos.push_back(point);
    }
}
