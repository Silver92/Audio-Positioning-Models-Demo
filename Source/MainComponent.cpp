/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
: mModelType(PanelModelType_TotalNumModels)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    /** Load the preset Manager and preset*/
    mPresetManager.reset(new PresetManager());
    
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
    
    /** Load the model and the user input panel*/
    mControlPanel->getComboBox().
    setSelectedId(mPresetManager->loadPreviousModelType() + 1);
}

MainComponent::~MainComponent()
{
    mPresetManager->
    saveCurrentPreset(mControlPanel->getLabels(),
                      mModelType);
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
    if (mModelType != PanelModelType_TotalNumModels) {
        std::cout << "save preset run " << ModelTypeLabel[mModelType] << std::endl;
        mPresetManager->
        saveCurrentPreset(mControlPanel->getLabels(),
                          mModelType);
    }

    PanelModelType modelType = static_cast<PanelModelType>
        (comboBoxThatHasChanged.getSelectedItemIndex());
    
    switch (modelType) {
            
        case (PanelModelType_VBAP):{
            mControlPanel->getPositionPanel().
            reset(new VBAPSubpanel());
            mModelManager.reset(new VBAP());
            mControlPanel->getRunButton().onClick = [this]
            {
                calModelAndDraw(mModelType);
            };
        }break;
            
        case (PanelModelType_MDAP):{
            mControlPanel->getPositionPanel().
            reset(new MDAPSubpanel());
            mModelManager.reset(new MDAP());
            mControlPanel->getRunButton().onClick = [this]
            {
                calModelAndDraw(mModelType);
            };
        }break;
            
        case (PanelModelType_DBAP):{
            mControlPanel->getPositionPanel().
            reset(new DBAPSubpanel());
            mModelManager.reset(new DBAP());
            mControlPanel->getRunButton().onClick = [this]
            {
                calModelAndDraw(mModelType);
            };
        }break;
            
        default:
        case (PanelModelType_TotalNumModels):{
            jassertfalse;
        }break;
            
    }
    
    addAndMakeVisible(mControlPanel->getPositionPanel().get());
    
    mPresetManager->
    loadPreviousPreset(mControlPanel->getLabels(), modelType);
    prepareInputData();
    calModelAndDraw(modelType);
    
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
        labels[i]->onTextChange = [this, i, point]
        {
            point->
            setX(mControlPanel->getLabels()[i]->getText()
                 .getFloatValue());
        };
        labels[i+1]->onTextChange = [this, i, point]
        {
            point->
            setY(mControlPanel->getLabels()[i+1]->getText()
                 .getFloatValue());
        };
        
        
    }
}

void MainComponent::calModelAndDraw(PanelModelType modelType) {
    mModelManager->calculate(mPos, mGainVals);
    modelType == PanelModelType_DBAP ?
    (mViewPanel->m2DPanel->
     drawComponents(mPos, mGainVals, false)) :
    (mViewPanel->m2DPanel->
     drawComponents(mPos, mGainVals));
}
