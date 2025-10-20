#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  dac.begin(0x000);

  // Immediate update of individual channels:
  dac.write_n_update(LTC2625_DAC_A, 0x123);
  dac.write_n_update(LTC2625_DAC_H, 0xABC);
}

void loop() {}