#ifndef AnalogBouncer_h_
#define AnalogBouncer_h_

#include <cstdint>
#include "debounce_int.h"

class AnalogBouncer
{
  public:
    AnalogBouncer(int delay, int positions, int startReading);
    void update(uint32_t time);
    void attach(int pin);
    void detach();
    bool changed();
    int getValue();

  private:
    bool _ready;
    int _pin;
    int _delay;
    int _floor;
    int _divisionSize;
    DebounceInt _debouncer;
};

#endif
