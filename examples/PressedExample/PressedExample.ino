/*
  Increments a counter each time the button is pressed

  circuit: pushbutton on pin 2, connected to ground

  created 29 Mar 2020
  by Tom Igoe
*/
#include <PushButton.h>

PushButton myButton(2);
int pressCounter = 0;

void setup() {
  Serial.begin(9600);
  // button is wired to ground, so activate internal pullup:
  myButton.begin(INPUT_PULLUP);
  // set a debounce time of 6ms:
  myButton.setDebounce(6);
}

void loop() {
  // if button changes:
  if (myButton.pressed()) {
    // increment counter:
    pressCounter++;
    // print the count:
    Serial.print("pressed ");
    Serial.print(pressCounter);
    Serial.println(" times");
  }
}
