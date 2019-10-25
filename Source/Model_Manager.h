/*
  ==============================================================================

    Model_Manager.h
    Created: 30 Sep 2019 3:30:43pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "Audio_Helper.h"

class ModelManager
{
public:
    ModelManager();
    virtual ~ModelManager();
    
    virtual void calculate(const std::vector<std::shared_ptr<Point<float>>>& inPos,
                           std::vector<float>& inGainVectors) = 0;
    
private:
};
