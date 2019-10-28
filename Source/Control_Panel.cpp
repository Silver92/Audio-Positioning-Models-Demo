/*
  ==============================================================================

    Control_Panel.cpp
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#include "Control_Panel.h"

ControlPanel::ControlPanel()
{
    setSize (CONTROL_PANEL_WIDTH, CONTROL_PANEL_HEIGHT);

    
    mComboBox.reset(new ComboBox());
    mComboBox->setBounds(0, 0, getWidth(), 30);
    mComboBox->addItem("VBAP", 1);
    mComboBox->addItem("MDAP", 2);
    mComboBox->addItem("DBAP", 3);
    mComboBox->setSelectedItemIndex(1);
    addAndMakeVisible(mComboBox.get());
    
}

ControlPanel::~ControlPanel()
{
    
}

void ControlPanel::setModel(PanelModel inModel)
{
    
}

void ControlPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    
}

void ControlPanel::getModel()
{
    
}
