/*
  ==============================================================================

    Model_Manager.cpp
    Created: 30 Sep 2019 3:30:43pm
    Author:  Silver

  ==============================================================================
*/

#include "Model_Manager.h"

ModelManager::ModelManager()
{
    
}

ModelManager::~ModelManager()
{
    
}

std::vector<float> ModelManager::calVBAP(const std::vector<std::shared_ptr<Label>>& inPos)
{
    std::cout << "Warning: not inplementing the VBAP model" << std::endl;
    std::vector<float> vec;
    return vec;
}
