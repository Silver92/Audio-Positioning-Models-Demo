/*
  ==============================================================================

    MDAP.h
    Created: 30 Sep 2019 3:26:22pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "Model_Manager.h"

class MDAP
: public ModelManager
{
public:
    MDAP();
    ~MDAP();
    
    void calculate(const std::vector<std::shared_ptr<Point<float>>>& inPos,
                   std::vector<float>& inGainVectors) override;
    
    void calculateGainDistribution(std::vector<Point<float> > &ampVectors,
                                   std::vector<float> &inGainVectors,
                                   float vSourceX,
                                   float vSourceY);
};
