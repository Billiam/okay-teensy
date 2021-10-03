#ifndef Synth_h_
#define Synth_h_

#include <array>
#include "constant.h"
#include "instrument.h"

class Synth
{
  public:
    explicit Synth(std::array<std::shared_ptr<Instrument>, OkayConstants::instrumentCount> &instrumentList);

    void setInstrument(unsigned char instrument);
    void setOctave(unsigned char octave);
    void play(unsigned short note);
    void stop(unsigned short note);
    Instrument& instrument();
private:
    std::array<std::shared_ptr<Instrument>, OkayConstants::instrumentCount> &_instrumentList;
    unsigned char _instrumentNum;
    unsigned char _octave;
};
#endif