#ifndef HDMI_H
#define HDMI_H

#include <Arduino.h>

class HDMI {
  public:
    // Constructor to initialize all HDMI TMDS signals
    HDMI(uint8_t TMDS_Data2_Shield, uint8_t TMDS_Data2_Plus, uint8_t TMDS_Data2_Minus,
         uint8_t TMDS_Data1_Shield, uint8_t TMDS_Data1_Plus, uint8_t TMDS_Data1_Minus,
         uint8_t TMDS_Data0_Shield, uint8_t TMDS_Data0_Plus, uint8_t TMDS_Data0_Minus,
         uint8_t TMDS_Clock_Shield, uint8_t TMDS_Clock_Plus, uint8_t TMDS_Clock_Minus);

    // Initialize HDMI interface
    void begin();

    // Send pixel data
    void sendPixel(uint8_t red, uint8_t green, uint8_t blue);

    // Send sync signals (Vertical and Horizontal)
    void sendSync(bool vsync, bool hsync);

  private:
    // Pin variables for TMDS channels and clock signals
    uint8_t _TMDS_Data2_Shield, _TMDS_Data2_Plus, _TMDS_Data2_Minus;
    uint8_t _TMDS_Data1_Shield, _TMDS_Data1_Plus, _TMDS_Data1_Minus;
    uint8_t _TMDS_Data0_Shield, _TMDS_Data0_Plus, _TMDS_Data0_Minus;
    uint8_t _TMDS_Clock_Shield, _TMDS_Clock_Plus, _TMDS_Clock_Minus;

    // Internal functions to encode pixel data
    void encodeTMDS(uint8_t channel, uint8_t data);
};

#endif