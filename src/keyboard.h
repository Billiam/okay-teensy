#ifndef keyboard_h_
#define keyboard_h_

class Keyboard
{
  public:
    Keyboard(unsigned uint8_t pins[], Synth syth);
    void update(int time);
  private:
    //uint8_t _pins;
    Button buttons;
    Synth synth;
};

#endif