/*
  ==============================================================================

    Control_Panel.cpp
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#include "Control_Panel.h"

//==============================================================================
ControlPanel::ControlPanel()
{
    setSize (CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);
    
    comboBoxInit();
    runButtonInit();
}

ControlPanel::~ControlPanel()
{
    
}

void ControlPanel::resized()
{
    Rectangle<int> area (2,
                         getBottom() - 45 - 2,
                         CONTROL_PANEL_WIDTH - 2*2,
                         45);
    runButton.setBounds(area);
}

void ControlPanel::comboBoxInit() {
    mComboBox.setBounds(2,
                        2,
                        CONTROL_PANEL_WIDTH - 2*2,
                        COMBOBOX_HEIGHT - 2*2);
    mComboBox.addItem("VBAP", 1);
    mComboBox.addItem("MDAP", 2);
    mComboBox.addItem("DBAP", 3);
    mComboBox.setColour(ComboBox::ColourIds::backgroundColourId, Colours::whitesmoke);
    mComboBox.setColour(ComboBox::ColourIds::arrowColourId, Colours::black);
    mComboBox.setColour(ComboBox::ColourIds::textColourId, Colours::black);
    mComboBox.setColour(ComboBox::ColourIds::buttonColourId, Colours::black);
    mComboBox.setJustificationType(Justification::centred);
    // TODO make the combobox and run button static;
//    mComboBox.setText(mComboBox.getItemText(modelType));
    addAndMakeVisible(mComboBox);
}

void ControlPanel::runButtonInit() {
    runButton.setButtonText("Run");
    runButton.setColour(TextButton::buttonColourId, Colours::whitesmoke.darker());
    runButton.setBounds(2,
                        getBottom() - 45 - 2,
                        CONTROL_PANEL_WIDTH - 2*2,
                        45);
    addAndMakeVisible(runButton);
}

//==============================================================================
/** Methods for subpanel use*/

void ControlPanel::drawLine(juce::Graphics &g, int lineDistance)
{
    Line<float> line (Point<float> (0, lineDistance),
                      Point<float> (CONTROL_PANEL_WIDTH, lineDistance));
    g.drawLine(line, 2);
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

//==============================================================================
/** Interface for external use */
ComboBox& ControlPanel::getComboBox()
{
    return mComboBox;
}

TextButton& ControlPanel::getRunButton()
{
    return runButton;
}

std::vector<std::shared_ptr<Label>>& ControlPanel::getLabels()
{
    return mPosLabels;
}
