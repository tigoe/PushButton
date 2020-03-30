#include "Arduino.h"
#include "PushButton.h"

//  instantiate, set default values for internal variables:
PushButton::PushButton(int pinNumber)
{
  _pin = pinNumber;
  _debounce = 4;
  _state = LOW;
  _mode = INPUT_PULLUP;
  _pressedState = LOW;
  _releasedState = HIGH;
  _changed = false;
}

// set pinMode and pressed and released states:
void PushButton::begin(int mode)
{
  _mode = mode;
  pinMode(_pin, _mode);
  if (mode == INPUT_PULLUP)
  {
    _pressedState = LOW;
    _releasedState = HIGH;
  }
  else
  {
    _pressedState = HIGH;
    _releasedState = LOW;
  }
}

// read and  set changed state:
int PushButton::read()
{
  delay(_debounce);             // debounce
  int temp = digitalRead(_pin); // read
  _changed = (_state != temp);
  if (_changed)
  {
    _state = temp;
  }
  return _state;
}

// read and return changed state:
int PushButton::changed()
{
  read();
  return _changed;
}

// read and return pressed state:
bool PushButton::pressed()
{
  return ((read() == _pressedState) && _changed);
}

// read and return released state:
bool PushButton::released()
{
  return ((read() == _releasedState) && _changed);
}

// set debounce delay in ms:
void PushButton::setDebounce(int debounce)
{
  _debounce = debounce;
}