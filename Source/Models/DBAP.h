/*
  ==============================================================================

    DBAP.h
    Created: 30 Sep 2019 3:26:29pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include "Model_Manager.h"
#include "juce_audio_basics/juce_audio_basics.h"

class DBAP
: public ModelManager
{
public:
    DBAP();
    ~DBAP();
    
    void calculate(const std::vector<std::shared_ptr<juce::Point<float>>>& inPos,
    std::vector<float>& inGainVectors) override;
};
