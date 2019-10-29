/*
  ==============================================================================

    MDAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:29:33pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Input_Label.h"
#include "Control_Panel.h"

class MDAPSubpanel
:   public ControlPanel
{
public:
    MDAPSubpanel();
    ~MDAPSubpanel();
    
    TextButton& getRunButton() override;
    std::vector<std::shared_ptr<Point<float>>> getPos() override;
    std::vector<float>& getGainVals() override;
    std::vector<std::shared_ptr<Label>> getLabels() override;
    void calPos() override;
    
private:
    void paint (Graphics& g) override;
//    void resized() override;
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
