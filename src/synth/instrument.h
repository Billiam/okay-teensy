#ifndef Instrument_h_
#define Instrument_h_

#include <Audio.h>
#include <array>
#include <memory>
#include <string>
#include "constant.h"
#include "wave_note.h"

class Instrument
{
  public:
    virtual void play(unsigned char note);
    virtual void stop(unsigned char note);
    virtual void setOctave(unsigned char octave);
    virtual void activate();
    virtual void deactivate();
    virtual String getName();
    virtual float noteFrequency(unsigned char note);
  protected:
    unsigned char _octave;
};

class WaveTableInstrument: public Instrument
{
  public:
    WaveTableInstrument(
      std::array<AudioSynthWavetable*, OkayConstants::keyCount>& wavetables,
      const AudioSynthWavetable::instrument_data& instrument,
      String name
    );

    void play(unsigned char note) override;
    void stop(unsigned char note) override;
    void setOctave(unsigned char octave) override;
    void activate() override;
    float noteFrequency(unsigned char note) override;
    String getName() override;
    void deactivate() override;
  private:
    std::array<AudioSynthWavetable*, OkayConstants::keyCount>& _generators;
    const AudioSynthWavetable::instrument_data& _instrument;
    unsigned char _octave;
    String _name;
};

class WaveformInstrument: public Instrument
{
  public:
    WaveformInstrument(
      std::array<std::shared_ptr<WaveNote>, OkayConstants::keyCount>& waves,
      short wave
    );
    void play(unsigned char note) override;
    void stop(unsigned char note) override;
    void setOctave(unsigned char octave) override;
    void activate() override;
    float noteFrequency(unsigned char note) override;
    String getName() override;
    void deactivate() override;
  private:
    std::array<std::shared_ptr<WaveNote>, OkayConstants::keyCount>& _generators;
    short _wave;
    unsigned char _octave;
};
#endif