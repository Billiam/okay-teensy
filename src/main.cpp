#include <array>
#include <memory>
#include <string>
#include <Bounce2.h>
#include <Metro.h>

#include "synth/synth_gui.h"
#include "keyboard.h"
#include "constant.h"
#include "analog_bouncer.h"
#include "synth/instrument.h"
#include "synth/wave_note.h"
#include "synth/synth.h"
#include "synth/midi_notes.h"

#include "samples/Piano1_samples.h"
#include "samples/Clarinet_samples.h"
#include "samples/Celesta_samples.h"
#include "samples/Trombone_samples.h"

//Record audio peaks
//AudioAnalyzePeak         peak1;
//AudioConnection patchCord90(mixer16, peak1);
//Metro peakLog = Metro(1000);

std::array<AudioSynthWavetable*, OkayConstants::keyCount> tableGenerators {{
  &wavetable1,
  &wavetable2,
  &wavetable3,
  &wavetable4,
  &wavetable5,
  &wavetable6,
  &wavetable7,
  &wavetable8,
  &wavetable9,
  &wavetable10,
  &wavetable11,
  &wavetable12,
  &wavetable13,
  &wavetable14,
  &wavetable15,
  &wavetable16,
  &wavetable17,
  &wavetable18,
  &wavetable19,
  &wavetable20,
  &wavetable21,
  &wavetable22,
  &wavetable23,
  &wavetable24,
  &wavetable25
}};

std::array<std::shared_ptr<WaveNote>, OkayConstants::keyCount> waveGenerators {{
  std::make_shared<WaveNote>(WaveNote(waveform1, envelope1)),
  std::make_shared<WaveNote>(WaveNote(waveform2, envelope2)),
  std::make_shared<WaveNote>(WaveNote(waveform3, envelope3)),
  std::make_shared<WaveNote>(WaveNote(waveform4, envelope4)),
  std::make_shared<WaveNote>(WaveNote(waveform5, envelope5)),
  std::make_shared<WaveNote>(WaveNote(waveform6, envelope6)),
  std::make_shared<WaveNote>(WaveNote(waveform7, envelope7)),
  std::make_shared<WaveNote>(WaveNote(waveform8, envelope8)),
  std::make_shared<WaveNote>(WaveNote(waveform9, envelope9)),
  std::make_shared<WaveNote>(WaveNote(waveform10, envelope10)),
  std::make_shared<WaveNote>(WaveNote(waveform11, envelope11)),
  std::make_shared<WaveNote>(WaveNote(waveform12, envelope12)),
  std::make_shared<WaveNote>(WaveNote(waveform13, envelope13)),
  std::make_shared<WaveNote>(WaveNote(waveform14, envelope14)),
  std::make_shared<WaveNote>(WaveNote(waveform15, envelope15)),
  std::make_shared<WaveNote>(WaveNote(waveform16, envelope16)),
  std::make_shared<WaveNote>(WaveNote(waveform17, envelope17)),
  std::make_shared<WaveNote>(WaveNote(waveform18, envelope18)),
  std::make_shared<WaveNote>(WaveNote(waveform19, envelope19)),
  std::make_shared<WaveNote>(WaveNote(waveform20, envelope20)),
  std::make_shared<WaveNote>(WaveNote(waveform21, envelope21)),
  std::make_shared<WaveNote>(WaveNote(waveform22, envelope22)),
  std::make_shared<WaveNote>(WaveNote(waveform23, envelope23)),
  std::make_shared<WaveNote>(WaveNote(waveform24, envelope24)),
  std::make_shared<WaveNote>(WaveNote(waveform25, envelope25))
}};

#define VOICE_SELECTOR 27
#define OCTAVE_SELECTOR 26
#define VOLUME 25
#define HEADPHONE 24

#define AMP_CONTROL 11

AnalogBouncer instrumentSwitch = AnalogBouncer(25, 8, 395);
AnalogBouncer octaveSwitch = AnalogBouncer(25, 8, 395);

