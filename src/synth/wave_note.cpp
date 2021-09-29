#include "wave_note.h"

 WaveNote::WaveNote(AudioSynthWaveform waveform, AudioEffectEnvelope envelope)
 {
   this->_waveform = waveform;
   this->_envelope = envelope;
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