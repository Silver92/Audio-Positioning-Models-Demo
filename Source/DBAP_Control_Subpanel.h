/*
  ==============================================================================

    DBAP_Control_Subpanel.h
    Created: 30 Sep 2019 3:29:50pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "Input_Label.h"
#include "Control_Panel.h"

class DBAPSubpanel
:   public ControlPanel
{
public:
    DBAPSubpanel();
    ~DBAPSubpanel();
    
private:
    void paint (Graphics& g) override;
};
