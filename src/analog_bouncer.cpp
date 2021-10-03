#include <cstdint>
#include <Arduino.h>
#include "analog_bouncer.h"

AnalogBouncer::AnalogBouncer(int delay, int positions, int startReading)
{
  this->_ready = false;

  int range = 1024 - startReading;
  _divisionSize = range / (positions - 1);
  this->_floor = startReading - _divisionSize/2;

  this->_debouncer = DebounceInt(delay);
}

void AnalogBouncer::attach(int pin)
{
  _pin = pin;
  pinMode(pin, INPUT_PULLDOWN);
  _ready = true;
}

void AnalogBouncer::detach()
{
  _ready = false;
}

void AnalogBouncer::update(uint32_t time)
{
  if (!_ready) return;

  int rawReading = analogRead(_pin);
  int mappedValue = (rawReading - _floor) / _divisionSize;

  _debouncer.setValue(mappedValue);
  _debouncer.update(time);
}

bool AnalogBouncer::changed()
{
  return _debouncer.changed();
}

int AnalogBouncer::getValue()
{
  return _debouncer.getValue();
}