std::array<std::shared_ptr<Instrument>, OkayConstants::instrumentCount> instrumentList {{
  std::make_shared<WaveTableInstrument>(WaveTableInstrument(tableGenerators, Piano1, "piano")),
  std::make_shared<WaveTableInstrument>(WaveTableInstrument(tableGenerators, Clarinet, "clarinet")),
  std::make_shared<WaveTableInstrument>(WaveTableInstrument(tableGenerators, Celesta, "celesta")),
  std::make_shared<WaveTableInstrument>(WaveTableInstrument(tableGenerators, Trombone, "trombone")),
  std::make_shared<WaveformInstrument>(WaveformInstrument(waveGenerators, WAVEFORM_SINE)),
  std::make_shared<WaveformInstrument>(WaveformInstrument(waveGenerators, WAVEFORM_TRIANGLE)),
  std::make_shared<WaveformInstrument>(WaveformInstrument(waveGenerators, WAVEFORM_SQUARE)),
  std::make_shared<WaveformInstrument>(WaveformInstrument(waveGenerators, WAVEFORM_SAWTOOTH)),
}};

std::array<uint8_t, OkayConstants::keyCount> keyPins {{
  33, 34, 35, 36, 37, 38, 39, 40, 41, 14, 16, 17, 22,
  32, 31, 30, 29, 0, 9, 28, 5, 4, 3, 2, 1
}};

Synth synth = Synth(instrumentList);
Keyboard keyboard = Keyboard(keyPins, synth);

Bounce2::Button debugBounce = Bounce2::Button();
Metro throttledLog = Metro(200);

void setup() {
  // Amp shutdown on launch
  // pinMode(AMP_CONTROL, OUTPUT);
  // digitalWrite(AMP_CONTROL, LOW);

  Serial.begin(9600);
  AudioMemory(30);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.3);
  sgtl5000_1.lineOutLevel(20);
  delay(100);

  keyboard.begin();

  for (uint8_t pin : keyPins) {
    digital.pinMode(pin, INPUT_PULLUP, RISING);
  }


  // debugBounce.setPressedState(LOW);
  // debugBounce.attach(40, INPUT_PULLUP);
  // debugBounce.interval(25);

  instrumentSwitch.attach(VOICE_SELECTOR);
  octaveSwitch.attach(OCTAVE_SELECTOR);
  synth.setOctave(4);
  
  pinMode(VOLUME, INPUT_PULLDOWN);

  // No effect
  // sgtl5000_1.audioPreProcessorEnable();
  // sgtl5000_1.autoVolumeControl(1,1,0,-36,0.5,0.75);

  // enable amplifier
  // digitalWrite(AMP_CONTROL, HIGH);
}

uint16_t lastMemory = 0;

void loop() {
  uint32_t time = millis();

  instrumentSwitch.update(time);
  if (instrumentSwitch.changed()) {
    synth.setInstrument(instrumentSwitch.getValue());
  }
  // octaveSwitch.update(time);
  // if (octaveSwitch.changed()) {
  //   synth.setOctave(octaveSwitch.getValue());
  // }
  volume_control.gain(0, (1024 - analogRead(VOLUME)) / 1024.0);

  
  
  // debugBounce.update();
  // if (debugBounce.pressed()) {
  //   sgtl5000_1.autoVolumeEnable();
  //   Serial.println("Enabling auto volume");
  // } else if (debugBounce.released()) {
  //   Serial.println("Disabling auto volume");
  //   sgtl5000_1.autoVolumeDisable();
  // }

  keyboard.update(time);
  // debug audio memory usage
//  uint16_t maxMemory = AudioMemoryUsageMax();
//  if (maxMemory != lastMemory) {
//    Serial.print("Audio mem used: ");
//    Serial.println(maxMemory);
//    lastMemory = maxMemory;
//  }

//  if (peakLog.check()) {
//    Serial.print("max volume: ");
//    Serial.println(peak1.read());
//  }
}
