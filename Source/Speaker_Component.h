/*
  ==============================================================================

    Speaker_Component.h
    Created: 2 Oct 2019 8:33:15pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "View_Component_Base.h"

class Speaker
:   public ViewComponentBase
{
public:
    Speaker();
    ~Speaker();
    void paint(Graphics& g) override;
    void mouseDown (const MouseEvent&) override;
};
