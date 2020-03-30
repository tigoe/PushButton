/*
  Reads when the button changes, uses the state of the button
  to set the built-in LED.

  circuit: pushbutton on pin 2, connected to ground

  created 29 Mar 2020
  by Tom Igoe
*/
#include <PushButton.h>

PushButton myButton(2);

void setup() {
  // button is wired to ground, so activate internal pullup:
  myButton.begin(INPUT_PULLUP);
  // set a debounce time of 6ms:
  myButton.setDebounce(6);
  // initialize built-in LED:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // if button changes:
  if (myButton.changed()) {
    // read its state into a variable:
    int ledState = myButton.read();
    // use the variable to set the LED state:
    digitalWrite(LED_BUILTIN, ledState);
  }
}
