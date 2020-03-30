/*
  Reads when the button changes, prints whether it's pressed
  or released.

  NOTE: this is the way to get both press and release. Using
  .pressed() and .released sequentially in the same loop
  will not produce reliable results.

  circuit: pushbutton on pin 2, connected to ground

  created 29 Mar 2020
  by Tom Igoe
*/
#include <PushButton.h>

PushButton myButton(2);

void setup() {
  Serial.begin(9600);
  // button is wired to ground, so activate internal pullup:
  myButton.begin(INPUT_PULLUP);
  // set a debounce time of 6ms:
  myButton.setDebounce(6);
}

void loop() {
  // check for change:
  if (myButton.changed()) {
    // read current state:
    int buttonState = myButton.read();
    // print pressed or released. Change LOW to HIGH
    // if you are using pinMode INPUT instead of INPUT_PULLUP: 
    if (buttonState == LOW) {
      Serial.println("pressed");
    } else {
      Serial.println("released");  
    }
  }
}
