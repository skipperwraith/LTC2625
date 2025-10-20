#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  //Wire.setClock(400000); // optional, device supports up to 400 kHz
  dac.begin(0x000);

  // Prepare channel C (index 2) to ~1/4 FSR (0x400)...
  dac.write(LTC2625_DAC_C, 0x400);
  // ...and take effect now:
  dac.update(LTC2625_DAC_C);

}

void loop() {}