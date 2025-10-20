#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  dac.begin(0x000);

  // Set A and B to mid-scale (active)
  dac.write_n_update(LTC2625_DAC_A, 0x800);
  dac.write_n_update(LTC2625_DAC_B, 0x800);

  delay(500);

  // Power down channel A
  dac.power_down(LTC2625_DAC_A);

  delay(500);

  // Power down ALL
}

void loop() {}