/*
  ==============================================================================

    PresetManager.cpp
    Created: 3 Oct 2019 9:15:35pm
    Author:  Silver

  ==============================================================================
*/

#include "PresetManager.h"

#if JUCE_WINDOWS
    static const juce::String directorySeparator = "\\";
#elif JUCE_MAC
    static const String directorySeparator = "/";
#endif

#define PRESET_FILE_EXTENSION ".kpf"

PresetManager::PresetManager()
{
    mPresetDirectory =
    (juce::File::getSpecialLocation(juce::File::userDesktopDirectory)).getFullPathName();
    
    if (!juce::File(mPresetDirectory).exists()) {
        juce::File(mPresetDirectory).createDirectory();
    }
    
    for (juce::DirectoryIterator di (juce::File(mPresetDirectory),
                               false,
                               "*"+(juce::String)PRESET_FILE_EXTENSION,
                                juce::File::TypesOfFileToFind::findFiles); di.next();)
    {
        myCurrentPreset = di.getFile();
    }
    
    if (myCurrentPreset.exists()) {
        std::cout << "Preset exists" << std::endl;
        juce::XmlDocument xmlDoc(myCurrentPreset);
        posList = xmlDoc.getDocumentElement();
    } else {
        myCurrentPreset = juce::File(mPresetDirectory + directorySeparator +
                               "SpacialAudio" + PRESET_FILE_EXTENSION);
        myCurrentPreset.create();
        posList.reset(new juce::XmlElement("StateInfo"));
    }
}

PresetManager::~PresetManager()
{
    
}

void PresetManager::saveCurrentPreset(std::vector<std::shared_ptr<juce::Label>>& mPos,
                                      PanelModelType inType)
{
    // create an node to save the current model type
    juce::XmlElement* type = new juce::XmlElement("CurrentModelType");
    type->setAttribute("ModelType", inType);
    
    auto oldElement = posList->
    getChildByName("CurrentModelType");
    if (oldElement != nullptr) {
        posList->replaceChildElement(oldElement, type);
    } else {
        posList->addChildElement(type);
    }
    
    std::cout << "Combobox index saved: " <<
    posList->getChildByName("CurrentModelType")->
    getIntAttribute("ModelType") << std::endl;
    
    // create and add children model node
    juce::XmlElement* pos = new juce::XmlElement(ModelTypeLabel[inType]);
    for (int i = 0; i < mPos.size() - 1; i += 2)
    {
        // create an inner element..
        juce::String s1 = "x" + juce::String(i);
        juce::String s2 = "y" + juce::String(i);
        pos->setAttribute (s1, mPos[i]->getText());
        pos->setAttribute (s2, mPos[i+1]->getText());
        
        std::cout << "x: " << mPos[i]->getText() <<
        " y: " << mPos[i+1]->getText() << std::endl;
    }
    
    oldElement = posList->
    getChildByName(ModelTypeLabel[inType]);
    if (oldElement != nullptr) {
        posList->replaceChildElement(oldElement, pos);
    } else {
        posList->addChildElement(pos);
    }
    
    posList->writeTo(myCurrentPreset);
    
    std::cout << "Total num elements: " <<
    posList->getNumChildElements() << std::endl;
    for (int i = 0; i < posList->getNumChildElements(); i++) {
        std::cout << "Element: " <<
        posList->getChildElement(i)->getTagName()
        << std::endl;
    }
}

void PresetManager::loadPreviousPreset(std::vector<std::shared_ptr<juce::Label>>& mPos,
                                       PanelModelType inType)
{
    // check we're looking at the right kind of document..
    if (posList != nullptr) {
        // check the main tag
        if (posList->getTagName() == "StateInfo") {
            auto element = posList->
            getChildByName(ModelTypeLabel[inType]);
            std::cout << "Loading buffer nullptr? " <<
            (element == nullptr) << std::endl;
            if (element) {
                for (int i = 0; i < mPos.size() - 1; i += 2)
                {
                    // create an inner element..
                    juce::String s1 = "x" + juce::String(i);
                    juce::String s2 = "y" + juce::String(i);
                    mPos[i]->setText(element->getStringAttribute(s1),
                        juce::dontSendNotification);
                    mPos[i+1]->setText(element->getStringAttribute(s2),
                        juce::dontSendNotification);
                    
                    std::cout << "x0: " << mPos[i]->getText()
                            << " y0: " << mPos[i+1]->getText()
                    << std::endl;
                }
            }
        }
    }
}

PanelModelType PresetManager::loadPreviousModelType()
{
    if (posList != nullptr) {
        // check the main tag
        if (posList->getTagName() == "StateInfo") {
            auto typeElement = posList->
            getChildByName("CurrentModelType");
            if (typeElement != nullptr) {
                return (PanelModelType)typeElement->
                getIntAttribute("ModelType");
            }
        }
    }
    
    std::cout << "No model type saved" << std::endl;
    return PanelModelType_VBAP;
}
