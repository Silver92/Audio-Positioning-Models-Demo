/*
  ==============================================================================

    VBAP.h
    Created: 30 Sep 2019 3:26:06pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "Model_Manager.h"

class VBAP
: public ModelManager
{
public:
    VBAP();
    ~VBAP();
    
    void calVBAP(std::vector<std::shared_ptr<Label>>& inPos) override;
};
