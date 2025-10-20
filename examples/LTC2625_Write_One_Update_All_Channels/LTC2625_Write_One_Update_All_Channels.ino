#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  dac.begin(0x000);

  // Preload A..D (input registers only)
  dac.write(LTC2625_DAC_A, 0x111);
  dac.write(LTC2625_DAC_B, 0x333);
  dac.write(LTC2625_DAC_C, 0x555);
  dac.write(LTC2625_DAC_D, 0x777);

  // Trigger writing to one channel and enable ALL:
  // The value for D is applied; other channels take the previously written values.
  dac.write_one_n_update_all(LTC2625_DAC_D, 0x888);
}

void loop() {}