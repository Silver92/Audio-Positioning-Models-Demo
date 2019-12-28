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
    
    /** Initiate the control panel*/
    mControlPanel.reset(new VBAPSubpanel());
    mControlPanel->setBounds(VIEW_PANEL_WIDTH,
                             COMBOBOX_HEIGHT,
                             CONTROL_PANEL_WIDTH,
                             CONTROL_PANEL_HEIGHT);
    addAndMakeVisible(mControlPanel.get());
    
    /** Initiate the view panel */
    mViewPanel.reset(new ViewPanel());
    addAndMakeVisible(mViewPanel.get());
    
    /** Initiate the model manager */
    mModelManager.reset(new VBAP());
    
    /** Set up the run button to calculate when clicked */
    mControlPanel->getRunButton().onClick = [this]
    {
        mModelManager->calculate(mControlPanel->getPos(),
                                 mControlPanel->getGainVals());
        mViewPanel->m2DPanel->drawComponents(mControlPanel->getPos(),
                                             mControlPanel->getGainVals());
        
    };
    
    /** Load the preset Manager and preset*/
    mPresetManager.reset(new PresetManager());
    mPresetManager->loadPreviousPreset(mControlPanel->getLabels());
    mControlPanel->calPos();
    mModelManager->calculate(mControlPanel->getPos(),
                             mControlPanel->getGainVals());
    mViewPanel->m2DPanel->drawComponents(mControlPanel->getPos(),
                                         mControlPanel->getGainVals());
    
    /** Inittiate the combobox*/
    mComboBox.reset(new ComboBox());
    mComboBox->setBounds(VIEW_PANEL_WIDTH + 2,
                         0 + 2,
                         CONTROL_PANEL_WIDTH - 2*2,
                         COMBOBOX_HEIGHT - 2*2);
    mComboBox->addItem("VBAP", 1);
    mComboBox->addItem("MDAP", 2);
    mComboBox->addItem("DBAP", 3);
    mComboBox->addListener(this);
    mComboBox->setColour(ComboBox::ColourIds::backgroundColourId, Colours::whitesmoke);
    mComboBox->setColour(ComboBox::ColourIds::arrowColourId, Colours::whitesmoke);
    addAndMakeVisible(mComboBox.get());
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

//==============================================================================
void MainComponent::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    PanelModelType modelType = static_cast<PanelModelType>
        (comboBoxThatHasChanged->getSelectedItemIndex());
    
    switch (modelType) {
            
        case (PanelModel_VBAP):{
            comboBoxThatHasChanged->
            setText(comboBoxThatHasChanged->getItemText(modelType));
            mControlPanel.reset(new VBAPSubpanel());
            mModelManager.reset(new VBAP());
            
        }break;
            
        case (PanelModel_MDAP):{
            comboBoxThatHasChanged->
            setText(comboBoxThatHasChanged->getItemText(modelType));
            mControlPanel.reset(new MDAPSubpanel());
            mModelManager.reset(new MDAP());
            
        }break;
            
        case (PanelModel_DBAP):{
            comboBoxThatHasChanged->
            setText(comboBoxThatHasChanged->getItemText(modelType));
            mControlPanel.reset(new DBAPSubpanel());
            mModelManager.reset(new DBAP());
                        
        }break;
            
        default:
        case (PanelModel_TotalNumModels):{
            jassertfalse;
        }break;
            
    }
    
    mControlPanel->setBounds(VIEW_PANEL_WIDTH,
                             COMBOBOX_HEIGHT,
                             CONTROL_PANEL_WIDTH,
                             CONTROL_PANEL_HEIGHT);
    addAndMakeVisible(mControlPanel.get());
    mControlPanel->getRunButton().onClick = [this]
    {
        mModelManager->calculate(mControlPanel->getPos(),
                                 mControlPanel->getGainVals());
        mViewPanel->m2DPanel->drawComponents(mControlPanel->getPos(),
                                             mControlPanel->getGainVals());
        
    };
    mControlPanel->calPos();
    
    mModelType = modelType;
}
