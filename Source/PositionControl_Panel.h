/*
  ==============================================================================

    PositionControl_Panel.h
    Created: 1 Jan 2020 8:50:43pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "Panel_Base.h"
#include "Input_Label.h"

class PositionControl_Panel
:   public PanelBase
{
public:
    //==============================================================================
    PositionControl_Panel();
    virtual ~PositionControl_Panel();
    
    //==============================================================================
    void drawLine(juce::Graphics &g, int lineDistance);
    void setText(Label& label, int fontSize, int xPos, int yPos, int width, String text = "");
    void setInputText(int fontSize, int xPos, int yPos, int width);
    void setInput(int fontSize, int yPos);
    
    //==============================================================================
    std::vector<std::shared_ptr<Label>>& getPosLabels();
    
protected:
    Label listenerPosTitle;
    Label speakerPosTitle;
    Label sourcePosTitle;
    
    std::vector<std::shared_ptr<Label>> mXYLabels;
    std::vector<std::shared_ptr<Label>> mPosLabels;
};
