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

void MDAP::calculate(const std::vector<std::shared_ptr<juce::Point<float>>>& inPos,
                     std::vector<float>& inGainVectors)
{
    std::cout << "MDAP Start " << std::endl;
    // Get the listener position
    float x0 = inPos[0]->getX();
    float y0 = inPos[0]->getY();
    
    // Calculate all the unit vectors of listener-speaker and
    // listener-sound source
    std::vector<juce::Point<float>> ampVectors;
    for (int i = 1; i < inPos.size(); i++) {
        
        auto x = inPos[i]->getX() - x0;
        auto y = inPos[i]->getY() - y0;
        
        auto length = sqrt(juce::square(x) + juce::square(y));
        
        ampVectors.push_back(juce::Point<float>(x/length, y/length));
        
        std::cout << "vector x: " << x/length << " vector y: " << y/length << std::endl;
    }
    
    // Create 2 vectors by spinning the source vector clockwise
    // and anticlockwise.
    auto vSourceX = ampVectors[ampVectors.size()-1].getX();
    auto vSourceY = ampVectors[ampVectors.size()-1].getY();
    
    float theta = (15.f/180.f) * juce::MathConstants<float>::pi;
    auto cos_theta = juce::dsp::FastMathApproximations::cos(theta);
    auto sin_theta = juce::dsp::FastMathApproximations::sin(theta);
    auto m_cos_theta = juce::dsp::FastMathApproximations::cos(-theta);
    auto m_sin_theta = juce::dsp::FastMathApproximations::sin(-theta);
    auto vSourceX1 = vSourceX * cos_theta - vSourceY * sin_theta;
    auto vSourceY1 = vSourceX * sin_theta + vSourceY * cos_theta;
    auto vSourceX2 = vSourceX * m_cos_theta - vSourceY * m_sin_theta;
    auto vSourceY2 = vSourceX * m_sin_theta + vSourceY * m_cos_theta;
    
    std::cout << "cos(theta): " << cos_theta << " sin(theta): " << sin_theta << std::endl;
    std::cout << "-cos(theta): " << m_cos_theta << " -sin(theta): " << m_sin_theta << std::endl;
    std::cout << "SourceX: " << vSourceX << " SourceY: " << vSourceY << std::endl;
    std::cout << "SourceX1: " << vSourceX1 << " SourceY1: " << vSourceY1 << std::endl;
    std::cout << "SourceX2: " << vSourceX2 << " SourceY2: " << vSourceY2 << std::endl;
    
    inGainVectors.clear();
    for (int i = 0; i < ampVectors.size() - 1; i++) {
        inGainVectors.push_back(0.f);
    }
    
    calculateGainDistribution(ampVectors, inGainVectors, vSourceX1, vSourceY1);
    calculateGainDistribution(ampVectors, inGainVectors, vSourceX2, vSourceY2);
    
    auto gainNum = inGainVectors.size();
    float sum = 0.f;
    for (int i = 0; i< gainNum; i++) {
        sum += inGainVectors[i] * inGainVectors[i];
    }
    sum = sqrt(sum);
    std::cout << "sum = " << sum << std::endl;
    for (int i = 0; i < gainNum; i++) {
        inGainVectors[i] =
        juce::Decibels::gainToDecibels(denormalize(inGainVectors[i] / sum));
        std::cout << "MDAP final gain: " << inGainVectors[i] << std::endl;
    }
}

void MDAP::calculateGainDistribution(std::vector<juce::Point<float> > &ampVectors,
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
