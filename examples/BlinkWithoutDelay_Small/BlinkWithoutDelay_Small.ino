/* Blink without Delay using SmallSetup
 
 This is a copy of the standard Arduino example BlinkWithoutDelay.
 It is designed to show SmallSetup working. For information on SmallSetup
 visit http://arduino.land/Code/SmallSetup/
 
 For info on BlinkWithoutDelay, open the original unmodified version.
*/
#include <SmallSetup.h>

const int ledPin =  13;      // the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
