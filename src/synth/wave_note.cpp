#include "wave_note.h"

 WaveNote::WaveNote(AudioSynthWaveform &waveform, AudioEffectEnvelope &envelope)
 :  _envelope(envelope), _waveform(waveform) {
   _waveform.amplitude(0.7);
}

void WaveNote::play()
{
  _envelope.noteOn();
}

void WaveNote::stop()
{
  _envelope.noteOff();
}

void WaveNote::setWave(short wave)
{
  _waveform.begin(wave);
}

void WaveNote::setFrequency(float freq)
{
  this->_waveform.frequency(freq);
}

bool WaveNote::playing()
{
  return _envelope.isActive();
}