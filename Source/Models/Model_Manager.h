/*
  ==============================================================================

    Model_Manager.h
    Created: 30 Sep 2019 3:30:43pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "../Audio_Helper.h"
#include "juce_gui_basics/juce_gui_basics.h"

class ModelManager
{
public:
    ModelManager();
    virtual ~ModelManager();
    
    virtual void calculate(const std::vector<std::shared_ptr<juce::Point<float>>>& inPos,
                           std::vector<float>& inGainVectors) = 0;
    
private:
};
