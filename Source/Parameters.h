/*
  ==============================================================================

    Parameters.h
    Created: 2 Jan 2020 9:49:01am
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

enum PanelModelType
{
    PanelModelType_VBAP,
    PanelModelType_MDAP,
    PanelModelType_DBAP,
    PanelModelType_TotalNumModels
};

static juce::String ModelTypeLabel[PanelModelType_TotalNumModels] =
{
    "VBAP",
    "MDAP",
    "DBAP"
};
