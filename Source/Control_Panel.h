/*
  ==============================================================================

    Control_Panel.h
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"

class ControlPanel
:   public PanelBase
{
public:
    ControlPanel();
    ~ControlPanel();
    
    virtual TextButton& getRunButton() = 0;
    virtual std::vector<std::shared_ptr<Point<float>>> getPos() = 0;
    virtual std::vector<float>& getGainVals() = 0;
    virtual std::vector<std::shared_ptr<Label>> getLabels() = 0;
    virtual void calPos() = 0;
    
private:
    
};
