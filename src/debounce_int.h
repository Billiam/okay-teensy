#ifndef DebounceInt_h_
#define DebounceInt_h_

class DebounceInt
{
  public:
    DebounceInt(int delay = 25);

    void setValue(int val);
    void update(int time);

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