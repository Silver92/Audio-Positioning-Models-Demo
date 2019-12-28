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
    mControlPanel.reset(new VBAPSubpanel());
    mControlPanel->setBounds(VIEW_PANEL_WIDTH,
                             0,
                             CONTROL_PANEL_WIDTH,
                             CONTROL_PANEL_HEIGHT);
    addAndMakeVisible(mControlPanel.get());
    
    /** Initiate the model manager */
    mModelManager.reset(new VBAP());
    
    /** Make connections between view and models */
    modelInteractions();
    
    /** Load the preset Manager and preset*/
    mPresetManager.reset(new PresetManager());
    mPresetManager->loadPreviousPreset(mControlPanel->getLabels());
    prepareInputData();
    mModelManager->calculate(mPos,
                             mGainVals);
    mViewPanel->m2DPanel->drawComponents(mPos,
                                         mGainVals);
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
void MainComponent::comboBoxChanged(ComboBox& comboBoxThatHasChanged)
{
    PanelModelType modelType = static_cast<PanelModelType>
        (comboBoxThatHasChanged.getSelectedItemIndex());
    
    switch (modelType) {
            
        case (PanelModel_VBAP):{
            mControlPanel.reset(new VBAPSubpanel());
            mModelManager.reset(new VBAP());
            
        }break;
            
        case (PanelModel_MDAP):{
            mControlPanel.reset(new MDAPSubpanel());
            mModelManager.reset(new MDAP());
            
        }break;
            
        case (PanelModel_DBAP):{
            mControlPanel.reset(new DBAPSubpanel());
            mModelManager.reset(new DBAP());
                        
        }break;
            
        default:
        case (PanelModel_TotalNumModels):{
            jassertfalse;
        }break;
            
    }
    
    mControlPanel->setBounds(VIEW_PANEL_WIDTH,
                             0,
                             CONTROL_PANEL_WIDTH,
                             CONTROL_PANEL_HEIGHT);
    addAndMakeVisible(mControlPanel.get());
    
    modelInteractions();
    prepareInputData();
    mModelType = modelType;
}

void MainComponent::modelInteractions()
{
    /**
     Make connections between view and models
     */
    mControlPanel->getRunButton().onClick = [this]
    {
        mModelManager->calculate(mPos, mGainVals);
        //        mViewPanel->m2DPanel->
        //        drawComponents(mPos, mGainVals);
    };
    
    mControlPanel->getComboBox().onChange = [this]
    {
        std::cout << "combo box changes" << std::endl;
        comboBoxChanged(mControlPanel->getComboBox());
    };
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
        std::shared_ptr<Point<float>> point(new Point<float>
                                            (labels[i]->getText()
                                             .getFloatValue(),
                                             labels[i+1]->getText()
                                             .getFloatValue()));
        labels[i]->onTextChange = [this, i, point, labels]
                                    {point->
                                    setX(labels[i]->getText()
                                    .getFloatValue());};
        labels[i+1]->onTextChange = [this, i, point, labels]
                                    {point->
                                    setY(labels[i+1]->getText()
                                    .getFloatValue());};
        mPos.push_back(point);
    }
}
