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
    setBounds(VIEW_PANEL_WIDTH,
              0,
              CONTROL_PANEL_WIDTH,
              CONTROL_PANEL_HEIGHT);
    
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
    return mPositionPanel->getPosLabels();
}

std::unique_ptr<PositionControl_Panel>& ControlPanel::getPositionPanel()
{
    return mPositionPanel;
}
