
#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

class PushButton
{
  public: 
    PushButton(int pin);    // instantiator
    void begin(int mode=INPUT_PULLUP);  // sets pinMode 
    int read();       // waits for debounce delay then reads
    int changed();    // reads, returns changed state 
    bool pressed();   // reads, returns pressed state 
    bool released();  // reads, returns release state 
    // sets debounce delay in ms:
    void setDebounce(int debounce);
  private:
    int _pin;       // I/O pin of this instance
    int _debounce;  // debounce delay in ms
    int _state;     // last saved state of the button 
    int _mode;      // pinMode of the button 

    // what constitutes pressed and released.
    // changes depending on the pinMode:
    int _pressedState;
    int _releasedState;
    
    bool _changed;   // if the button has changed
};

#endif
