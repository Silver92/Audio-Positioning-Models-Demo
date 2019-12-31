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
    std::cout << "DBAP start" << std::endl;
    
    // Get the listener position
    float x0 = inPos[0]->getX();
    float y0 = inPos[0]->getY();
    
    // Calculate all the unit vectors of listener-speaker
    std::vector<float> ampVectors;
    for (int i = 1; i < inPos.size(); i++) {
        
        auto x = inPos[i]->getX() - x0;
        auto y = inPos[i]->getY() - y0;
        
        auto length = sqrt(square(x) + square(y) + 1);
        std::cout << "length: " << length << std::endl;
        ampVectors.push_back(length);
        
    }
    
    auto sum = 0.f;
    for (int i = 0; i < ampVectors.size(); i++) {
        sum += 1 / square(ampVectors[i]);
    }
    sum = sqrt(sum);
    std::cout << "sum = " << sum << std::endl;
    
    float temp = 0;
    inGainVectors.clear();
    for (int i = 0; i < ampVectors.size(); i++) {
        temp = ampVectors[i] * sum;
        inGainVectors.push_back(
        Decibels::gainToDecibels(denormalize(1.f / temp)));
        
        std::cout << "DBAP final gain: " << inGainVectors[i] << std::endl;
        std::cout << "DBAP final gain: " << Decibels::gainToDecibels(denormalize(1.f / temp)) << std::endl;
    }
    
    for (int i = 0; i < inGainVectors.size(); i++) {
        std::cout << "DBAP final gain: " << inGainVectors[i] << std::endl;
    }
    
}
