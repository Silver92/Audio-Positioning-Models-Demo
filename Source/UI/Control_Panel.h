/*
  ==============================================================================

    Control_Panel.h
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "PositionControl_Panel.h"

class ControlPanel
:   public PanelBase
{
public:
    
    //==============================================================================
    ControlPanel();
    ~ControlPanel();
    
    //==============================================================================
    juce::ComboBox& getComboBox();
    juce::TextButton& getRunButton();
    std::vector<std::shared_ptr<juce::Label>>& getLabels();
    std::unique_ptr<PositionControl_Panel>& getPositionPanel();

private:
    //==============================================================================
    void resized() override;
    void comboBoxInit();
    void runButtonInit();
    
    //==============================================================================
    std::unique_ptr<PositionControl_Panel> mPositionPanel;
    juce::ComboBox mComboBox;
    juce::TextButton runButton;
};
