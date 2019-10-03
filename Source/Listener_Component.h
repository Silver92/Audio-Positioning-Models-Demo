/*
  ==============================================================================

    Listener_Component.h
    Created: 2 Oct 2019 8:32:59pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "View_Component_Base.h"

class Listener
:   public ViewComponentBase
{
public:
    Listener();
    ~Listener();
    void paint(Graphics& g) override;
    void mouseDown (const MouseEvent&) override;
private:
};
