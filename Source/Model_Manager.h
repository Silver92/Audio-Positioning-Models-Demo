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
    
    virtual std::vector<float> calVBAP(const std::vector<std::shared_ptr<Label>>& inPos) = 0;
    
private:
};
