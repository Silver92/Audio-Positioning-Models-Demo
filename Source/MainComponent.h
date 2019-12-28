/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Control_Panel.h"
#include "VBAP_Control_Subpanel.h"
#include "MDAP_Control_Subpanel.h"
#include "DBAP_Control_Subpanel.h"

#include "View_Panel.h"

#include "Model_Manager.h"
#include "VBAP.h"
#include "MDAP.h"
#include "DBAP.h"

#include "PresetManager.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

enum PanelModelType
{
    PanelModel_VBAP,
    PanelModel_MDAP,
    PanelModel_DBAP,
    PanelModel_TotalNumModels
};

class MainComponent   : public Component
{
public:
//==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    //==============================================================================
    void comboBoxChanged(ComboBox& comboBoxThatHasChanged);

private:
    //==============================================================================
    void modelInteractions();
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
