/*
  ==============================================================================

    InputComponent.h
    Created: 19 May 2019 2:53:36pm
    Author:  kayaw

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class InputComponent    : public Component
{
public:
    InputComponent();
    ~InputComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputComponent)
};
