#include "debounce_int.h"

DebounceInt::DebounceInt(int delay)
{
  this->_changed = false;
  this->_delay = delay;
}

void DebounceInt::update(int time) 
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
  if (val != _lastValue) {
    _lastValue = val;
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