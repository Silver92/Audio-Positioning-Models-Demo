/*
  ==============================================================================

    Audio_Helper.h
    Created: 3 Oct 2019 12:29:28pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

inline float denormalize(float inValue)
{
    float absValue = fabs(inValue);
    
    if (absValue < 1e-15) {
        return  0.0f;
    } else {
        return inValue;
    }
}
