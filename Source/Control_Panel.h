/*
  ==============================================================================

    Control_Panel.h
    Created: 30 Sep 2019 3:12:08pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"

enum PanelModel
{
    PanelModel_VBAP,
    PanelModel_MDAP,
    PanelModel_DBAP,
    PanelModel_TotalNumModels
};

class ControlPanel
:   public PanelBase,
    public ComboBox::Listener
{
public:
    ControlPanel();
    ~ControlPanel();
    
    void setModel(PanelModel inModel);
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    void getModel();
    
    virtual TextButton& getRunButton() = 0;
    virtual std::vector<std::shared_ptr<Point<float>>> getPos() = 0;
    virtual std::vector<float>& getGainVals() = 0;
    virtual std::vector<std::shared_ptr<Label>> getLabels() = 0;
    virtual void calPos() = 0;
    
private:
    
    std::unique_ptr<ComboBox> mComboBox;
    PanelModel mModelEnum;
    
};
