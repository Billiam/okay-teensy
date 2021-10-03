#include "instrument.h"
#include <Audio.h>
#include "midi_notes.h"
#include "constant.h"

void Instrument::activate() {};
void Instrument::deactivate() {};
void Instrument::play(unsigned char note) {};
void Instrument::stop(unsigned char note) {};
float Instrument::noteFrequency(unsigned char note) { return 0.0; };

String Instrument::getName() { return "Base instrument"; };

void Instrument::setOctave(unsigned char octave) {
  this->_octave = octave;
}

WaveTableInstrument::WaveTableInstrument(
  std::array<AudioSynthWavetable*, OkayConstants::keyCount> &wavetables,
  const AudioSynthWavetable::instrument_data &instrument,
  String name
) :  _generators(wavetables), _instrument(instrument), _name(name)
{
  _octave = 0;
}

void WaveTableInstrument::play(unsigned char note)
{
  _generators[note]->playFrequency(this->noteFrequency(note));
}

void WaveTableInstrument::stop(unsigned char note)
{
  AudioSynthWavetable::envelopeStateEnum state = _generators[note]->getEnvState();

  if (state != AudioSynthWavetable::STATE_IDLE && state != AudioSynthWavetable::STATE_RELEASE) {
    _generators[note]->stop();
  }
}

void WaveTableInstrument::activate()
{
  for (size_t i = 0; i < _generators.size(); ++i) {
    _generators[i]->amplitude(0.8);
    _generators[i]->setInstrument(_instrument);
  }
}
void WaveTableInstrument::deactivate()
{
  for (size_t i = 0; i < _generators.size(); ++i) {
    this->stop(i);
  }
}

void WaveTableInstrument::setOctave(unsigned char octave)
{
  this->_octave = octave;

  for (size_t i = 0; i < _generators.size(); ++i) {
    if (_generators[i]->isPlaying()) {
      _generators[i]->setFrequency(this->noteFrequency(i));
    }
    _generators[i]->setInstrument(_instrument);
  }
}
float WaveTableInstrument::noteFrequency(unsigned char note)
{
  return midiNotes[note + _octave * 12];
}
String WaveTableInstrument::getName() {
  return _name;
}

/*
 * Waveform instrument
 */


WaveformInstrument::WaveformInstrument(
  std::array<std::shared_ptr<WaveNote>, OkayConstants::keyCount>& waves,
  short wave
) : _generators(waves), _wave(wave)
{
  this->_octave = 0;
}

void WaveformInstrument::play(unsigned char note)
{
  _generators[note]->play();
}

void WaveformInstrument::stop(unsigned char note)
{
  if (_generators[note]->playing()) {
    _generators[note]->stop();
  }
}

void WaveformInstrument::activate()
{
  for (size_t i = 0; i < _generators.size(); ++i) {
    _generators[i]->setWave(_wave);
  }
}

void WaveformInstrument::setOctave(unsigned char octave)
{
  this->_octave = octave;

  Serial.print("Waveform instrument octave: ");
  Serial.println(octave);

  for (size_t i = 0; i < _generators.size(); ++i) {
    _generators[i]->setFrequency(this->noteFrequency(i));
  }
}
float WaveformInstrument::noteFrequency(unsigned char note)
{
  return midiNotes[note + _octave * 12];
}

void WaveformInstrument::deactivate()
{
  for (size_t i = 0; i < _generators.size(); ++i) {
    this->stop(i);
  }
}

String WaveformInstrument::getName() {
  return _wave;
}