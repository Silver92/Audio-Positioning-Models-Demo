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

void TwoDSubpanel::drawComponents(const std::vector<std::shared_ptr<Point<float>>>& inPos,
                                  const std::vector<float>& dBFSs,
                                  const bool hasSoundSource)
{
    listener.clear();
    speakers.clear();
    soundSource.clear();
    int speakerIndex = 0;
    for (int i = 0; i < inPos.size(); i++) {
        // Draw Listener
        if (i == 0) {
            std::shared_ptr<Listener> mListener (new Listener());
            mListener->setCentrePosition(inPos[i]->getX(),
                                         inPos[i]->getY());
            addAndMakeVisible(mListener.get());
            listener.push_back(mListener);
        // Draw Sound Source
        } else if ((i == inPos.size() - 1) && hasSoundSource) {
            std::shared_ptr<SoundSource> mSoundSource (new SoundSource());
            mSoundSource->setCentrePosition(inPos[i]->getX(),
                                            inPos[i]->getY());
            addAndMakeVisible(mSoundSource.get());
            soundSource.push_back(mSoundSource);
        // Draw Speakers
        } else {
            std::shared_ptr<Speaker> mTestSpeaker (new Speaker(String(dBFSs[speakerIndex], 1)));
            speakerIndex++;
            mTestSpeaker->setCentrePosition(inPos[i]->getX(),
                                            inPos[i]->getY());
            addAndMakeVisible(mTestSpeaker.get());
            speakers.push_back(mTestSpeaker);
        }
    }
}
