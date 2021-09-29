
#include "instrument.h"
#include <Audio.h>
#include "midi_notes.h"
#include "wave_note.h"

// Instrument::Instrument() {};
void Instrument::activate() {};
void Instrument::deactivate() {};
// void Instrument::play(unsigned char note) {};
// void Instrument::stop(unsigned char note) {};
void Instrument::setOctave(unsigned char octave) {
  this->_octave = octave;
}

WaveTableInstrument::WaveTableInstrument(
  AudioSynthWavetable* wavetables,
  std::size_t tableSize,
  const AudioSynthWavetable::instrument_data& instrument,
  unsigned char octave
)
{
  this->_generators = wavetables;
  this->_generatorSize = tableSize;
  this->_instrument = &instrument;
  this->_octave = octave;
}

void WaveTableInstrument::play(unsigned char note)
{
  _generators[note].playFrequency(midiNotes[note + _octave]);
}

void WaveTableInstrument::stop(unsigned char note)
{
  _generators[note].stop();
}

void WaveTableInstrument::activate()
{
  for (std::size_t i=0; i<_generatorSize; i++) {
    _generators[i].setInstrument(*_instrument);
  }
}

WaveformInstrument::WaveformInstrument(
  WaveNote* waves,
  std::size_t tableSize,
  short wave,
  unsigned char octave
)
{
  this->_generators = waves;
  this->_generatorSize = tableSize;
  this->_wave = wave;
  this->_octave = octave;
}

void WaveformInstrument::play(unsigned char note)
{
  _generators[note].play();
}

void WaveformInstrument::stop(unsigned char note)
{
  _generators[note].stop();
}

void WaveformInstrument::activate()
{
  for (std::size_t i=0; i<_generatorSize; i++) {
    _generators[i].setWave(_wave);
  }
}