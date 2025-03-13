#include <HDMI.h>

// Create an HDMI object with pin assignments for TMDS data and clock channels
HDMI hdmi(2, 3, 4,   // TMDS Data 2 Shield, Data 2+, Data 2-
          5, 6, 7,   // TMDS Data 1 Shield, Data 1+, Data 1-
          8, 9, 10,  // TMDS Data 0 Shield, Data 0+, Data 0-
          11, 12, 13 // TMDS Clock Shield, Clock+, Clock-
         );

void setup() {
  // Initialize the HDMI interface
  hdmi.begin();
}

void loop() {
  // Send some pixels (RGB values)
  hdmi.sendPixel(255, 0, 0);   // Send red pixel