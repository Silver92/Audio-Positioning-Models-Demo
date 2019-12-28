/*
  ==============================================================================

    Control_Panel.h
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "Input_Label.h"

class ControlPanel
:   public PanelBase
{
public:
    
    //==============================================================================
    ControlPanel();
    ~ControlPanel();
    
    //==============================================================================
    ComboBox& getComboBox();
    TextButton& getRunButton();
    std::vector<std::shared_ptr<Label>>& getLabels();

protected:
    //==============================================================================
    void resized() override;
    void comboBoxInit();
    void runButtonInit();
    
    //==============================================================================
    void drawLine(juce::Graphics &g, int lineDistance);
    void setText(Label& label, int fontSize, int xPos, int yPos, int width, String text = "");
    void setInputText(int fontSize, int xPos, int yPos, int width);
    void setInput(int fontSize, int yPos);
    
    //==============================================================================
    ComboBox mComboBox;
    Label listenerPosTitle;
    Label speakerPosTitle;
    Label sourcePosTitle;
    TextButton runButton;
    
    std::vector<std::shared_ptr<Label>> mXYLabels;
    std::vector<std::shared_ptr<Label>> mPosLabels;
    
    //==============================================================================
    std::vector<std::shared_ptr<Point<float>>> mPos;
    std::vector<float> mGainVals;
};
