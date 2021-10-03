#include <array>

#include "constant.h"
#include "synth.h"

Synth::Synth(std::array<std::shared_ptr<Instrument>, OkayConstants::instrumentCount> &instrumentList)
  : _instrumentList(instrumentList)
{
  this->_instrumentNum = 0;
  this->_octave = 0;
  this->setInstrument(0);
}

Instrument& Synth::instrument()
{
  return *(_instrumentList[_instrumentNum]);
}

void Synth::setInstrument(unsigned char instrument)
{
  this->instrument().deactivate();
  _instrumentNum = instrument;

  Instrument& activeInstrument = this->instrument();
  activeInstrument.setOctave(_octave);
  activeInstrument.activate();

  Serial.print("Instrument set to: ");
  Serial.println(activeInstrument.getName());
}

void Synth::setOctave(unsigned char octave)
{
  _octave = octave;
  this->instrument().setOctave(octave);
}

void Synth::play(unsigned short note)
{
  this->instrument().play(note);
}
void Synth::stop(unsigned short note)
{
  this->instrument().stop(note);
}