/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);

    gainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    gainSlider.setRange(0.f, 1.f, 0.0001f); // TODO: Make log
	gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20, 20);
	gainSlider.setPopupDisplayEnabled(true, true, this);
    gainSlider.setTextValueSuffix("Gain");
    gainSlider.setValue(1.f);

	panSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	panSlider.setRange(-180.f, 180.f, 0.1f); // TODO: Make log
	panSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20, 20);
	panSlider.setPopupDisplayEnabled(true, true, this);
	panSlider.setTextValueSuffix("Pan (x)");
	panSlider.setValue(0.f);

	tiltSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	tiltSlider.setRange(-180.f, 180.f, 0.1f); // TODO: Make log
	tiltSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20, 20);
	tiltSlider.setPopupDisplayEnabled(true, true, this);
	tiltSlider.setTextValueSuffix("Tilt (y)");
	tiltSlider.setValue(0.f);

	yawSlider.setSliderStyle(juce::Slider::LinearBarVertical);
	yawSlider.setRange(-180.f, 180.f, 0.1f); // TODO: Make log
	yawSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20, 20);
	yawSlider.setPopupDisplayEnabled(true, true, this);
	yawSlider.setTextValueSuffix("Yaw (z)");
	yawSlider.setValue(0.f);

	addAndMakeVisible(gainSlider);
	addAndMakeVisible(panSlider);
	addAndMakeVisible(tiltSlider);
	addAndMakeVisible(yawSlider);

	gainSlider.addListener(this);
	panSlider.addListener(this);
	tiltSlider.addListener(this);
	yawSlider.addListener(this);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Ambisonic Utility", getLocalBounds(), juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	gainSlider.setBounds(40,  30, 40, getHeight() - 60);
	 panSlider.setBounds(140, 30, 40, getHeight() - 60);
    tiltSlider.setBounds(240, 30, 40, getHeight() - 60);
	 yawSlider.setBounds(340, 30, 40, getHeight() - 60);
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
	if (slider == &gainSlider)
	{
		audioProcessor.setGain(slider->getValue());
	}
	if (slider == &panSlider)
	{
		audioProcessor.setPan(slider->getValue());
	}
	if (slider == &tiltSlider)
	{
		audioProcessor.setTilt(slider->getValue());
	}
	if (slider == &yawSlider)
	{
		audioProcessor.setYaw(slider->getValue());
	}
	
}
