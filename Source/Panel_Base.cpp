/*
  ==============================================================================

    Panel_Base.cpp
    Created: 30 Sep 2019 5:15:58pm
    Author:  Silver

  ==============================================================================
*/

#include "Panel_Base.h"

PanelBase::PanelBase(std::shared_ptr<ModelManager> inModelManager)
{
    mModelManager = inModelManager;
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint (Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 2);
}
