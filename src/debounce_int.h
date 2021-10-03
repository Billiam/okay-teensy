#ifndef DebounceInt_h_
#define DebounceInt_h_

#include <cstdint>

#include <Arduino.h>
class DebounceInt
{
  public:
    explicit DebounceInt(int delay = 25);

    void setValue(int val);
    void update(uint32_t time);
    bool changed();
    int getValue();

  private:
    bool _changed;
    int _delay;
    int _time;
    int _lastTime;
    int _lastValue;
    int _value;
};
#endif