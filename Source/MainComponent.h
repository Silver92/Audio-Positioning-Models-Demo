/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Control_Panel.h"
#include "View_Panel.h"
#include "Model_Manager.h"
#include "VBAP.h"
#include "MDAP.h"
#include "PresetManager.h"

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
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    std::unique_ptr<ControlPanel> mControlPanel;
    std::unique_ptr<ViewPanel> mViewPanel;
    std::unique_ptr<ModelManager> mModelManager;
    std::unique_ptr<PresetManager> mPresetManager;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
