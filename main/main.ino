	
#include "Arduino_SensorKit.h"
 
void setup() {
  Oled.begin();
  Oled.setFlipMode(true); // Sets the rotation of the screen
}
 
void loop() {
  int random_value = random(0, 1000);   //read value from A0
 
  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 33);    // Set the Coordinates 
  Oled.print("Analog Value:");   
  Oled.print(random_value); // Print the Values  
  Oled.refreshDisplay();    // Update the Display 
  //delay(1000);
}