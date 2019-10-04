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
{
    mPresetDirectory =
    (File::getSpecialLocation(File::userDesktopDirectory)).getFullPathName();
    
    if (!File(mPresetDirectory).exists()) {
        File(mPresetDirectory).createDirectory();
    }
}

PresetManager::~PresetManager()
{
    
}

void PresetManager::saveCurrentPreset()
{
    // create an outer node
    XmlElement posList ("StateInfo");
    
    // create and add children node
    XmlElement* pos = new XmlElement("preset");
    for (int i = 0; i < 2; ++i)
    {
        // create an inner element..
        String s1 = "x" + String(i);
        String s2 = "y" + String(i);
        pos->setAttribute (s1, 100);
        pos->setAttribute (s2, 200);
    }
    posList.addChildElement(pos);
    
    // create a file
    File presetFile = File(mPresetDirectory + directorySeparator + "SpacialAudio" + PRESET_FILE_EXTENSION);
    if (!presetFile.exists()) {
        presetFile.create();
    } else {
        presetFile.deleteFile();
    }
    
    posList.writeTo(presetFile);
    myCurrentPreset = presetFile;
}

void PresetManager::loadPreviousPreset()
{
    for (DirectoryIterator di (File(mPresetDirectory),
                               false,
                               "*"+(String)PRESET_FILE_EXTENSION,
                               File::TypesOfFileToFind::findFiles); di.next();)
    {
        myCurrentPreset = di.getFile();
    }
    
    // check we're looking at the right kind of document..
    if (myCurrentPreset.exists()) {
        std::cout << "Preset exists" << std::endl;
        XmlDocument xmlDoc(myCurrentPreset);
        std::unique_ptr<XmlElement> mainElement = xmlDoc.getDocumentElement();

        if (mainElement != nullptr) {
            // check the main tag
            if (mainElement->getTagName() == "StateInfo") {
                forEachXmlChildElement (*mainElement, e) {
                    if (e->hasTagName("preset")) {
                        std::cout << e->getIntAttribute("x0") << std::endl;
                        std::cout << e->getIntAttribute("y0") << std::endl;
                    }
                }
            }
        }
    }
}
