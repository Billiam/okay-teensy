#include <Bounce.h>
#include "synth/instrument.h"
#include "synth/wave_note.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=105,240
AudioSynthWaveform       waveform2;      //xy=106,285
AudioSynthWavetable      wavetable1;     //xy=106,386.0000057220459
AudioSynthWaveform       waveform3;      //xy=108,327
AudioEffectEnvelope      envelope2;      //xy=261,285
AudioEffectEnvelope      envelope1;      //xy=262,244
AudioEffectEnvelope      envelope3;      //xy=262,324
AudioMixer4              mixer1;         //xy=467,298
AudioOutputI2S           i2s1;           //xy=641,310
AudioConnection          patchCord1(waveform1, envelope1);
AudioConnection          patchCord2(waveform2, envelope2);
AudioConnection          patchCord3(wavetable1, 0, mixer1, 3);
AudioConnection          patchCord4(waveform3, envelope3);
AudioConnection          patchCord5(envelope2, 0, mixer1, 1);
AudioConnection          patchCord6(envelope1, 0, mixer1, 0);
AudioConnection          patchCord7(envelope3, 0, mixer1, 2);
AudioConnection          patchCord8(mixer1, 0, i2s1, 0);
AudioConnection          patchCord9(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=227,536
// GUItool: end automatically generated code

#include "samples/Piano1_samples.h"
#include "samples/Piano2_samples.h"
#include "samples/Clarinet_samples.h"
#include "samples/Celesta_samples.h"

#include "synth/midi_notes.h"
#include "debounce_int.h"

const unsigned short keyCount = 24;
const unsigned short instrumentCount = 8;
const uint8_t keyPins[keyCount] = {
  0, 1, 2, 3, 4, 5, 9, 24, 25, 26, 27, 28, 29, 30, 31, 32,
  22, 17, 16, 14, 37, 36, 35, 34
};

AudioSynthWavetable tableGenerators[keyCount] = {
  wavetable1
};

WaveNote *waveGenerators[keyCount] = {
  new WaveNote(waveform1, envelope1),
  new WaveNote(waveform2, envelope2),
  new WaveNote(waveform3, envelope3)
};

unsigned char octave = 0;

WaveTableInstrument *piano = new WaveTableInstrument(tableGenerators, keyCount, Piano1, octave);
WaveTableInstrument *clarinet = new WaveTableInstrument(tableGenerators, keyCount, Clarinet, octave);
WaveTableInstrument *celesta = new WaveTableInstrument(tableGenerators, keyCount, Celesta, octave);

WaveformInstrument *sine = new WaveformInstrument(*waveGenerators, keyCount, WAVEFORM_SINE, octave);
WaveformInstrument *triangle = new WaveformInstrument(*waveGenerators, keyCount, WAVEFORM_TRIANGLE, octave);
WaveformInstrument *square = new WaveformInstrument(*waveGenerators, keyCount, WAVEFORM_SQUARE, octave);
WaveformInstrument *saw = new WaveformInstrument(*waveGenerators, keyCount, WAVEFORM_SAWTOOTH, octave);

Instrument *instrumentList[instrumentCount] = {
  piano,
  clarinet,
  celesta,
  sine,
  triangle,
  square,
  saw
};
// need to track active instrument, maybe with pointer, so that it can be played

#define P1 33
#define P2 34
#define P3 35

#define VOICE_SELECTOR 27

unsigned int voiceValue;
unsigned int lastVoiceValue;

Bounce button1 = Bounce(P1, 15);
Bounce button2 = Bounce(P2, 15);
Bounce button3 = Bounce(P3, 15);

DebounceInt instrumentSwitch = DebounceInt(25);

long voiceDebounceTime = 0;
unsigned int voiceDebounceValue = 0;

void setup() {
  AudioMemory(10);
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);
  Serial.begin(9600);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.3);
  sgtl5000_1.lineOutLevel(6);


  waveform1.begin(WAVEFORM_SQUARE);
  waveform2.begin(WAVEFORM_SQUARE);
  waveform3.begin(WAVEFORM_SQUARE);

  delay(100);
  button1.update();
  button2.update();
  button3.update();

  wavetable1.setInstrument(Celesta);
  // wavetable1.setInstrument(Piano1);
  // wavetable1.setInstrument(Clarinet);
  waveform1.frequency(440);
  waveform2.frequency(554.37);
  waveform3.frequency(659.25);

  waveform1.amplitude(1);
  waveform2.amplitude(0.9);
  waveform3.amplitude(0.9);
}




void loop() {
  int _time = millis();
  instrumentSwitch.update(_time);

  // TODO:

  // keyboard.update();

  button1.update();
  button2.update();
  button3.update();


  if (button1.risingEdge()) {
    envelope1.noteOff();
    // string1.noteOff(0.7);
  }
  if (button1.fallingEdge()) {
    envelope1.noteOn();
    // string1.noteOn(440, 0.5);
  }

  if (button2.risingEdge()) {
    envelope2.noteOff();
    // string2.noteOff(0.7);
  }
  if (button2.fallingEdge()) {
    envelope2.noteOn();
    // string2.noteOn(554.37, 0.5);
  }

  if (button3.risingEdge()) {
    // envelope3.noteOff();
    // string3.noteOff(0.7);
    wavetable1.stop();
  }
  if (button3.fallingEdge()) {
    // envelope3.noteOn();
    // string3.noteOn(659.25, 0.5);
    wavetable1.playFrequency(midiNotes[69]);
  }

  //TODO: Make debouncer
  int rawReading = analogRead(VOICE_SELECTOR);
  if (rawReading > 300) {
    int voiceReading = (rawReading - 350) / 88;
    instrumentSwitch.setValue(voiceReading);

    if (instrumentSwitch.changed()) {
      instrumentList[instrumentSwitch.getValue()]->activate();
    }
    // if (voiceReading != lastVoiceValue) {
    //   lastVoiceValue = voiceReading;
    //   voiceDebounceTime = millis();
    // }

    // if (millis() - voiceDebounceTime > 50 && lastVoiceValue != voiceValue) {
    //   voiceValue = lastVoiceValue;
    //   if (voiceValue > 1024) {
    //     Serial.print("Issue: ");
    //     Serial.println(analogRead(VOICE_SELECTOR));
    //   }
    //   Serial.println(voiceValue);
    // }
  }

}
