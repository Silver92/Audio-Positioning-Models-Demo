/*
  ==============================================================================

    VBAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:28:59pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"

class VBAP_Panel
:   public PanelBase
{
public:
    
    VBAP_Panel(std::shared_ptr<ModelManager> inModelManager);
    ~VBAP_Panel();
    
private:
    
    void paint (Graphics& g) override;
    void resized() override;
    void setText(Label& label, int fontSize, int xPos, int yPos, int width, String text = "");
    void setInput(int fontSize, int xPos, int yPos, int width);
    void setPosInput(int fontSize, int yPos);
    void drawLine(juce::Graphics &g, int lineDistance);
    
    Label listenerPosTitle;
    Label speakerPosTitle;
    Label sourcePosTitle;
    TextButton runButton;
    
    std::vector<std::shared_ptr<Label>> mPos;
    std::vector<std::shared_ptr<Label>> mXYLabel;
};
