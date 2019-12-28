/*
  ==============================================================================

    DBAP.cpp
    Created: 30 Sep 2019 3:26:29pm
    Author:  Silver

  ==============================================================================
*/

#include "DBAP.h"

DBAP::DBAP()
{
    
}

DBAP::~DBAP()
{
    
}

void DBAP::calculate(const std::vector<std::shared_ptr<Point<float>>>& inPos,
                     std::vector<float>& inGainVectors)
{
    
    // Get the listener position
    float x0 = inPos[0]->getX();
    float y0 = inPos[0]->getY();
    
    // Calculate all the unit vectors of listener-speaker
    std::vector<float> ampVectors;
    for (int i = 1; i < inPos.size(); i++) {
        
        auto x = inPos[i]->getX() - x0;
        auto y = inPos[i]->getY() - y0;
        
        auto length = sqrt(square(x) + square(y) + 1);
        
        ampVectors.push_back(length);
        
    }
    
    auto sum = 0.f;
    for (int i = 0; i < ampVectors.size(); i++) {
        sum += 1 / sqrt(ampVectors[i]);
    }
    
    for (int i = 0; i < ampVectors.size(); i++) {
        auto temp = ampVectors[i] * sum;
        inGainVectors.push_back(
        Decibels::gainToDecibels(denormalize(1.f / temp)));
    }
    
}
