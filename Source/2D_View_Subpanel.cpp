/*
  ==============================================================================

    2D_View_Subpanel.cpp
    Created: 30 Sep 2019 3:27:43pm
    Author:  Silver

  ==============================================================================
*/

#include "2D_View_Subpanel.h"

TwoDSubpanel::TwoDSubpanel()
{
    setSize(VIEW_PANEL_WIDTH, VIEW_PANEL_HEIGHT);
}

TwoDSubpanel::~TwoDSubpanel()
{
    
}

void TwoDSubpanel::paint(Graphics& g)
{
    
}

void TwoDSubpanel::drawComponents(const std::vector<std::shared_ptr<Label>>& inPos,
                                  const std::vector<float>& dBFSs)
{
    listener.clear();
    speakers.clear();
    soundSource.clear();
    for (int i = 0; i < inPos.size()-1; i += 2) {
        // Draw Listener
        if (i == 0) {
            std::shared_ptr<Listener> mListener (new Listener());
            mListener->setCentrePosition(inPos[i]->getText().getFloatValue(),
                                         inPos[i+1]->getText().getFloatValue());
            addAndMakeVisible(mListener.get());
            listener.push_back(mListener);
        // Draw Speakers
        } else if (i > 0 && i < inPos.size() - 3) {
            std::shared_ptr<Speaker> mTestSpeaker (new Speaker(String(dBFSs[i], 1)));
            mTestSpeaker->setCentrePosition(inPos[i]->getText().getFloatValue(),
                                            inPos[i+1]->getText().getFloatValue());
            addAndMakeVisible(mTestSpeaker.get());
            speakers.push_back(mTestSpeaker);
        // Draw Sound Source
        } else {
            std::shared_ptr<SoundSource> mSoundSource (new SoundSource());
            mSoundSource->setCentrePosition(inPos[i]->getText().getFloatValue(),
                                            inPos[i+1]->getText().getFloatValue());
            addAndMakeVisible(mSoundSource.get());
            soundSource.push_back(mSoundSource);
        }
    }
}
