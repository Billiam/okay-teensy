#ifndef Instrument_h_
#define Instrument_h_

#include <Audio.h>
#include "wave_note.h"

class Instrument
{
  public:
    // Instrument();

    virtual void play(unsigned char note);
    virtual void stop(unsigned char note);
    void setOctave(unsigned char octave);
    void activate();
    void deactivate();
  protected:
    unsigned char _octave;
};

class WaveTableInstrument: public Instrument
{
  public:
    WaveTableInstrument(
      AudioSynthWavetable* wavetables,
      std::size_t tableSize,
      const AudioSynthWavetable::instrument_data& instrument,
      unsigned char octave
    );

    void play(unsigned char note);
    void stop(unsigned char note);
//    void setOctave(unsigned char octave);
    void activate();
    // void deactivate();
  private:
    AudioSynthWavetable* _generators;
    std::size_t _generatorSize;
    const AudioSynthWavetable::instrument_data* _instrument;
    unsigned char octave;
};

class WaveformInstrument: public Instrument
{
  public:
    WaveformInstrument(
      WaveNote* waves,
      std::size_t tableSize,
      short wave,
      unsigned char octave
    );
    void play(unsigned char note);
    void stop(unsigned char note);
//    void setOctave(unsigned char octave);
    void activate();
    // void deactivate();
  private:
    WaveNote* _generators;
    std::size_t _generatorSize;
    short _wave;
    unsigned char octave;
};
#endif