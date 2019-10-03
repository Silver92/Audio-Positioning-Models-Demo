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
    
    mControlPanel.reset(new ControlPanel());
    mControlPanel->setBounds(VIEW_PANEL_WIDTH, 0, getWidth(), getHeight());
    addAndMakeVisible(mControlPanel.get());
    
    mViewPanel.reset(new ViewPanel());
    addAndMakeVisible(mViewPanel.get());
    
    mModelManager.reset(new VBAP());
    
    mControlPanel->mVBAPPanel->runButton.onClick = [this]
    {mViewPanel->m2DPanel->drawComponents(mControlPanel->mVBAPPanel->mPos,
                                          mModelManager->calVBAP(mControlPanel->mVBAPPanel->mPos));
        
    };
    
}

MainComponent::~MainComponent()
{
//    File OutFile("TestOutput.txt");
//    FileOutputStream OutStream(OutFile);
//    if (OutStream.openedOk())
//        OutStream.writeFloat(1.0f);
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
