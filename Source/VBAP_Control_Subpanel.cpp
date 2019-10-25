/*
  ==============================================================================

    VBAP_Control_Subpanel.cpp
    Created: 30 Sep 2019 3:28:59pm
    Author:  Silver

  ==============================================================================
*/

#include "VBAP_Control_Subpanel.h"

VBAPSubpanel::VBAPSubpanel()
{
    setSize(CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
    
    int yPos = 35;
    setText(listenerPosTitle, 20, 0, yPos, getWidth(), "Listener Position");
    yPos += 20;
    setInput(20, yPos);
    
    yPos += 25;
    setText(speakerPosTitle, 20, 0, yPos, getWidth(), "Speakers Position");
    yPos += 25;
    setInput(20, yPos);
    yPos += 25;
    setInput(20, yPos);
    yPos += 25;
    setInput(20, yPos);
    yPos += 25;
    setInput(20, yPos);
    
    yPos += 25;
    setText(sourcePosTitle, 20, 0, yPos, getWidth(), "Sound Source Position");
    yPos += 20;
    setInput(20, yPos);
    
    runButton.setButtonText("Run");
    runButton.setColour(TextButton::buttonColourId, Colours::whitesmoke.darker());
    runButton.onClick = [this] {;};
    addAndMakeVisible(runButton);
}

VBAPSubpanel::~VBAPSubpanel()
{
    
}

void VBAPSubpanel::paint(Graphics& g)
{
    g.setFont(25);
    g.setColour(Colours::black);
    g.drawText("VBAP Model", getLocalBounds(), Justification::centredTop);
    
    g.setColour(Colours::black);
    int lineDistance = 35;
    drawLine(g, lineDistance);
    lineDistance += 20 + 25;
    drawLine(g, lineDistance);
    lineDistance += 25 * 5;
    drawLine(g, lineDistance);
}

void VBAPSubpanel::drawLine(juce::Graphics &g, int lineDistance)
{
    Line<float> line (Point<float> (0, lineDistance),
                      Point<float> (CONTROL_PANEL_WIDTH, lineDistance));
    g.drawLine(line, 2);
}

void VBAPSubpanel::resized()
{
    Rectangle<int> area (2, getBottom() - 45 - 2, getWidth() - 2, 45);
    runButton.setBounds(area);
}

void VBAPSubpanel::setText(Label& label,
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

void VBAPSubpanel::setInputText(int fontSize,
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
    mPosLabel.push_back(input);
}

void VBAPSubpanel::setInput(int fontSize, int yPos)
{
    std::shared_ptr<Label> textX (new Label());
    setText(*textX, fontSize, 3, yPos, getWidth()/4, "X:");
    mXYLabel.push_back(textX);
    
    std::shared_ptr<Label> textY (new Label());
    setText(*textY, fontSize, getWidth()/2 - 10, yPos, getWidth()/4, "Y:");
    mXYLabel.push_back(textY);
    
    setInputText(fontSize, getWidth()/4, yPos, getWidth()/4);
    setInputText(fontSize, getWidth()/4*3 - 20, yPos, getWidth()/4);
}



TextButton& VBAPSubpanel::getRunButton()
{
    return runButton;
}

std::vector<std::shared_ptr<Point<float>>> VBAPSubpanel::getPos()
{
    return mPos;
}

std::vector<float>& VBAPSubpanel::getGainVals()
{
    return mGainVals;
}

std::vector<std::shared_ptr<Label>> VBAPSubpanel::getLabels()
{
    return mPosLabel;
}

void VBAPSubpanel::calPos()
{
    for (int i = 0; i < mPosLabel.size() - 1; i += 2)
    {
        std::shared_ptr<Point<float>> point(new Point<float>
                                            (mPosLabel[i]->getText()
                                             .getFloatValue(),
                                             mPosLabel[i+1]->getText()
                                             .getFloatValue()));
        mPosLabel[i]->onTextChange = [this, i, point]{point->
                                    setX(mPosLabel[i]->getText()
                                    .getFloatValue());};
        mPosLabel[i+1]->onTextChange = [this, i, point]{point->
                                    setY(mPosLabel[i+1]->getText()
                                    .getFloatValue());};
        mPos.push_back(point);
    }
}
