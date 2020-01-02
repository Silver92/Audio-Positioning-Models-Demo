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
    
    /** Initiate the view panel */
    mViewPanel.reset(new ViewPanel());
    addAndMakeVisible(mViewPanel.get());
    
    /** Initiate the control panel*/
    mControlPanel.reset(new ControlPanel());
    mControlPanel->getComboBox().onChange = [this]
    {
        comboBoxChanged(mControlPanel->getComboBox());
    };
    addAndMakeVisible(mControlPanel.get());
    
    
    mControlPanel->getComboBox().setSelectedId(PanelModel_VBAP + 1);
    
    /** Load the preset Manager and preset*/
//    mPresetManager.reset(new PresetManager());
//    mPresetManager->loadPreviousPreset(mControlPanel->getLabels());
//    prepareInputData();
//    mModelManager->calculate(mPos, mGainVals);
//    mViewPanel->m2DPanel->
//    drawComponents(mPos, mGainVals);
}

MainComponent::~MainComponent()
{
//    mPresetManager->saveCurrentPreset(mControlPanel->getLabels());
    mPos.clear();
    mGainVals.clear();
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

//==============================================================================
void MainComponent::comboBoxChanged(ComboBox& comboBoxThatHasChanged)
{
    PanelModelType modelType = static_cast<PanelModelType>
        (comboBoxThatHasChanged.getSelectedItemIndex());
    
    switch (modelType) {
            
        case (PanelModel_VBAP):{
            mControlPanel->getPositionPanel().
            reset(new VBAPSubpanel());
            mModelManager.reset(new VBAP());
            mControlPanel->getRunButton().onClick = [this]
            {
                mModelManager->calculate(mPos, mGainVals);
                mViewPanel->m2DPanel->
                drawComponents(mPos, mGainVals);
            };
        }break;
            
        case (PanelModel_MDAP):{
            mControlPanel->getPositionPanel().
            reset(new MDAPSubpanel());
            mModelManager.reset(new MDAP());
            mControlPanel->getRunButton().onClick = [this]
            {
                mModelManager->calculate(mPos, mGainVals);
                mViewPanel->m2DPanel->
                drawComponents(mPos, mGainVals);
            };
        }break;
            
        case (PanelModel_DBAP):{
            mControlPanel->getPositionPanel().
            reset(new DBAPSubpanel());
            mModelManager.reset(new DBAP());
            mControlPanel->getRunButton().onClick = [this]
            {
                mModelManager->calculate(mPos, mGainVals);
                mViewPanel->m2DPanel->
                drawComponents(mPos, mGainVals, false);
            };
        }break;
            
        default:
        case (PanelModel_TotalNumModels):{
            jassertfalse;
        }break;
            
    }
    
    addAndMakeVisible(mControlPanel->getPositionPanel().get());
    prepareInputData();
    mModelType = modelType;
}

void MainComponent::prepareInputData()
{
    /**
     Save the user input into the position vectors
     */
    
    mPos.clear();
    auto labels = mControlPanel->getLabels();
    for (int i = 0; i < labels.size() - 1; i += 2)
    {
        std::shared_ptr<Point<float>> point(
                                            new Point<float>
                                            (labels[i]->getText()
                                             .getFloatValue(),
                                             labels[i+1]->getText()
                                             .getFloatValue())
                                            );
        mPos.push_back(point);
        labels[i]->onTextChange = [this, i]
        {
            mPos[mPos.size()-1]->
            setX(mControlPanel->getLabels()[i]->getText()
                 .getFloatValue());
        };
        labels[i+1]->onTextChange = [this, i]
        {
            mPos[mPos.size()-1]->
            setY(mControlPanel->getLabels()[i+1]->getText()
                 .getFloatValue());
        };
    }
}
