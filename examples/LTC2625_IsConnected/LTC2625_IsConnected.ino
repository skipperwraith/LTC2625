#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;  // default 0x10

void setup() {
  Serial.begin(115200);
  Wire.begin();
  //Wire.setClock(400000); // optional, device supports up to 400 kHz

  Serial.println(F("LTC2625: begin / isConnected / getAddress"));

  if (!dac.isConnected()) {
    Serial.println(F("DAC not reachable!"));
    while (1) {}
  }

  // Initialize with 0x000 (zero-scale).
  // Library: write ALL + update; if 0x000, it powers down ALL for lowest output.
  if (!dac.begin(0x000)) {
    Serial.println(F("begin() failed"));
    while (1) {}
  }

  Serial.print(F("DAC I2C-Adresse: 0x"));
  Serial.println(dac.getAddress(), HEX);
}

void loop() {
  // nothing
}