/*
  ==============================================================================

    Model_Manager.h
    Created: 30 Sep 2019 3:30:43pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class ModelManager
{
public:
    ModelManager();
    virtual ~ModelManager();
    
    virtual void calVBAP(std::vector<std::shared_ptr<Label>>& inPos);
    
private:
};
