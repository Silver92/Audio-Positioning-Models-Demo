/*
  ==============================================================================

    PresetManager.cpp
    Created: 3 Oct 2019 9:15:35pm
    Author:  Silver

  ==============================================================================
*/

#include "PresetManager.h"

#if JUCE_WINDOWS
    static const String directorySeparator = "\\";
#elif JUCE_MAC
    static const String directorySeparator = "/";
#endif

#define PRESET_FILE_EXTENSION ".kpf"

PresetManager::PresetManager()
: posList("StateInfo")
{
    mPresetDirectory =
    (File::getSpecialLocation(File::userDesktopDirectory)).getFullPathName();
    
    if (!File(mPresetDirectory).exists()) {
        File(mPresetDirectory).createDirectory();
    }
    
    for (DirectoryIterator di (File(mPresetDirectory),
                               false,
                               "*"+(String)PRESET_FILE_EXTENSION,
                               File::TypesOfFileToFind::findFiles); di.next();)
    {
        myCurrentPreset = di.getFile();
    }
    if (myCurrentPreset.exists()) {
        std::cout << "Preset exists" << std::endl;
        XmlDocument xmlDoc(myCurrentPreset);
        mainElement = xmlDoc.getDocumentElement();
    }
}

PresetManager::~PresetManager()
{
    
}

void PresetManager::saveCurrentPreset(std::vector<std::shared_ptr<Label>>& mPos,
                                      PanelModelType inType)
{
    // create an element to save the current model type
    XmlElement* type = new XmlElement("CurrentModelType");
    type->setAttribute("ModelType", inType);
    if (posList.containsChildElement(type)) {
        auto oldElement = posList.
        getChildByName("CurrentModelType");
        posList.replaceChildElement(oldElement, type);
    } else {
        posList.addChildElement(type);
    }
    
    // create and add children node
    XmlElement* pos = new XmlElement(ModelTypeLabel[inType]);
    for (int i = 0; i < mPos.size() - 1; i += 2)
    {
        // create an inner element..
        String s1 = "x" + String(i);
        String s2 = "y" + String(i);
        pos->setAttribute (s1, mPos[i]->getText());
        pos->setAttribute (s2, mPos[i+1]->getText());
    }
    if (posList.containsChildElement(pos)) {
        auto oldElement = posList.
        getChildByName(ModelTypeLabel[inType]);
        posList.replaceChildElement(oldElement, pos);
    } else {
        posList.addChildElement(pos);
    }
    
    
    // create a file
    File presetFile = File(mPresetDirectory + directorySeparator +
                           "SpacialAudio" + PRESET_FILE_EXTENSION);
    if (!presetFile.exists()) {
        presetFile.create();
    } else {
        presetFile.deleteFile();
    }
    
    posList.writeTo(presetFile);
}

void PresetManager::loadPreviousPreset(std::vector<std::shared_ptr<Label>>& mPos,
                                       PanelModelType inType)
{
    // check we're looking at the right kind of document..
    if (mainElement != nullptr) {
        // check the main tag
        if (mainElement->getTagName() == "StateInfo") {
            auto element = mainElement->
            getChildByName(ModelTypeLabel[inType]);
            std::cout << "nullptr? " << (element == nullptr) << std::endl;
                if (element) {
                    std::cout << element->getStringAttribute("x0") << std::endl;
                    std::cout << element->getStringAttribute("y0") << std::endl;
                    for (int i = 0; i < mPos.size() - 1; i += 2)
                    {
                        // create an inner element..
                        String s1 = "x" + String(i);
                        String s2 = "y" + String(i);
                        mPos[i]->setText(element->getStringAttribute(s1),
                                         dontSendNotification);
                        mPos[i+1]->setText(element->getStringAttribute(s2),
                                           dontSendNotification);
                        
                        std::cout << mPos[i]->getText() << " "
                        << mPos[i+1]->getText() << std::endl;
                    }
                }
        }
    }
}

PanelModelType PresetManager::loadPreviousModelType()
{
    if (mainElement != nullptr) {
        // check the main tag
        if (mainElement->getTagName() == "StateInfo") {
            auto typeElement = mainElement->
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
