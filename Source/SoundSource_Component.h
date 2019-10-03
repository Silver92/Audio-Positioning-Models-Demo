/*
  ==============================================================================

    SoundSource_Component.h
    Created: 2 Oct 2019 8:33:40pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "View_Component_Base.h"

class SoundSource
:   public ViewComponentBase
{
public:
    SoundSource();
    ~SoundSource();
    void paint(Graphics& g) override;
    void mouseDown (const MouseEvent&) override;
};
