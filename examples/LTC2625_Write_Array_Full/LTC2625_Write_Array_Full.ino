#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  dac.begin(0x000);

  // Eight values for A..H:
  uint16_t vals[8] = {
    0x010,  // A
    0x120,  // B
    0x230,  // C
    0x340,  // D
    0x450,  // E
    0x560,  // F
    0x670,  // G
    0x780   // H
  };

  // Writes input registers per channel (no update yet):
  dac.write_array(vals);

  // Now update all outputs simultaneously:
  dac.update(LTC2625_DAC_ALL);
}

void loop() {}