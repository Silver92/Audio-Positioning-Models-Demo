/*
  ==============================================================================

    2D_View_Subpanel.h
    Created: 30 Sep 2019 3:27:43pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Panel_Base.h"
#include "Speaker_Component.h"
#include "SoundSource_Component.h"
#include "Listener_Component.h"

class TwoDSubpanel
:   public PanelBase
{
public:
    
    TwoDSubpanel();
    ~TwoDSubpanel();
    
    void paint(Graphics& g) override;
    void drawComponents(const std::vector<std::shared_ptr<Label>>& inPos,
                        const std::vector<float>& dBFSs);
    
private:
    std::vector<std::shared_ptr<Speaker>> speakers;
    std::vector<std::shared_ptr<SoundSource>> soundSource;
    std::vector<std::shared_ptr<Listener>> listener;
};
