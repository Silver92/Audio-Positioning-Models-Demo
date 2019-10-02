/*
  ==============================================================================

    Panel_Base.h
    Created: 30 Sep 2019 5:15:58pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "UI_Dimensions.h"
#include "Model_Manager.h"

class PanelBase
:   public  Component
{
public:
    PanelBase(std::shared_ptr<ModelManager> inModelManager);
    ~PanelBase();
    
    void paint (Graphics& g) override;
    
protected:
    std::shared_ptr<ModelManager> mModelManager;
};
