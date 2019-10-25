/*
  ==============================================================================

    VBAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:28:59pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "Input_Label.h"

class VBAPSubpanel
:   public PanelBase
{
public:
    
    VBAPSubpanel();
    ~VBAPSubpanel();
    
    TextButton& getRunButton();
    std::vector<std::shared_ptr<Point<float>>> getPos();
    std::vector<float>& getGainVals();
    std::vector<std::shared_ptr<Label>> getLabels();
    void calPos();
    
private:

    void paint (Graphics& g) override;
    void resized() override;
    void setText(Label& label, int fontSize, int xPos, int yPos, int width, String text = "");
    void setInputText(int fontSize, int xPos, int yPos, int width);
    void setInput(int fontSize, int yPos);
    void drawLine(juce::Graphics &g, int lineDistance);
    
    Label listenerPosTitle;
    Label speakerPosTitle;
    Label sourcePosTitle;
    
    TextButton runButton;
    
    std::vector<std::shared_ptr<Label>> mXYLabel;
    std::vector<std::shared_ptr<Label>> mPosLabel;
    std::vector<std::shared_ptr<Point<float>>> mPos;
    std::vector<float> mGainVals;
};
