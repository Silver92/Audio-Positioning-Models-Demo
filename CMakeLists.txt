cmake_minimum_required(VERSION 3.22)

project(AudioPositioningDemo VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# set(JUCE_ENABLE_MODULE_SOURCE_GROUPS ON)

set(TargetName ${PROJECT_NAME})

# JUCE is setup as a submodule in the /JUCE folder
# Locally, you must run `git submodule update --init --recursive` once
# and later `git submodule update --remote --merge` to keep it up to date
# On Github Actions, this is done as a part of actions/checkout
add_subdirectory(JUCE)

# find_package(JUCE CONFIG REQUIRED)
juce_add_gui_app(${TargetName}
    PRODUCT_NAME "Audio Positioning Demo")

file(GLOB_RECURSE SourceFiles 
    "${CMAKE_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_SOURCE_DIR}/Source/*.h")

target_sources(${TargetName} PRIVATE ${SourceFiles})

source_group("Source Files" FILES 
    ${CMAKE_SOURCE_DIR}/Source/MainComponent.h
    ${CMAKE_SOURCE_DIR}/Source/MainComponent.cpp
    ${CMAKE_SOURCE_DIR}/Source/Main.cpp
)

source_group("Source Files/Models" FILES 
    ${CMAKE_SOURCE_DIR}/Source/Models/DBAP.h
    ${CMAKE_SOURCE_DIR}/Source/Models/DBAP.cpp
    ${CMAKE_SOURCE_DIR}/Source/Models/Listener_Component.h
    ${CMAKE_SOURCE_DIR}/Source/Models/Listener_Component.cpp
    ${CMAKE_SOURCE_DIR}/Source/Models/MDAP.h
    ${CMAKE_SOURCE_DIR}/Source/Models/MDAP.cpp
    ${CMAKE_SOURCE_DIR}/Source/Models/Model_Manager.h
    ${CMAKE_SOURCE_DIR}/Source/Models/Model_Manager.cpp
    ${CMAKE_SOURCE_DIR}/Source/Models/SoundSource_Component.h
    ${CMAKE_SOURCE_DIR}/Source/Models/SoundSource_Component.cpp
    ${CMAKE_SOURCE_DIR}/Source/Models/Speaker_Component.h
    ${CMAKE_SOURCE_DIR}/Source/Models/Speaker_Component.cpp
    ${CMAKE_SOURCE_DIR}/Source/Models/VBAP.h
    ${CMAKE_SOURCE_DIR}/Source/Models/VBAP.cpp
)

source_group("Source Files/Other" FILES 
    ${CMAKE_SOURCE_DIR}/Source/Other/Audio_Helper.h
    ${CMAKE_SOURCE_DIR}/Source/Other/Parameters.h
    ${CMAKE_SOURCE_DIR}/Source/Other/PresetManager.h
    ${CMAKE_SOURCE_DIR}/Source/Other/PresetManager.cpp
)

source_group("Source Files/UI" FILES 
    ${CMAKE_SOURCE_DIR}/Source/UI/2D_View_Subpanel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/2D_View_Subpanel.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/Control_Panel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/Control_Panel.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/DBAP_Control_Subpanel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/DBAP_Control_Subpanel.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/Input_Label.h
    ${CMAKE_SOURCE_DIR}/Source/UI/Input_Label.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/MDAP_Control_Subpanel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/MDAP_Control_Subpanel.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/Panel_Base.h
    ${CMAKE_SOURCE_DIR}/Source/UI/Panel_Base.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/PositionControl_Panel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/PositionControl_Panel.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/UI_Dimensions.h
    ${CMAKE_SOURCE_DIR}/Source/UI/VBAP_Control_Subpanel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/VBAP_Control_Subpanel.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/View_Component_Base.h
    ${CMAKE_SOURCE_DIR}/Source/UI/View_Component_Base.cpp
    ${CMAKE_SOURCE_DIR}/Source/UI/View_Panel.h
    ${CMAKE_SOURCE_DIR}/Source/UI/View_Panel.cpp
)

target_include_directories(${TargetName} PRIVATE 
    "${CMAKE_SOURCE_DIR}/Source"
    "${CMAKE_SOURCE_DIR}/Source/Models"
    "${CMAKE_SOURCE_DIR}/Source/Other"
    "${CMAKE_SOURCE_DIR}/Source/UI")

target_compile_definitions(${TargetName} PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_PROJECT_NAME>"
    JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:${TargetName},JUCE_VERSION>")

target_link_libraries(${TargetName}
    PRIVATE
    juce::juce_analytics
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_core
    juce::juce_data_structures
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
    juce::juce_audio_utils
    juce::juce_dsp
    PUBLIC
    juce::juce_recommended_warning_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_config_flags)

# ----------------------------------------------------------------------------------------------------
# adding any custom modules you might have:
# add_subdirectory(Modules)

# optionally, we're also adding the unit tests:
# option(BUILD_UNIT_TESTS "Build JUCE prototype examples" OFF)

# if(BUILD_UNIT_TESTS)
# enable_testing()
# add_subdirectory(Tests)
# endif()