/**
 *  This Code turns your ESP32 into a Bluetooth LE mouse that once paired with
 *  your mobile phone it will skip to the next Instagram Reels every 10 seconds.
 */
#include <BleMouse.h>

BleMouse bleMouse;

void setup() {
  bleMouse.begin();
}

void loop() {
    scroll();
    delay(10000); 
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