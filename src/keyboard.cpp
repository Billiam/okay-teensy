#include "keyboard.h"
#include <Snooze.h>

Keyboard::Keyboard(std::array<uint8_t, OkayConstants::keyCount> &pins, Synth &synth)
: _pins(pins), _synth(synth) {}

void Keyboard::begin()
{
  for (size_t i = 0; i < _pins.size(); ++i) {
    _buttons[i].attach(_pins[i], INPUT_PULLUP);
    _buttons[i].interval(5);
  }
}

void Keyboard::update(uint32_t time)
{
  for (size_t i = 0; i < _buttons.size(); ++i) {
    _buttons[i].update();
    if (_buttons[i].fell()) {
      _synth.play(i);
    } else if (_buttons[i].rose()) {
      _synth.stop(i);
    }
  }
}