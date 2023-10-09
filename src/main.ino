/**
 *  This Code turns your ESP32 into a Bluetooth LE mouse that once paired with
 *  your mobile phone it will skip to the next Instagram Reels every 10 seconds.
 */
#include <BleMouse.h>

BleMouse bleMouse;
const int PushButton = 0;  // onboard Boot Button
const int LEDPin = 2;
int lastButtonState;
int currentButtonState;

void setup() {
  bleMouse.begin();
  pinMode(PushButton, INPUT);
  pinMode(LEDPin, OUTPUT);
  currentButtonState = digitalRead(PushButton);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(PushButton);
  if(lastButtonState == LOW && currentButtonState == HIGH) { 
    scroll();
    delay(1000); 
    digitalWrite(LEDPin, LOW);
  }
  else { 
    scroll();
    delay(10000); 
    digitalWrite(LEDPin, HIGH);
  }
}
void scroll(){
 if(bleMouse.isConnected()) {
      bleMouse.move(0,0,6);
      bleMouse.move(0,0,8);
      bleMouse.move(0,0,10);
      bleMouse.move(0,0,8);
      bleMouse.move(0,0,6);  
  }
}