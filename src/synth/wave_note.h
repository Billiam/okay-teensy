#ifndef WaveNote_h_
#define WaveNote_h_

#include <Audio.h>

class WaveNote
{
  public:
    WaveNote(AudioSynthWaveform &waveform, AudioEffectEnvelope &envelope);
    void play();
    void stop();
    void setWave(short wave);
    void setFrequency(float freq);
    bool playing();
  private:
    AudioEffectEnvelope &_envelope;
    AudioSynthWaveform &_waveform;
};

#endif