/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "juce_gui_basics/juce_gui_basics.h"

#include "UI/Control_Panel.h"
#include "UI/VBAP_Control_Subpanel.h"
#include "UI/MDAP_Control_Subpanel.h"
#include "UI/DBAP_Control_Subpanel.h"

#include "UI/View_Panel.h"

#include "Models/Model_Manager.h"
#include "Models/VBAP.h"
#include "Models/MDAP.h"
#include "Models/DBAP.h"

#include "PresetManager.h"
#include "Parameters.h"

using namespace juce;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainComponent   : public Component
{
public:
//==============================================================================
    MainComponent();
    ~MainComponent();

//==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
//==============================================================================
    void comboBoxChanged(juce::ComboBox& comboBoxThatHasChanged);
    void calModelAndDraw(PanelModelType modelType);

private:
    //==============================================================================
    void prepareInputData();
    
    std::unique_ptr<ControlPanel> mControlPanel;
    std::unique_ptr<ViewPanel> mViewPanel;
    std::unique_ptr<ModelManager> mModelManager;
    std::unique_ptr<PresetManager> mPresetManager;

    PanelModelType mModelType;
    
    std::vector<std::shared_ptr<Point<float>>> mPos;
    std::vector<float> mGainVals;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
