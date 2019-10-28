/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mControlPanel.reset(new VBAPSubpanel());
    mControlPanel->setBounds(VIEW_PANEL_WIDTH, 0, getWidth(), getHeight());
    addAndMakeVisible(mControlPanel.get());
    
    mViewPanel.reset(new ViewPanel());
    addAndMakeVisible(mViewPanel.get());
    
    mModelManager.reset(new VBAP());
    
    mControlPanel->getRunButton().onClick = [this]
    {
        mModelManager->calculate(mControlPanel->getPos(),
                                 mControlPanel->getGainVals());
        mViewPanel->m2DPanel->drawComponents(mControlPanel->getPos(),
                                             mControlPanel->getGainVals());
        
    };
    
    mPresetManager.reset(new PresetManager());
    mPresetManager->loadPreviousPreset(mControlPanel->getLabels());
    
    mControlPanel->calPos();
    
    mModelManager->calculate(mControlPanel->getPos(),
                             mControlPanel->getGainVals());
    mViewPanel->m2DPanel->drawComponents(mControlPanel->getPos(),
                                         mControlPanel->getGainVals());
}

MainComponent::~MainComponent()
{
    mPresetManager->saveCurrentPreset(mControlPanel->getLabels());
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
