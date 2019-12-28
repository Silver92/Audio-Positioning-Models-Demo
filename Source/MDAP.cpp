/*
  ==============================================================================

    MDAP.cpp
    Created: 30 Sep 2019 3:26:22pm
    Author:  Silver

  ==============================================================================
*/

#include "MDAP.h"

MDAP::MDAP()
{
    
}

MDAP::~MDAP()
{
    
}

void MDAP::calculate(const std::vector<std::shared_ptr<Point<float>>>& inPos,
                     std::vector<float>& inGainVectors)
{
    // Get the listener position
    float x0 = inPos[0]->getX();
    float y0 = inPos[0]->getY();
    
    // Calculate all the unit vectors of listener-speaker and
    // listener-sound source
    std::vector<Point<float>> ampVectors;
    for (int i = 1; i < inPos.size(); i++) {
        
        auto x = inPos[i]->getX() - x0;
        auto y = inPos[i]->getY() - y0;
        
        auto length = sqrt(square(x) + square(y));
        
        ampVectors.push_back(Point<float>(x/length, y/length));
        
    }
    
    // Create 2 vectors by spinning the source vector clockwise
    // and anticlockwise.
    auto vSourceX = ampVectors[ampVectors.size()-1].getX();
    auto vSourceY = ampVectors[ampVectors.size()-1].getY();
    float theta = 15.f;
    auto vSourceX1 = vSourceX * cos(theta) - vSourceY * sin(theta);
    auto vSourceY1 = vSourceX * sin(theta) + vSourceY * cos(theta);
    auto vSourceX2 = vSourceX * cos(-theta) - vSourceY * sin(-theta);
    auto vSourceY2 = vSourceX * sin(-theta) + vSourceY * sin(-theta);
    
    inGainVectors.clear();
    for (int i = 0; i < ampVectors.size() - 1; i++) {
        inGainVectors.push_back(0.f);
    }
    
    calculateGainDistribution(ampVectors, inGainVectors, vSourceX1, vSourceY1);
    calculateGainDistribution(ampVectors, inGainVectors, vSourceX2, vSourceY2);
    
    for (int i = 0; i < inGainVectors.size(); i++) {
        inGainVectors[i] =
        Decibels::gainToDecibels(denormalize(inGainVectors[i] / 2.f));
    }
}

void MDAP::calculateGainDistribution(std::vector<Point<float> > &ampVectors,
                                     std::vector<float> &inGainVectors,
                                     float vSourceX,
                                     float vSourceY) {
    
    // Calculate the 2 max dot products of speaker vector and
    // the source vector and select the 2 max speaker vectors.
    decltype(vSourceX) maxDotProduct = -10;
    decltype(vSourceX) maxDotProduct2 = -10;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < ampVectors.size()-1; i++) {
        decltype(vSourceX) dotProduct = ampVectors[i].getX() * vSourceX +
        ampVectors[i].getY() * vSourceY;
        
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
    
    // Calculate the 2 gains of the 2 speakers with the maximum volumes
    auto denorm = (ampVectors[index1].getX() * ampVectors[index2].getY() -
                   ampVectors[index2].getX() * ampVectors[index1].getY());
    auto gain1 = (vSourceX * ampVectors[index2].getY() -
                  vSourceY * ampVectors[index2].getX()) / denorm;
    auto gain2 = (vSourceY * ampVectors[index1].getX() -
                  vSourceX * ampVectors[index1].getY()) / denorm;
    
    std::cout << gain1 << " " << gain2 << std::endl;
    
    // Denote the result to all the speakers
    for (int i = 0; i < ampVectors.size()-1; i++) {
        if (i == index1) {
            inGainVectors[i] += gain1;
        }
        else if (i == index2) {
            inGainVectors[i] += gain2;
        }
    }
    
    for (int i = 0; i < inGainVectors.size(); i++) {
        std::cout << "gain: " << i << ": " << inGainVectors[i] << std::endl;
    }
}
