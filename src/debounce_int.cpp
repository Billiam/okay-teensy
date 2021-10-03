#include <stdint.h>
#include "debounce_int.h"

DebounceInt::DebounceInt(int delay)
{
  this->_changed = false;

  this->_value = 0;
  this->_lastValue = 0;
  this->_time = 0;
  this->_lastTime = 0;

  this->_delay = delay;
}

void DebounceInt::update(uint32_t time)
{
  this->_time = time;

  if (_time - _lastTime > _delay && _lastValue != _value) {
    _value = _lastValue;
    _changed = true;
  } else {
    _changed = false;
  }
}

void DebounceInt::setValue(int val)
{
  if (val >= 0) {
    if (val != _lastValue) {
      _lastValue = val;
      _lastTime = _time;
    }
  } else {
    _lastTime = _time;
  }
}

bool DebounceInt::changed()
{
  return _changed;
}

int DebounceInt::getValue()
{
  return _value;
}