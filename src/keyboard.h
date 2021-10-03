#ifndef Keyboard_h_
#define Keyboard_h_

#include <array>
#include <cstdint>
#include <Bounce2.h>
#include "synth/synth.h"
#include "constant.h"

class Keyboard
{
  public:
    Keyboard(std::array<uint8_t, OkayConstants::keyCount> &pins,  Synth &synth);
    void update(uint32_t time);
    void begin();
  private:
    std::array<uint8_t, OkayConstants::keyCount> &_pins;
    std::array<Bounce2::Button, OkayConstants::keyCount> _buttons;
    Synth &_synth;
};

#endif