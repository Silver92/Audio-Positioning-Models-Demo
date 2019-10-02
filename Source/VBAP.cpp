/*
  ==============================================================================

    VBAP.cpp
    Created: 30 Sep 2019 3:26:06pm
    Author:  Silver

  ==============================================================================
*/

#include "VBAP.h"

VBAP::VBAP()
{
    
}

VBAP::~VBAP()
{
    
}

void VBAP::calVBAP(std::vector<std::shared_ptr<Label>>& inPos)
{
    std::vector<float> ampVectors;
    for (int i = 2; i < inPos.size()-1; i += 2) {
        float x0 = inPos[0]->getText().getFloatValue();
        float y0 = inPos[1]->getText().getFloatValue();
        ampVectors.push_back(inPos[i]->getText().getFloatValue() - x0);
        ampVectors.push_back(inPos[i+1]->getText().getFloatValue() - y0);
    }
}
