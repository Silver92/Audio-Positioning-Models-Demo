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

std::vector<float> VBAP::calVBAP(const std::vector<std::shared_ptr<Label>>& inPos)
{
    std::vector<float> ampVectors;
    float x0 = inPos[0]->getText().getFloatValue();
    float y0 = inPos[1]->getText().getFloatValue();
    for (int i = 2; i < inPos.size()-1; i += 2) {
        
        auto x = inPos[i]->getText().getFloatValue() - x0;
        auto y = inPos[i+1]->getText().getFloatValue() - y0;
        
        auto length = sqrt(square(x) + square(y));
        ampVectors.push_back(x / length);
        ampVectors.push_back(y / length);
        
    }
    
    auto vSourceX = ampVectors[ampVectors.size()-2];
    auto vSourceY = ampVectors[ampVectors.size()-1];
    decltype(vSourceX) maxDotProduct = 0;
    decltype(vSourceX) maxDotProduct2 = 0;
    int index1 = -10;
    int index2 = -10;
    for (int i = 0; i < ampVectors.size() - 3; i += 2) {
        decltype(vSourceX) dotProduct = ampVectors[i] * vSourceX +
        ampVectors[i+1] * vSourceY;
        
        if (dotProduct > maxDotProduct) {
            index2 = index1;
            index1 = i;
            maxDotProduct2 = maxDotProduct;
            maxDotProduct = dotProduct;
        } else if (dotProduct > maxDotProduct2) {
            index2 = i;
            maxDotProduct2 = dotProduct;
        }
    }
    
    std::cout << index1 << " " << index2 << std::endl;
    
    std::vector<float> gainVectors;
    auto denorm = (ampVectors[index1] * ampVectors[index2+1] -
                   ampVectors[index2] * ampVectors[index1+1]);
    auto gain1 = (vSourceX * ampVectors[index2+1] -
                  vSourceY * ampVectors[index2]) / denorm;
    auto gain2 = (vSourceY * ampVectors[index1] -
                  vSourceX * ampVectors[index1+1]) / denorm;
    
    std::cout << gain1 << " " << gain2 << std::endl;
    for (int i = 0; i < ampVectors.size() - 3; i +=2) {
        if (i == index1) {
            gainVectors.push_back(Decibels::gainToDecibels(denormalize(gain1)));
        } else if (i == index2) {
            gainVectors.push_back(Decibels::gainToDecibels(denormalize(gain2)));
        } else {
            gainVectors.push_back(Decibels::gainToDecibels(0.f));
        }
    }
    
    for (int i = 0; i < gainVectors.size(); i++) {
        std::cout << "gain: " << i << ": " << gainVectors[i] << std::endl;
    }
    
    return gainVectors;
}
